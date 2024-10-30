#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{
    if (argc == 1) {
        cerr << "argh!" << endl;
        return 1;
    }

    ofstream(argv[1], ios::out);

    return 0;
}
