#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;


int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 3;
    }

    std::string filename = argv[1];
    
    int fd = open(filename.c_str(), O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    while (true) {
        off_t pos = lseek(fd, 0, SEEK_SET);
        if (pos == -1) {
            perror("lseek");
            return 2;
        }

        char buf[32];
        ssize_t nread = read(fd, buf, sizeof(buf));
        if (nread == -1) {
            perror("read");
            return 3;
        }
        
        std::this_thread::sleep_for(1s);        
        std::cout << buf << std::endl;
    }

    return 0;
}
