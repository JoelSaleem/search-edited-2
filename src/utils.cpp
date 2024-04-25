#include <string>
#include "utils.h"

namespace utils
{
    void validateAndAppend(std::string &key, std::string &val, std::unordered_map<std::string, std::string> &mapping)
    {
        if (val == "")
        {
            throw std::runtime_error("empty val");
        }

        if (key == "")
        {
            throw std::runtime_error("empty key");
        }

        mapping[key] = val;
        key = "";
        val = "";
    }

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

    std::unique_ptr<std::unordered_map<std::string, std::string>> getQueryParams(const std::string &input)
    {
        if (input.size() == 0)
        {
            throw std::runtime_error("invalid path found of length 0");
        }

        if (input[0] != '/')
        {
            throw std::runtime_error("invalid path: does not begin with /");
        }

        // count at most ?
        bool startAcc = false;
        bool isKey = true;
        std::string key = "";
        std::string val = "";
        std::unique_ptr<std::unordered_map<std::string, std::string>> qp = std::make_unique<std::unordered_map<std::string, std::string>>();
        for (int i = 1; i < input.size(); i++) // first elem is /
        {
            if (input[i] == '?')
            {
                if (startAcc)
                {
                    throw std::runtime_error("invalid path, more than one ?");
                }

                startAcc = true;
            }
            else if (input[i] == '&')
            {
                if (isKey)
                {
                    throw std::runtime_error("found two keys in a row");
                }

                isKey = true;
                validateAndAppend(key, val, *qp);
            }
            else if (input[i] == '=')
            {
                if (!isKey)
                {
                    throw std::runtime_error("found two vals in a row");
                }
                isKey = false;

                if (key == "")
                {
                    throw std::runtime_error("empty key");
                }
            }
            else
            {
                if (!startAcc)
                {
                    continue;
                }
                if (isKey)
                {
                    key.push_back(input[i]);
                }
                else
                {
                    val.push_back(input[i]);
                }
            }
        }

        if (key != "")
        {
            validateAndAppend(key, val, *qp);
        }

        return qp;
    }
}
