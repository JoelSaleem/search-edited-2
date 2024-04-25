#pragma once
#include "db/DBConn.h"
#include "brand/Brand.h"

namespace search
{
    class IBrandRepo
    {
    public:
        virtual std::unique_ptr<Brand> GetBrandById(int id) = 0;
        virtual std::unique_ptr<Brand> CreateBrand(int id, const std::string &name) = 0;
    };
}
