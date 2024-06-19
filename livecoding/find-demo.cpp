#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    std::vector<int> array = { 3, 1, 4, 666, 42 };

    auto begin = array.cbegin();
    auto end = array.cend();

    auto found = std::find(begin, end, 7);

    if (found == array.cend())
        std::cout << "not found" << std::endl;
    else
        std::cout << *found << std::endl;
    
    return 0;
}
