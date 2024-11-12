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

TEST_F(sysfs_file_suite, read_uint64_t)
{
    std::ofstream(dirname / "my-file") << "42\n";

    SysFSFile file(dirname / "my-file");

    ASSERT_EQ(file.read_uint64(), 42);
}

TEST_F(sysfs_file_suite, write_uint64_t)
{
    std::ofstream(dirname / "my-file") << "0\n";

    SysFSFile file(dirname / "my-file");

    ASSERT_EQ(file.read_uint64(), 0);

    file.write_uint64(42); // 2**64-1

    uint64_t content;
    std::ifstream(dirname / "my-file") >> content;

    ASSERT_EQ(content, 42);
}

TEST_F(sysfs_file_suite, read_max_uint64_t)
{
    std::ofstream(dirname / "my-file") << "18446744073709551615\n"; // 2**64-1

    SysFSFile file(dirname / "my-file");

    ASSERT_EQ(file.read_uint64(), std::numeric_limits<uint64_t>::max());
}

TEST_F(sysfs_file_suite, write_max_uint64_t)
{
    std::ofstream(dirname / "my-file") << "0\n";

    SysFSFile file(dirname / "my-file");

    ASSERT_EQ(file.read_uint64(), 0);

    file.write_uint64(18446744073709551615ULL); // 2**64-1

    uint64_t content;
    std::ifstream(dirname / "my-file") >> content;

    ASSERT_EQ(content, 18446744073709551615ULL);
}

TEST_F(sysfs_file_suite, read_string)
{
    std::ofstream(dirname / "my-file") << "blah\n";

    SysFSFile file(dirname / "my-file");

    ASSERT_EQ(file.read_string(), "blah");
}

TEST_F(sysfs_file_suite, write_string)
{
    std::ofstream(dirname / "my-file") << "blah\n";

    SysFSFile file(dirname / "my-file");
    ASSERT_EQ(file.read_string(), "blah");

    file.write_string("blech");

    std::string content;
    std::ifstream(dirname / "my-file") >> content;

    ASSERT_EQ(content, "blech");
}
