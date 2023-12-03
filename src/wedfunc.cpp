#include "wedfunc.h"
#include "http.h"
#include <asio.hpp>
#include <fstream>
#include <iostream>
#include <boost/array.hpp>
#include <boost/filesystem.hpp>
#include <vector>

using asio::ip::tcp;

std::string getrequest(tcp::socket& socket){
    std::string request;
    for (;;){        
        boost::array<char, 128> buf;
        asio::error_code error;
        size_t len = socket.read_some(asio::buffer(buf), error);
        if (error == asio::error::eof ) break; // Connection closed cleanly by peer.
        
        for(size_t i = 0; i < len; i++){
            request += buf[i];
        }
        if(len < 128) break;
        //std::cerr  << request.size() << '\n';
    }
    //std::cerr  << request;
    return request;
}

std::string get_respon(tcp::socket& socket,http_request& request){
    //std::cerr  << "url" << request.get_url() << "\n";
    if(request.get_content_type()[0] != 'i'){
        boost::filesystem::ifstream file_html("/home/danya/Documents/software_engineering/templates"
        + request.get_url()
        + '.'
        + request.get_extension());
        std::cerr << "home/danya/Documents/software_engineering/templates"
        + request.get_url()
        + '.'
        + request.get_extension();
        std::string html;
        if(file_html.is_open()){
            std::cerr << "open\n";
            while(!file_html.eof()){
                std::string buf;
                std::getline(file_html,buf);
                html += buf;            
            }
            file_html.close();
        }else{
            std::cerr << "not open error\n";
        }
        std::string str = "HTTP/2 200 OK \r\n"+
        std::string("Server: Apache \r\n")+
        "Content-Type: " + request.get_content_type() + "\r\n"+
        "Content-Length:" + std::to_string(html.size()) + " \r\n\n"
        + html;
        return str;
    }else{
        std::ifstream file_imag("/home/danya/Documents/software_engineering/templates"
        + request.get_url()
        + '.'
        + request.get_extension(), std::ios::binary);
        std::cerr << "home/danya/Documents/software_engineering/templates"
        + request.get_url()
        + '.'
        + request.get_extension();
        std::vector<unsigned char> imag;
        if(file_imag.is_open()){
            std::cerr << "1open\n";
            while(!file_imag.eof()){
                char buf;
                file_imag.get(buf);
                imag.push_back(buf);
            }
            file_imag.close();
        }else{
            std::cerr << "not open error\n";
        }
        std::string str = "HTTP/2 200 OK \r\n"+
        std::string("Server: Apache \r\n")+
        "Content-Type: " + request.get_content_type() + "\r\n"+
        "Content-Length:" + std::to_string(imag.size()) + " \r\n\n";
        for(auto elem : imag){
            str += elem;
        }
        return str;
    }
}