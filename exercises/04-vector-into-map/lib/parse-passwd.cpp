#include "parse-passwd.h"

#include <stdexcept>


User parse_passwd_line(std::string line)
{
    User user;

    size_t cur = 0, next;
    next = line.find(':', cur);
    if (next == std::string::npos)
        throw PasswdError(PasswdError::LINE_INVALID, line);
    user.name = line.substr(cur, next-cur);

    cur = next + 1;
    next = line.find(':', cur);
    if (next == std::string::npos)
        throw PasswdError(PasswdError::LINE_INVALID, line);
    user.passwd = line.substr(cur, next-cur);

    cur = next + 1;
    next = line.find(':', cur);
    if (next == std::string::npos)
        throw PasswdError(PasswdError::LINE_INVALID, line);
    try {
        user.uid = std::stoi(line.substr(cur, next-cur));
    }
    catch (const std::invalid_argument&) {
        throw PasswdError(PasswdError::LINE_INVALID, line);
    }
    
    cur = next + 1;
    next = line.find(':', cur);
    if (next == std::string::npos)
        throw PasswdError(PasswdError::LINE_INVALID, line);
    try {
        user.gid = std::stoi(line.substr(cur, next-cur));
    }
    catch (const std::invalid_argument&) {
        throw PasswdError(PasswdError::LINE_INVALID, line);
    }
    
    cur = next + 1;
    next = line.find(':', cur);
    if (next == std::string::npos)
        throw PasswdError(PasswdError::LINE_INVALID, line);
    user.descr = line.substr(cur, next-cur);

    cur = next + 1;
    next = line.find(':', cur);
    if (next == std::string::npos)
        throw PasswdError(PasswdError::LINE_INVALID, line);
    user.homedir = line.substr(cur, next-cur);

    cur = next + 1;
    next = line.size();   // ':' won't be found
    if (next == cur)
        throw PasswdError(PasswdError::LINE_INVALID, line);
    user.shell = line.substr(cur, next-cur);
    if (user.shell[user.shell.size()-1] == '\n')
        user.shell = user.shell.substr(0, user.shell.size()-1);

    return user;
}
