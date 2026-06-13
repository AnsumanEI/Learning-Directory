#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

// Shared state — protected by mutex or atomic
map<string, string> store; // key-value store
mutex mtx;                 // protects 'store' from concurrent thread access
atomic<int> ID{0};         // thread-safe client counter (atomic avoids mutex for single variable)

void handle_client(int client_fd)
{
    char buf[1024];

    while (true)
    {
        memset(buf, 0, sizeof(buf)); // wipe buffer before each read to avoid leftover data

        int bytes = read(client_fd, buf, sizeof(buf));

        // bytes <= 0 means client disconnected or error
        if (bytes <= 0)
        {
            break;
        }

        // Convert raw char buffer to C++ string, then split by newline
        // (client may send multiple commands in one TCP packet)
        string line(buf);
        istringstream full(line);
        string oneline;

        while (getline(full, oneline))
        {
            if (oneline.empty())
                continue;

            // Parse command and key from each line
            istringstream iss(oneline);
            string cmd, key, value;
            iss >> cmd >> key;

            string response;

            if (cmd == "SET")
            {
                iss >> value;

                // Log on server terminal
                cout << "[SET] " << key << " = " << value << endl;

                // Lock store while writing — only one thread at a time
                lock_guard<mutex> lock(mtx);
                store[key] = value;

                response = "SET successful\n";
            }
            else if (cmd == "GET")
            {
                lock_guard<mutex> lock(mtx);
                // Check if key exists before accessing
                response = (store.find(key) != store.end())
                               ? store[key] + "\n"
                               : "Key not found\n";
            }
            else if (cmd == "NUM")
            {
                // No mutex needed — ID is atomic
                response = "Active clients: " + to_string(ID) + "\n";
            }
            else
            {
                // Unknown command — echo back raw input
                cout << "[UNKNOWN] Client " << ID << " sent: " << oneline << endl;
                response = "Unknown command: " + oneline + "\n";
            }

            // Send response back to this client
            write(client_fd, response.c_str(), response.size());
        }
    }

    // ✅ Runs ONCE when client disconnects (outside while loop)
    int this_id = ID.load(); // save which client this was before decrementing
    ID--;
    cout << "Client " << this_id << " disconnected. Active clients: " << ID << endl;
    close(client_fd); // release the socket file descriptor
}

int main()
{
    // Create TCP socket — AF_INET = IPv4, SOCK_STREAM = TCP
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        cerr << "Socket creation failed" << endl;
        return -1;
    }

    // Allow immediate reuse of port after server restart
    // (avoids "Address already in use" error)
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Configure address: IPv4, any network interface, port 8000
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8000); // htons converts port to network byte order (big-endian)

    bind(server_fd, (sockaddr *)&addr, sizeof(addr));

    // Start listening — queue up to 5 pending connections
    listen(server_fd, 5);
    cout << "Server listening on port 8000..." << endl;

    while (true)
    {
        // accept() blocks until a client connects, returns new fd for that client
        int client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd == -1)
        {
            cerr << "Accept failed" << endl;
            continue;
        }

        ID++;
        cout << "Client " << ID << " connected!" << endl;

        // Spawn a new thread per client so server can handle multiple clients simultaneously
        // detach() lets thread run independently — main loop doesn't wait for it
        thread t(handle_client, client_fd);
        t.detach();
    }

    close(server_fd);
    return 0;
}