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
    nlohmann::json json_1_only;
    nlohmann::json json_2_only;
    nlohmann::json json_1_more_version;
    ll i = 0, j = 0, arch_i = 0, arch_j = 0;
    while (i != json_1["length"] && j != json_2["length"]){
        if (json_2["packages"][j]["arch"] < json_1["packages"][i]["arch"]){
            json_2_only += json_2["packages"][j];
            j++;
            continue;
        }
        if (json_2["packages"][j]["arch"] > json_1["packages"][i]["arch"]){
            json_1_only += json_1["packages"][i];
            i++;
            continue;
        }
        if (json_2["packages"][j]["name"] == json_1["packages"][i]["name"]){
            if (json_2["packages"][j]["version"] < json_1["packages"][i]["version"])
                json_1_more_version += json_1["packages"][i];
            i++;
            j++;
        }else if (json_2["packages"][j]["name"] > json_1["packages"][i]["name"]){
            json_1_only += json_1["packages"][i];
            i++;
        }else{
            json_2_only += json_2["packages"][j];
            j++;
        }
    }
    return 0;
}

int get_response(http::response<http::string_body> *res, string branch){
    try{
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
    }catch(...){
        cout<<"Incorrect request! Try again!"<<endl;
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]){
    http::response<http::string_body> res_1;
    if (get_response(&res_1, argv[1])){
        return 1;
    }
    auto json_1 = nlohmann::json::parse(res_1.body());
    http::response<http::string_body> res_2;
    if (get_response(&res_2, argv[2])){
        return 1;
    }
    auto json_2 = nlohmann::json::parse(res_2.body());
    if (compare(json_1, json_2)){
        return 1;
    }
    return 0;
}