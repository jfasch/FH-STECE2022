#pragma once

#include <string>
#include <fcntl.h>


class SysFSFile
{
public:
    SysFSFile(const std::string& path);

    int read_int();
    void write_int(int i);

private:
    const std::string _path;
};
