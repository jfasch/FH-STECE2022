#include <vector>
#include <iostream>


int main()
{
    using MyVector = std::vector<std::pair<int, int>>;

    MyVector my_vec = {{1,2}, {3,4}, {5,6}};
    auto /*MyVector::const_iterator*/ begin = my_vec.cbegin();
    auto end = my_vec.cend();

    while (begin != end) {
        std::cout << begin->first << ',' << begin->second << std::endl;
        ++begin;
    }
    return 0;
}
