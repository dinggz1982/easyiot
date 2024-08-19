#include "http_client.h"
#include <iostream>

int main() {
    HttpClient client;
    std::string url = "http://www.example.com";
    std::string response = client.get(url);
    std::cout << "Response from " << url << ":\n" << response << std::endl;
    return 0;
}
