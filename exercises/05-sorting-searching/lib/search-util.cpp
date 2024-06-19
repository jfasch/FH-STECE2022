#include "search-util.h"

#include <algorithm>


Person find_person_by_name(std::vector<Person> persons, std::string name)
{
    auto found = std::find_if(persons.cbegin(), persons.cend(),
                              [name](Person p) { return p.name == name; });
    if (found == persons.cend())
        return Person();
    return *found;
}
