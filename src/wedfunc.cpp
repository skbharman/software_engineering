#include "wedfunc.h"
#include "http.h"
#include <asio.hpp>

using asio::ip::tcp;

std::string getrequest(tcp::socket& socket){
    std::string request;
    for (;;){        
        std::array<char,128> buf;
        asio::error_code error;
        size_t len = socket.read_some(asio::buffer(buf), error);
        if (error == asio::error::eof) break; // Connection closed cleanly by peer.
        else if (error) throw asio::system_error(error); // Some other error.
        for(size_t i = 0; i < len; i++){
            request += buf[i];
        }
    }
    return request;
}

std::string get_respon(tcp::socket& socket,http_request& request){
    if(request.get_url() == "\\"){        
        return "";
    }
    return "";  
}