#include <pqxx/pqxx>
#include <iostream>
#include "db/DBConn.h"

namespace search
{
    DBConn::DBConn(std::string &host, std::string &dbname, std::string &user, std::string &password)
    {
        pqxx::connection conn("host=localhost dbname=testdb user=testuser password=testpass");
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