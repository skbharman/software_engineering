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
    
    std::string& get_extension();
    std::string get_content_type();
private:
    method _method;
    std::string url;
    std::string param;
    std::string body;
    std::string extension;
    static  std::unordered_map<std::string,http_request::method> method_hashmap;
    static  std::unordered_map<std::string,std::string> content_type_hashmap;
};
