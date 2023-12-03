#pragma once
#include <string>
#include <unordered_map>


class http_request{ 
public:
    enum method {
    GET,
    POST,
    PUT,
    DELETE,
    PATCH
    };
    http_request(std::string& str);
    
    const std::string tostring();

    const std::string get_method();

    std::string& get_url();
private:
    method _method;
    std::string url;
    std::string param;
    std::string body;
    static const std::unordered_map<std::string,http_request::method> method_hashmap;
};
