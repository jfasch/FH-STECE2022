#pragma once

#include <string>
#include <vector>


struct Person
{
    std::string name;
    std::string birth;
    unsigned int height = 0;
};

Person find_person_by_name(std::vector<Person>, std::string name);
