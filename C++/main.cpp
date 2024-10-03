#include "comparison.hpp"

int main(int argc, char *argv[]){
    if (argc != 3){
        cout<<"Incorrect number of parameters!"<<endl;
        return 1;
    }
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