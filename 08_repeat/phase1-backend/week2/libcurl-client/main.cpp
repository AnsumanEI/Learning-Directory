#include <iostream>
#include <string.h>
#include <curl/curl.h>
using namespace std;
/*
response — the empty string where we'll collect the server's reply
CURL* — a pointer to the "postman" object libcurl creates
curl_easy_init() — creates and returns that postman
size * nmemb = size of one member × number of members = total bytes in this chunk. 

*/

size_t WriteCallback(void * contents , size_t size , size_t nmemb , string* output)
{
    output->append((char*)contents , size * nmemb);
    return size * nmemb;
}

int main()
{
    string response;//collect server reply
    CURL* curl = curl_easy_init();//creates postman and store it in the pointer

    if(!curl)
    {
        cerr<<"Failed to init curl" <<endl;
        return 1;
    }

    curl_easy_setopt(curl , CURLOPT_URL ,"http://127.0.0.1:8000/users");
    curl_easy_setopt(curl , CURLOPT_WRITEFUNCTION ,WriteCallback);
    curl_easy_setopt(curl , CURLOPT_WRITEDATA,&response);
    curl_easy_setopt(curl , CURLOPT_HTTP_VERSION , CURL_HTTP_VERSION_1_1);//By default libcurl tries HTTP/2 first. FastAPI's dev server (uvicorn) only speaks HTTP/1.1. 

    /*
    CURLOPT_URL — where to go
CURLOPT_WRITEFUNCTION — which function to call when data arrives (our callback)
CURLOPT_WRITEDATA — pass our response string to that callback as the output parameter
    */
   curl_easy_perform(curl);
   cout<<response<<endl;
   curl_easy_cleanup(curl);
   return 0;


}