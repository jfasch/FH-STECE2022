#pragma once

#include <string>


/** User

    Represents the data from one line of /etc/passwd, e.g.
    "jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash"

    See ``man -s 5 passwd``

 */
struct User
{
    User() : uid(-1), gid(-1) {}    // <--- default constructor

    std::string name;
    std::string passwd;
    int uid;
    int gid;
    std::string descr;
    std::string homedir;
    std::string shell;
};

/** PasswdError

    Exception class to be throw on error from parse_passwd_line() (see
    below)

 */
struct PasswdError
{
    enum Code {                              // <--- nested type definition (error codes)
        LINE_INVALID,
    };

    PasswdError(Code code, std::string msg)  // <--- default constructor
    : code(code), msg(msg) {}

    Code code;                               // <--- struct member
    std::string msg;                         // <--- struct member
};

/** parse_passwd_line

    Given a line, parse from it items of ``struct User``.
    Throw exceptions of type ``PasswdError`` as they are encountered.

    See the test suite for detailed specs.

 */
User parse_passwd_line(std::string line);

