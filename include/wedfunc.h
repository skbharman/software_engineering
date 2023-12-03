#include <string>
#include <asio.hpp>

std::string getrequest(asio::ip::tcp::socket& socket);

std::string get_respon(asio::ip::tcp::socket& socket);



