#include <iostream>
#include <map>

int main()
{
    using MyMap = std::map<int, std::string>;

    MyMap my_map = {{42, "zweiundvierzig"}, {666, "sechshundertsechsundsechzig"}};

    try {
        my_map.at(7);
    }
    catch (const std::out_of_range&) {
        // ...
    }

    return 0;
}
