#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <nlohmann/json.hpp>

using namespace boost::beast;
using namespace boost::asio;
using namespace std;

int main(int argc, char *argv[]){
    const string host = "rdb.altlinux.org";
    const string path = "/api/export/branch_binary_packages/p10";
    const string port = "443";
    io_service svc;
    ssl::context ctx(ssl::context::sslv23_client);
    ssl::stream<ip::tcp::socket> ssocket = {svc, ctx};
    ip::tcp::resolver resolver(svc);
    auto it = resolver.resolve(host, port);
    connect(ssocket.lowest_layer(), it);
    ssocket.handshake(ssl::stream_base::handshake_type::client);
    http::request<http::string_body> req = {http::verb::get, path, 11};
    req.set(http::field::host, host);
    http::write(ssocket, req);
    http::response<http::string_body> res;
    flat_buffer buffer;
    http::read(ssocket, buffer, res);
    auto json = nlohmann::json::parse(res.body());
    std::cout<<json<<std::endl;
    return 0;
}