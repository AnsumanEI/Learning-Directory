#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <atomic>
using namespace std;
atomic<int> id = 0;

void handle_client(int client_fd)
{
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
        socklent_t addrlen = sizeof(client_addr);
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