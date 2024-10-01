#ifndef __comparison__
#define __comparison__

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast.hpp>
#include <nlohmann/json.hpp>
#include "comparison.hpp"

#define ll long long

using namespace boost::beast;
using namespace boost::asio;
using namespace std;

const string host = "rdb.altlinux.org";
const string path = "/api/export/branch_binary_packages/";
const string port = "443";

template<typename T>
int compare(T json_1, T json_2);
int get_response(http::response<http::string_body> *res, string branch);

#endif