#include <fstream>
#include <pqxx/pqxx>
#include <iostream>
#include "db/DBConn.h"
#include <format>
#include <nlohmann/json.hpp>
#include <string>

namespace search
{
    std::unique_ptr<pqxx::connection> DBConn::conn;
    std::unique_ptr<DBConn> DBConn::dbConn;

    DBConn &DBConn::Get()
    {
        if (!conn || !conn->is_open())
        {
            std::ifstream i("../config.json");
            nlohmann::json j;
            i >> j;

            std::string host = j["database"]["host"];
            std::string dbname = j["database"]["dbname"];
            std::string user = j["database"]["user"];
            std::string pass = j["database"]["pass"];
            dbConn = std::unique_ptr<DBConn>{new DBConn(host, dbname, user, pass)};
        }
        return *dbConn;
    };

    DBConn::DBConn(const std::string &host, const std::string &dbname, const std::string &user, const std::string &password)
    {
        std::string connStr = "host=" + host + " dbname=" + dbname + " user=" + user + " password=" + password;
        conn = std::make_unique<pqxx::connection>(connStr);
        if (conn->is_open())
        {
            std::cout << "Opened database successfully: " << conn->dbname() << std::endl;
        }
        else
        {
            std::cerr << "Can't open database" << std::endl;
        }
    }
}