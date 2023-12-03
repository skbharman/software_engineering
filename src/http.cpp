#include "http.h"

#include <string>

const std::unordered_map<std::string,http_request::method> http_request::method_hashmap{
    std::make_pair(std::string("GET"),http_request::GET),
    std::make_pair(std::string("POST"),http_request::POST),
    std::make_pair(std::string("PUT"),http_request::PUT),
    std::make_pair(std::string("DELETE"),http_request::DELETE),
    std::make_pair(std::string("PATCH"),http_request::PATCH)
};

http_request::http_request(std::string& str){
    std::string buf = "";
    size_t i = 0;
    for(; i < str.size();i++){
        if(str[i] == ' '){
            i++;
            break;
        }
    }    
    this->_method = (*(http_request::method_hashmap.find(buf))).second;
    buf.clear();
    for(; i < str.size();i++){
        if(str[i] == ' ' || str[i] == '?'){            
            break;
        }
    }
    this->url = (*(http_request::method_hashmap.find(buf))).second;
    for(; i < str.size();i++){
        if(str[i] == ' '){            
            break;
        }
    }
    this->param = (*(http_request::method_hashmap.find(buf))).second;
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