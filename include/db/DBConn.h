#pragma once
#include <string>
#include <pqxx/pqxx>

namespace search
{
    class DBConn
    {
    public:
        static DBConn &Get();

    protected:
        DBConn(const std::string &host, const std::string &dbname, const std::string &user, const std::string &password);

    private:
        static std::unique_ptr<pqxx::connection> conn;
        static std::unique_ptr<DBConn> dbConn;
    };
}