#pragma once
#include "brand/IBrandRepo.h"
#include "brand/Brand.h"
#include "db/DBConn.h"

namespace search {
    class BrandRepo: public IBrandRepo 
    {
    public:
        BrandRepo(DBConn *dbConn);

        std::unique_ptr<Brand> GetBrandById(const int id) override;
        std::unique_ptr<Brand> CreateBrand(const int id, const std::string& name) override;

    private:
        std::shared_ptr<DBConn> mDBConn;
    };
}