#include <string>
#include "utils.h"

namespace utils
{
    // Todo: would be a good method to test
    std::unique_ptr<std::string> getPath(const std::string &input)
    {
        if (input.size() == 0)
        {
            throw std::runtime_error("invalid path found of length 0");
        }

        if (input[0] != '/')
        {
            throw std::runtime_error("invalid path: does not begin with /");
        }

        std::unique_ptr<std::string> path = std::make_unique<std::string>("/");
        for (int i = 1; i < input.size(); i++) // first elem is /
        {
            if (input[i] == '?')
            {
                break;
            }

            path->push_back(input[i]);
        }

        return path;
    }
}