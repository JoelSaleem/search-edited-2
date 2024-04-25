#include <string>

namespace utils
{
    // Todo: would be a good method to test
    std::unique_ptr<std::string> getPath(const std::string &input)
    {
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