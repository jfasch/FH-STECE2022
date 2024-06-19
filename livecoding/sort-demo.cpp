#include <algorithm>
#include <vector>
#include <iostream>


int main()
{
    std::vector<int> array = { 3, 1, 4, 666, 42 };

    auto begin = array.begin();
    auto end = array.end();

    std::sort(begin, end);

    // while (begin != end)
    //     std::cout << *begin++ << std::endl;
    
    // "range based for"
    for (auto elem: array)
        std::cout << elem << std::endl;

    return 0;
}
