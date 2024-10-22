#include "sysfs-file.h"

#include <unistd.h>
#include <assert.h>
#include <sstream>


SysFSFile::SysFSFile(const std::string& path)
: _path(path)
{}

int SysFSFile::read_int()
{
    int fd = open(_path.c_str(), O_RDONLY);
    assert(fd>=0);
    char buffer[64] = {0};
    ssize_t nread = read(fd, buffer, sizeof(buffer));
    close(fd);

    assert(nread < (ssize_t)sizeof(buffer));

    // copy all into a std::string, for the sole purpose of using
    // std::stoi() on it. todo: use std::from_chars()
    std::string s_buffer(buffer);

    return std::stoi(s_buffer);
}

void SysFSFile::write_int(int i)
{
    // todo: performance is not what sstream is known for
    std::ostringstream si;
    si << i << std::ends;
    std::string ssi = si.str();

    int fd = open(_path.c_str(), O_WRONLY);
    assert(fd>=0);
    ssize_t nwritten = write(fd, ssi.c_str(), ssi.size());
    assert(nwritten == (ssize_t)ssi.size());

    close(fd);
}
