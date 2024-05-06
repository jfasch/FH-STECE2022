#include "fixture-tmpdir-cwd.h"


cd_to_tmpdir_fixture::cd_to_tmpdir_fixture()
{
    _old_dirname = std::filesystem::current_path();
    std::filesystem::current_path(dirname);
}

cd_to_tmpdir_fixture::~cd_to_tmpdir_fixture()
{
    std::filesystem::current_path(_old_dirname);
}
