#pragma once

#include <gtest/gtest.h>

#include <string>
#include <stdlib.h>
#include <string.h>


struct tmpdir_fixture : public ::testing::Test
{
    tmpdir_fixture();
    ~tmpdir_fixture() override;

    std::string dirname;
};
