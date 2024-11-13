#include "sysfs-file.h"

#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>


SysFSFile::SysFSFile(const std::filesystem::path& path)
: _path(path)
{}

int64_t SysFSFile::read_int64()
{
    int fd = open(_path.c_str(), O_RDONLY);
    assert(fd>=0);  // todo: error handling (what if path does not
                    // exist?)
    char buffer[64] = {0};
    ssize_t nread = read(fd, buffer, sizeof(buffer));
    close(fd);

    assert(nread < (ssize_t)sizeof(buffer)); // todo: error handling

    // copy all into a std::string, for the sole purpose of using
    // std::stoi() on it. todo: use std::from_chars()
    std::string s_buffer(buffer);

    return std::stoll(s_buffer);
}

void SysFSFile::write_int64(int64_t i)
{
    // todo: performance is not what sstream is known for
    std::ostringstream si;
    si << i << std::endl;
    std::string ssi = si.str();

    int fd = open(_path.c_str(), O_WRONLY|O_TRUNC);
    if (fd == -1) {
        perror("open");
        assert(false); // todo: error handling
    }
    ssize_t nwritten = write(fd, ssi.c_str(), ssi.size());
    assert(nwritten == (ssize_t)ssi.size());  // todo: error handling

    close(fd);
}

uint64_t SysFSFile::read_uint64()
{
    int fd = open(_path.c_str(), O_RDONLY);
    assert(fd>=0);  // todo: error handling (what if path does not
                    // exist?)
    char buffer[64] = {0};
    ssize_t nread = read(fd, buffer, sizeof(buffer));
    close(fd);

    assert(nread < (ssize_t)sizeof(buffer)); // todo: error handling

    // copy all into a std::string, for the sole purpose of using
    // std::stoi() on it. todo: use std::from_chars()
    std::string s_buffer(buffer);

    return std::stoull(s_buffer);
}

void SysFSFile::write_uint64(uint64_t i)
{
    // todo: performance is not what sstream is known for
    std::ostringstream si;
    si << i << std::endl;
    std::string ssi = si.str();

    int fd = open(_path.c_str(), O_WRONLY|O_TRUNC);
    if (fd == -1) {
        perror("open");
        assert(false); // todo: error handling
    }
    ssize_t nwritten = write(fd, ssi.c_str(), ssi.size());
    assert(nwritten == (ssize_t)ssi.size());  // todo: error handling

    close(fd);
}

std::string SysFSFile::read_string()
{
    int fd = open(_path.c_str(), O_RDONLY);
    assert(fd>=0);  // todo: error handling (what if path does not
                    // exist?)
    char buffer[64] = {0};
    ssize_t nread = read(fd, buffer, sizeof(buffer));
    close(fd);

    assert(nread < (ssize_t)sizeof(buffer)); // todo: error handling

    // trim from back
    int idx = nread-1;
    while (idx > 0)
        if (std::isspace(buffer[idx]))
            --idx;
        else
            break;

    return std::string(buffer, idx+1);
}

void SysFSFile::write_string(const std::string& s)
{
    int fd = open(_path.c_str(), O_WRONLY|O_TRUNC);
    if (fd == -1) {
        perror("open");
        assert(false); // todo: error handling
    }
    ssize_t nwritten = write(fd, s.c_str(), s.size());
    assert(nwritten == (ssize_t)s.size());  // todo: error handling

    close(fd);
}
