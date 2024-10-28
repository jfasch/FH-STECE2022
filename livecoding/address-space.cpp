#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int i = 42;
    // const char hello_old_c[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };
    // cout << strlen(hello_old_c) << endl;

    std::string hello = "Hello World";
    hello += " Joerg";
    cout << hello << " (" << hello.size() << ')' << i << endl;

    return 0;
}
