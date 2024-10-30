#pragma once

#include <string>
#include <stdint.h>


class SysFSFile
{
public:
    SysFSFile(const std::string& path);

    int64_t read_int64();
    void write_int64(int64_t i);

private:
    const std::string _path;
};
