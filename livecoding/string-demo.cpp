#include <string>
#include <iostream>

int main()
{
    std::string a = "abc";
    std::string b = "yz";

    if (a < b)
        std::cout << "a<b" << std::endl;
    else
        std::cout << "b<a" << std::endl;

    return 0;
}
