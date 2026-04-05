#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <strings.h>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <sstream>
#include <map>


using namespace std;


map <string , string>  store;
mutex mtx;
void handle_client(int client_fd) {
     char buf[1024];
        while(true) {
            memset(buf , 0 , sizeof(buf));
            int bytes = read(client_fd, buf , sizeof(buf));
            if(bytes <= 0){
                cout<<"Client disconnected!"<<endl;
            break;}
            
            

            string line(buf);
            istringstream iss(line);
            string cmd , key , value ;
            iss >> cmd >> key;
            string response;

            if(cmd == "SET"){
                iss>> value;
                lock_guard<mutex> lock(mtx);
                store[key] = value;
                response = "SET successful";
            } else if(cmd == "GET"){
                lock_guard<mutex> lock(mtx);
                if(store.find(key) != store.end()){
                    response = store[key] + "\n";
                } else {
                    response = "Key not found";
                }
            } else {
                cout<<"Received from client: "<<buf<<endl;
                response = string(buf);
            }
            write(client_fd , response.c_str() , response.size());  ;
        }
        close(client_fd);
        cout<<"client disconnected \n";
}

int main()
{
    int server_fd = socket(AF_INET,SOCK_STREAM,0);
    if(server_fd == -1){
        cerr<<"socket creation failed"<<endl;
        return -1;
    }
    
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8000);
    bind(server_fd,(sockaddr*)&addr , sizeof(addr));

    listen(server_fd, 5);
    cout<<"Server is listening on port 8000..."<<endl;

    while(true) {
        int client_fd = accept(server_fd , nullptr , nullptr);
        if(client_fd == -1){
            cerr<<"accept failed"<<endl;
            continue;}
        cout<<"Client connected!"<<endl;
        thread t(handle_client, client_fd);
        t.detach();
    }
    close(server_fd);
return 0;
}