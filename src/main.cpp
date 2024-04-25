#include <iostream>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "db/DBConn.h"
#include <nlohmann/json.hpp>

void handle_get(web::http::http_request request)
{
    ucout << "Received a GET request\n";
    web::json::value response_data;
    response_data[U("message")] = web::json::value::string(U("Hello, World!"));

    request.reply(web::http::status_codes::OK, response_data);
}

int main()
{
    std::ifstream i("../config.json");
    nlohmann::json j;
    i >> j;

    std::string host = j["database"]["host"];
    std::string dbname = j["database"]["dbname"];
    std::string user = j["database"]["user"];
    std::string pass = j["database"]["pass"];
    auto db = search::DBConn(host, dbname, user, pass);
    
    web::uri_builder uri(U("http://localhost:8080"));
    std::string addr = uri.to_uri().to_string();

    web::http::experimental::listener::http_listener listener(addr);
    listener.support(web::http::methods::GET, handle_get);

    try
    {
        listener
            .open()
            .then([&listener]()
                  { ucout << "Starting to listen at: " << listener.uri().to_string() << std::endl; })
            .wait();

        std::string line;
        std::getline(std::cin, line);
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}