#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
#include <sys/socket.h> // theses error are there because im in windows os , we can run this file directly from wsl terminal then navigating to the
// project folder then g++ server.cpp -o server
//  ./server
// then use nc localhost 8000 in terminal to check set and get

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <sstream>
#include <map>
#include <atomic>

using namespace std;

atomic<int> ID = 0; // means if 2 3 people join simultaneously the value will not be accurate

map<string, string> store;
mutex mtx;
void handle_client(int client_fd)
{
    char buf[1024];
    while (true)
    {
        memset(buf, 0, sizeof(buf));
        int bytes = read(client_fd, buf, sizeof(buf));
        if (bytes <= 0)
        {
            cout << "Client disconnected!" << endl;
            break;
        }

        // parsing not working properly
        // also the client id management should be better

        string line(buf); // converts to c++ string format from raw char
        // istringstream iss(line); // makes it into words separated by spaces
        // string cmd, key, value;
        // iss >> cmd >> key;

        // string line(buf);
        // split by \n and process each line
        istringstream full(line);
        string oneline;
        while (getline(full, oneline))
        {
            if (oneline.empty())
                continue;
            istringstream iss(oneline);
            string cmd, key, value;
            iss >> cmd >> key;
            string response; // to print into server side terminal and if used inside write then prints in
            // client side

            if (cmd == "SET")
            {
                iss >> value;

                response = "Setting " + key + " to " + value + "\n";

                cout << response << "\n";
                cout.flush(); // else it will printed on a delay after click / or we can use cerr it has inbuilt no delay

                lock_guard<mutex> lock(mtx); // locks the store command , as we are using threads .
                // only one should be able to access this at a time

                store[key] = value;
                response = "SET successful \n";
            }
            else if (cmd == "GET")
            {
                lock_guard<mutex> lock(mtx);
                if (store.find(key) != store.end())
                {
                    response = store[key] + "\n";
                }
                else
                {
                    response = "Key not found \n";
                }
            }
            else if (cmd == "NUM")
            {
                lock_guard<mutex> lock(mtx);
                response = "Number of Clients Connected : " + to_string(ID) + "\n";
            }
            else
            {
                cout << "Received from client " << ID << ": " << buf << endl;
                response = string(buf);
            }
            write(client_fd, response.c_str(), response.size());
        }
        ID--;
        close(client_fd);

        cout << "client " << ID << " disconnected \n";
    }
}

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); // afnet  = ipv4 , sock_stream = tcp , 0 = auto select protocol for tcp

    if (server_fd == -1)
    {                                             // socket returns -1 on failed so checking
        cerr << "socket creation failed" << endl; // cerr is cout for errors
        return -1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)); // if we restart server quickly the port is kept by windows for sometime
    // so to reuse it quickly we are using opt to enable , solcocket saying its general level option , reuse address = even if its wait time itll help us bind to our port
    // reuse port enable multiple threads to use the same port
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;                // listens on all network interface
    addr.sin_port = htons(8000);                      // search big endian and small endian , host to network byte genralisation
    bind(server_fd, (sockaddr *)&addr, sizeof(addr)); // binds to port 8000 using socket addr

    listen(server_fd, 5); // 5 is the queue size while one process is going on
    cout << "Server is listening on port 8000..." << endl;

    while (true)
    { // sp that we can accept multiple client instead of waiting
        int client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd == -1)
        {
            cerr << "accept failed" << endl;
            continue;
        }
        ID++;
        cout << "Client " << ID << " connected!" << endl;
        thread t(handle_client, client_fd); // handle client gets called multiple time because of thread
        t.detach();
    }
    close(server_fd);
    return 0;
}