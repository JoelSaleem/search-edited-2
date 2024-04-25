#include "brand/BrandRepo.h"

namespace search
{
    BrandRepo::BrandRepo(DBConn *dbConn) : mDBConn{dbConn}
    {
    }

    std::unique_ptr<Brand>  BrandRepo::GetBrandById(const int id) {
        return nullptr;
    };

    std::unique_ptr<Brand> BrandRepo::CreateBrand(int id, const std::string& name) {
        return nullptr;
    };
}