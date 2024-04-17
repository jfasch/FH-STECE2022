#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>

using namespace std;


int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <UID> <FILENAME>" << std::endl;
        return 1;
    }

    string uidstr = argv[1];
    string filename = argv[2];

    uid_t uid = stol(argv[1]);

    while (true) {
        int error = unlink(filename.c_str());
        if (error == -1) {
            if (errno == EACCES) {
                int error = setuid(uid);
                if (error == -1) {
                    cerr << "Nix setuid: " << errno << ", und zwar: \"" << strerror(errno) << '"' << endl;
                    return 1;
                }
                continue;
            }        
            else {
                cerr << "Jessas: " << errno << ", und zwar: \"" << strerror(errno) << '"' << endl;
                return 1;
            }
        }
        else 
            break;
    }
    
    return 0;
}
