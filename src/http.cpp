#include "http.h"

#include <string>
#include <iostream>

std::unordered_map<std::string,http_request::method> http_request::method_hashmap{
    std::make_pair(std::string("GET"),http_request::GET),
    std::make_pair(std::string("POST"),http_request::POST),
    std::make_pair(std::string("PUT"),http_request::PUT),
    std::make_pair(std::string("DELETE"),http_request::DELETE),
    std::make_pair(std::string("PATCH"),http_request::PATCH)
};

std::unordered_map<std::string,std::string>  http_request::content_type_hashmap{
    std::make_pair(std::string("html"),std::string("text/html; charset=UTF-8")),
    std::make_pair(std::string("map"),std::string("application/javascript; charset=utf-8")),//
    std::make_pair(std::string("js"),std::string("application/javascript; charset=utf-8")),
    std::make_pair(std::string("svg"),std::string("image/svg+xml")),
    std::make_pair(std::string("jpg"),std::string("image/jpg")),
    std::make_pair(std::string("webp"),std::string("image/webp")),
    std::make_pair(std::string("png"),std::string("image/png")),//вообще хз
    std::make_pair(std::string("woff2"),std::string("font/woff2")),
    std::make_pair(std::string("css"),std::string("text/css; charset=utf-8"))
};

http_request::http_request(std::string& str){
    std::string buf = "";
    size_t i = 0;
    for(; i < str.size();i++){
        if(str[i] == ' '){            
            i++;
            break;
        }
        buf.push_back(str[i]);
    }    
    this->_method = method_hashmap[buf];
    buf.clear();
    for(; i < str.size();i++){
        if(str[i] == '.'){
            i++;       
            break;
        }
        buf.push_back(str[i]);
    }
    this->url = buf;
    buf.clear();
    for(; i < str.size();i++){
        if(str[i] == '?' || str[i] == ' ' ){            
            break;
        }
        buf.push_back(str[i]);
    }
    this->extension = buf;
    for(; i < str.size();i++){
        if(str[i] == ' '){            
            break;
        }
        buf.push_back(str[i]);
    }
    this->param = buf;
}



const std::string http_request::tostring(){
    const std::string str;
    return str;
    
}

const std::string http_request::get_method(){
    return {};    
}

std::string& http_request::get_url(){
    return this->url;
}

std::string& http_request::get_extension(){
    return this->extension;
}

std::string http_request::get_content_type(){
    return content_type_hashmap[this->extension];
}