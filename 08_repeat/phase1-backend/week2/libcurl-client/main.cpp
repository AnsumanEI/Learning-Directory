#include <iostream>
#include <string.h>
#include <curl/curl.h>
using namespace std;

// ─────────────────────────────────────────────
// STEP 1: THE CALLBACK FUNCTION
// ─────────────────────────────────────────────
// libcurl does NOT return the server response directly.
// Instead, every time a chunk of data arrives from the server,
// libcurl automatically calls this function.
// Our job: collect every chunk into one string called 'output'.
//
// Parameters:
//   contents — the chunk of raw bytes that just arrived
//   size     — size of one member (always 1 for HTTP)
//   nmemb    — number of members = number of bytes in this chunk
//   output   — OUR string where we collect everything
//
// Think of it like: postman slides pages under the door one at a time.
// This function catches each page and staples them together.
// ─────────────────────────────────────────────
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output)
{
    output->append((char*)contents, size * nmemb); // staple this chunk onto our string
    return size * nmemb; // tell libcurl "I consumed all bytes, send more"
}

// ─────────────────────────────────────────────
// STEP 3: POST REQUEST FUNCTION
// Called from main() AFTER the GET request is done.
// Sends JSON to FastAPI /echo and prints the response.
// ─────────────────────────────────────────────
// Why a separate function?
// Keeps main() clean. Each request has its own scope,
// its own response string, its own headers.
// ─────────────────────────────────────────────
void postEcho(CURL* curl)
{
    // Fresh response string for this request
    string response;

    // The JSON we are sending as the request body
    const char* jsonBody = "{\"text\": \"hello from c++\"}";

    // curl_slist = a linked list of HTTP headers
    // We need to tell FastAPI: "the body I am sending is JSON, not a form"
    // Without this header, FastAPI rejects the request
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    // headers list now contains one entry: "Content-Type: application/json"

    // Give the postman his instructions for this request
    curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8000/echo"); // where to go
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonBody);               // what to send as body
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);                // attach headers
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);       // use our collector function
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);               // collect into our string

    // Send the postman — he goes, server responds, WriteCallback collects chunks
    curl_easy_perform(curl);

    cout << "POST /echo: " << response << endl;

    // Free the headers linked list from memory — we created it, we clean it
    curl_slist_free_all(headers);
}

// ─────────────────────────────────────────────
// STEP 2: MAIN — THE ORCHESTRATOR
// Creates one postman (curl handle), uses it for two requests,
// then dismisses it.
// Flow: init → GET /users → reset → POST /echo → cleanup
// ─────────────────────────────────────────────
int main()
{
    // STEP 2a: Create the postman
    // curl_easy_init() returns a pointer to a CURL object
    // This one postman will be reused for both requests
    CURL* curl = curl_easy_init();

    if (!curl)
    {
        cerr << "Failed to init curl" << endl;
        return 1; // 0 = success, 1 = something went wrong
    }

    // STEP 2b: GET /users
    // Empty string — WriteCallback will fill this as chunks arrive
    string response;

    curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8000/users"); // where to go
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);        // use our collector
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);                // collect into response
    curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1); // force HTTP/1.1
    // Why HTTP/1.1? libcurl defaults to HTTP/2. Uvicorn dev server only speaks HTTP/1.1.
    // Forcing 1.1 prevents "invalid request" errors.

    // Send the postman for GET /users
    curl_easy_perform(curl);
    cout << "GET /users: " << response << endl;

    // STEP 2c: Reset the postman before the next request
    // curl_easy_reset() wipes ALL previous settings (URL, headers, options)
    // Without this, the GET /users settings would bleed into POST /echo
    curl_easy_reset(curl);

    // STEP 2d: POST /echo — handled in its own function
    postEcho(curl);

    // STEP 2e: Dismiss the postman and free all memory
    curl_easy_cleanup(curl);

    return 0;
}