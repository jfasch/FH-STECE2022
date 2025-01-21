#pragma once

#include <string>
#include <cstdint>


/** `sysfs` file

    `sysfs` files are used to represent attributes to userspace in the
    form of files. Usually these files contain only small amounts of
    information; for example the value of GPIO pin 25 is represented
    as file `/sys/class/gpio/gpio25/value` which contains either `0`
    or `1`.

 */
class SysFS_File
{
public:
    /** Constructor

        @param path path to sysfs file; e.g. `/sys/class/gpio/gpio25/value`
    */
    SysFS_File(const std::string& path);

    /** Read file contents as `int64_t`

     */
    int64_t read_int64();
    /** Write `int64_t` */
    void write_int64(int64_t value);

    
    /** Read file contents as `uint64_t` */
    uint64_t read_uint64();
    /** Write `uint64_t` */
    void write_uint64(uint64_t);

    /** Read file contents as `std::string` */
    std::string read_string();
    /** Write `std::string` */
    void write_string(const std::string&);

private:
    std::string _path;
};
