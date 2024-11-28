#pragma once

#include <string>
#include <cstdint>


class SysFS_File
{
public:
    SysFS_File(const std::string& path);

    int64_t read_int64();
    void write_int64(int64_t);

    uint64_t read_uint64();
    void write_uint64(uint64_t);

    std::string read_string();
    void write_string(const std::string&);

private:
    std::string _path;
};
