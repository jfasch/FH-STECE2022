#pragma once

#include "fixture-tmpdir.h"
#include <filesystem>


struct cd_to_tmpdir_fixture : public tmpdir_fixture
{
    cd_to_tmpdir_fixture();
    ~cd_to_tmpdir_fixture() override;

    std::filesystem::path _old_dirname;
};
