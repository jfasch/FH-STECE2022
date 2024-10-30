#include <gtest/gtest.h>

#include <base/sysfs-file.h>

#include "fixture-tmpdir.h"
#include <fstream>


struct sysfs_file_suite : tmpdir_fixture {};


TEST_F(sysfs_file_suite, read_int64_with_linefeed)
{
    std::ofstream(dirname / "my-file") << "1234\n";

    SysFSFile f(dirname / "my-file");
    ASSERT_EQ(f.read_int64(), 1234);
}

TEST_F(sysfs_file_suite, read_int64_without_linefeed)
{
    std::ofstream(dirname / "my-file") << "1234";

    SysFSFile f(dirname / "my-file");
    ASSERT_EQ(f.read_int64(), 1234);
}

TEST_F(sysfs_file_suite, write_int64)
{
    std::ofstream(dirname / "my-file"); // create file

    SysFSFile(dirname / "my-file").write_int64(1234);

    int i;
    std::ifstream(dirname / "my-file") >> i;

    ASSERT_EQ(i, 1234);
}

TEST_F(sysfs_file_suite, write_int64_truncate)
{
    std::ofstream(dirname / "my-file"); // create file

    SysFSFile file(dirname / "my-file");

    file.write_int64(100000);
    int64_t i;
    std::ifstream(dirname / "my-file") >> i;
    ASSERT_EQ(i, 100000);

    file.write_int64(666);
    std::ifstream(dirname / "my-file") >> i;
    ASSERT_EQ(i, 666);
}
