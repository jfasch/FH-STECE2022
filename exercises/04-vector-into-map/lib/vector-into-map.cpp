#include "vector-into-map.h"


std::map<std::string, int> vector_into_map(std::vector<std::pair<std::string, int>> array)
{
    std::map<std::string, int> rv;

    for (auto key_value_pair: array)
        // insert()
        // (https://en.cppreference.com/w/cpp/container/map/insert)
        // guarantees that no elements are overwritten
        rv.insert(key_value_pair);

    return rv;
}
