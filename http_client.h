#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>

class HttpClient {
public:
    HttpClient();
    std::string get(const std::string& url);
};

#endif // HTTP_CLIENT_H

