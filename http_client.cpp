#include "http_client.h"
#include <iostream>
#include <curl/curl.h>

size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* buffer) {
    size_t realsize = size * nmemb;
    buffer->append((char*)contents, realsize);
    return realsize;
}

HttpClient::HttpClient() {
    curl_global_init(CURL_GLOBAL_ALL);
}

std::string HttpClient::get(const std::string& url) {
    CURL* curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        std::string buffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        CURLcode res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "Failed to get data from " << url << std::endl;
        }
        curl_easy_cleanup(curl);
        return buffer;
    } else {
        std::cerr << "Failed to initialize cURL" << std::endl;
        return "";
    }
}

