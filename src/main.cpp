#include <iostream>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include "db/DBConn.h"
#include "utils.h"

void handle_get(web::http::http_request request)
{

    std::string path = *utils::getPath(request.relative_uri().to_string());
    std::cout << path << std::endl;
    if (path == "/hello")
    {
        web::json::value response_data;
        response_data[U("message")] = web::json::value::string(U("Hello, World!"));

        request.reply(web::http::status_codes::OK, response_data);
    }
    else
    {
        request.reply(web::http::status_codes::NotFound);
    }
}

void handle_post(web::http::http_request request)
{
    std::string path = request.relative_uri().to_string();
    std::cout << path << std::endl;
    if (path == "/hello")
    {

        web::json::value response_data;
        response_data[U("message")] = web::json::value::string(U("Hello, World!"));

        request.reply(web::http::status_codes::OK, response_data);
    }
    else if (path == "/brand")
    {
        pplx::task<web::json::value> body = request.extract_json();
        auto brand = body.get()["name"];
        std::cout << "brand: " << brand << std::endl;
        
        web::json::value response_data;
        response_data[U("message")] = web::json::value::string(U("upserting brand"));

        request.reply(web::http::status_codes::OK, response_data);
    }
    else
    {
        request.reply(web::http::status_codes::NotFound);
    }
}

int main()
{

    auto db = search::DBConn::Get();

    web::uri_builder uri(U("http://localhost:8080"));
    std::string addr = uri.to_uri().to_string();

    web::http::experimental::listener::http_listener listener(addr);
    listener.support(web::http::methods::GET, handle_get);
    listener.support(web::http::methods::POST, handle_post);

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