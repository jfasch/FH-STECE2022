#include <iostream>
#include <map>

void print(std::map<int, std::string>::const_iterator begin,
           std::map<int, std::string>::const_iterator end) {
    while (begin != end) {
        std::pair<int, std::string> elem = *begin;
        std::cout << elem.first << ',' << elem.second << std::endl;
        ++begin;
    }
}

int main()
{
    using MyMap = std::map<int, std::string>;

    MyMap my_map = {{666, "sechshundertsechsundsechzig"}, {42, "zweiundvierzig"}};

    print(my_map.cbegin(), my_map.cend());

    std::cout << std::endl;

    my_map[7] = "sieben";

    print(my_map.cbegin(), my_map.cend());

    return 0;
}
