#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <mutex>
#include <atomic>
using namespace std;
map<string, string> store;
atomic<int> id{0}; // direct initialisation
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
            break;
        }

        string line(buf);
        istringstream full(line);
        string oneline;
        while (getline(full, oneline))
        {
            if (oneline.empty())
            {
                continue;
            }
            istringstream iss(oneline);
            string cmd, key, value;
            iss >> cmd >> key;
            string response;

            if (cmd == "SET")
            {
                iss >> value;
                cout << "[SET] " << key << " = " << value << endl;
                lock_guard<mutex> lock(mtx);
                store[key] = value;
                response = "SET successful\n";
            }
            else if (cmd == "GET")
            {
                lock_guard<mutex> lock(mtx);
                response = (store.find(key) != store.end())
                               ? store[key] + "\n"
                               : "Key not found\n";
            }
            else if (cmd == "NUM")
            {

                response = "Active clients: " + to_string(id) + "\n";
            }
            else
            {
                // Unknown command — echo back raw input
                cout << "[UNKNOWN] Client " << id << " sent: " << oneline << endl;
                response = "Unknown command: " + oneline + "\n";
            }
            write(client_fd, response.c_str(), response.size());
        }
    }
    int curr_id = id.load();
    id--;
    // cout for client id or which is disconnected
    close(client_fd);
}
int main()
{
    // create tcp socket

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1)
    {
        cerr << "\nSocket creation failed\n";
        return -1;
    }

    // immmediate reuse of port after restart
    int opt = 1;

    // socket, level ,option ,&value ,size
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8000);

    bind(server_fd, (sockaddr *)&addr, sizeof(addr));

    listen(server_fd, 5);

    while (true)
    {
        sockaddr_in client_addr;
        socklen_t addrlen = sizeof(client_addr);
        int client_fd = accept(server_fd, (sockaddr *)&client_addr, &addrlen); // ip and port no needed so nullptr
        if (client_fd == -1)
        {
            cerr << "\nAccept failed\n";
            continue;
        }
        id++;

        thread t(handle_client, client_fd);
        t.detach();
    }

    return 0;
}