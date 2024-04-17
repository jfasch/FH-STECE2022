#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>

using namespace std;


int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <FILENAME>" << std::endl;
        return 1;
    }

    const char* filename = argv[1];

    int error = unlink(filename);
    if (error == -1) {
        cerr << "Jessas: " << errno << ", und zwar: \"" << strerror(errno) << '"' << endl;
        return 1;
    }
    
    return 0;
}
