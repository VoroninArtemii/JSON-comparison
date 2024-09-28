#include <string>
#include <iostream>
#include <vector>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <nlohmann/json.hpp>

#define ll long long

using namespace boost::beast;
using namespace boost::asio;
using namespace std;

const string host = "rdb.altlinux.org";
const string path = "/api/export/branch_binary_packages/";
const string port = "443";

template<typename T>
int compare(T json_1, T json_2){
    vector<string> json_1_only;
    vector<string> json_2_only;
    ll i = 0, j = 0;
    while (i != json_1["length"] && j != json_2["length"]){
        if (json_2["packages"][j]["name"] == json_1["packages"][i]["name"]){
            i++;
            j++;
        }else if (json_2["packages"][j]["name"] > json_1["packages"][i]["name"]){
            json_1_only.push_back(json_1["packages"][i]["name"]);
            i++;
        }else{
            json_2_only.push_back(json_2["packages"][j]["name"]);
            j++;
        }
    }
    return 0;
}

int get_response(http::response<http::string_body> *res, string branch){
    string full_path = path + branch;
    io_service svc;
    ssl::context ctx(ssl::context::sslv23_client);
    ssl::stream<ip::tcp::socket> ssocket = {svc, ctx};
    ip::tcp::resolver resolver(svc);
    auto it = resolver.resolve(host, port);
    connect(ssocket.lowest_layer(), it);
    ssocket.handshake(ssl::stream_base::handshake_type::client);
    http::request<http::string_body> req = {http::verb::get, full_path, 11};
    req.set(http::field::host, host);
    http::write(ssocket, req);
    flat_buffer buffer;
    http::read(ssocket, buffer, *res);
    boost::system::error_code ec;
    ssocket.shutdown();
    ssocket.lowest_layer().shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
    ssocket.lowest_layer().close();
    return 0;
}

int main(int argc, char *argv[]){
    http::response<http::string_body> res_1;
    get_response(&res_1, argv[1]);
    auto json_1 = nlohmann::json::parse(res_1.body());
    http::response<http::string_body> res_2;
    get_response(&res_2, argv[2]);
    auto json_2 = nlohmann::json::parse(res_2.body());
    compare(json_1, json_2);
    return 0;
}