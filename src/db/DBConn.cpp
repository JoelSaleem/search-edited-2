#include <pqxx/pqxx>
#include <iostream>
#include "db/DBConn.h"
#include <format>

namespace search
{
    DBConn::DBConn(std::string &host, std::string &dbname, std::string &user, std::string &password)
    {
        std::string connStr = "host=" +host + " dbname=" +dbname + " user=" + user + " password=" + password;
        pqxx::connection conn(connStr);
        if (conn.is_open())
        {
            std::cout << "Opened database successfully: " << conn.dbname() << std::endl;
        }
        else
        {
            std::cerr << "Can't open database" << std::endl;
        }
    }
}