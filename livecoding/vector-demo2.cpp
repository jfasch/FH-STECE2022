#include <vector>
#include <iostream>

std::vector<int> f();

int main()
{
    std::vector<int> array = { 4, 1, 7, 42, 666, 18 };

    auto begin = array.cbegin();
    auto end = array.cend();
    while (begin != end)
        std::cout << *begin++ << std::endl;

    array.push_back(1001);

    std::cout << std::endl;
    
    begin = array.cbegin();
    end = array.cend();
    while (begin != end)
        std::cout << *begin++ << std::endl;

    return 0;
}
