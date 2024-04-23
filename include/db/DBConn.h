#include <string>

namespace search
{
    class DBConn
    {
    public:
        DBConn(std::string &host, std::string &dbname, std::string &user, std::string &password);
    };
}