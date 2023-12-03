#include <string>
#include <asio.hpp>

#include "http.h"

std::string getrequest(asio::ip::tcp::socket& socket);

std::string get_respon(asio::ip::tcp::socket& socket,http_request& request);



