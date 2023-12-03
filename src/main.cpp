#include <iostream>
#include <asio.hpp>
#include <ctime>
#include <array>
#include <boost/array.hpp>

#include "http.h"
#include "wedfunc.h"

using asio::ip::tcp;

int main(){
    
    asio::io_context io_context;
    
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8083));
    
    try{
        for (;;)
        {
        
        tcp::resolver resolver(io_context);
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        
        std::cerr << socket.remote_endpoint().address().to_string();

        std::string request_str{getrequest(socket)};
        
        http_request request(request_str);
        
        std::string respon = get_respon(socket, request);
        asio::error_code ignored_error;
        asio::write(socket, asio::buffer(respon), ignored_error);               
        
    }
    }catch(std::exception& exc){
        std::cerr  << exc.what();
    }
    return 0;
}
// std::string message = "hello111";        
//         asio::error_code ignored_error;
//         asio::write(socket, asio::buffer(message), ignored_error);