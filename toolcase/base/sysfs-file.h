#pragma once

#include <filesystem>
#include <stdint.h>


class SysFSFile
{
public:
    SysFSFile(const std::filesystem::path& path);

    int64_t read_int64();
    void write_int64(int64_t i);

private:
    const std::filesystem::path _path;
};
