#include <parse-passwd.h>
#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <FILENAME>" << std::endl;
        return 1;
    }

    std::ifstream passwd(argv[1]);
    std::string line;
    while (std::getline(passwd, line)) {
        User user = parse_passwd_line(line);

        std::cout << "User.name    " << user.name << '\n';
        std::cout << "    .passwd  " << user.passwd << '\n';
        std::cout << "    .uid     " << user.uid << '\n';
        std::cout << "    .gid     " << user.gid << '\n';
        std::cout << "    .descr   " << user.descr << '\n';
        std::cout << "    .homedir " << user.homedir << '\n';
        std::cout << "    .shell   " << user.shell << '\n';
    }

    return 0;
}
