#include "comparison.hpp"

int compare(nlohmann::json json_1, nlohmann::json json_2){
    nlohmann::json json_1_only;
    nlohmann::json json_2_only;
    nlohmann::json json_1_more_version;
    ll i = 0, j = 0;
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
    ofstream out;
    out.open("json_1_only.json");
    if (out.is_open()){
        out<<json_1_only<<endl;
    }else{
        cout<<"Error with saving to a file!"<<endl;
        return 1;
    }
    out.close(); 
    out.open("json_2_only.json");
    if (out.is_open()){
        out<<json_2_only<<endl;
    }else{
        cout<<"Error with saving to a file!"<<endl;
        return 1;
    }
    out.close(); 
    out.open("json_1_more_version.json");
    if (out.is_open()){
        out<<json_1_more_version<<endl;
    }else{
        cout<<"Error with saving to a file!"<<endl;
        return 1;
    }
    out.close(); 
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
    write(ssocket, req);
    flat_buffer buffer;
    read(ssocket, buffer, *res);
    boost::system::error_code ec;
    ssocket.shutdown();
    ssocket.lowest_layer().shutdown(ip::tcp::socket::shutdown_both, ec);
    ssocket.lowest_layer().close();
    if (obsolete_reason(res->result()) != "OK"){
        cout<<"Incorrect request! Try again!"<<endl;
        return 1;
    }
    return 0;
}