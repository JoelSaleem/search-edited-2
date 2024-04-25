#include <memory>

namespace utils
{
    std::unique_ptr<std::string> getPath(const std::string &input);

    std::unique_ptr<std::unordered_map<std::string, std::string>> getQueryParams(const std::string &input);
}