#include <vector>
#include <iostream>


int main()
{
    std::vector<int> array{42, 666, 7, 88};
    auto begin = array.cbegin();
    auto end = array.cend();

    while (begin != end)
        std::cout << *begin++ << std::endl;

    return 0;
}
