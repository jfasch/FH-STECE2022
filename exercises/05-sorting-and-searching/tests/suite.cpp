#include <gtest/gtest.h>

#include <sort-util.h>
#include <search-util.h>


TEST(sorting_searching_suite, sort_ascending)
{
    std::vector<int> numbers = { 3, 5, 1, 666, 42 };
    auto sorted_numbers = sort_ascending(numbers);
    ASSERT_EQ(sorted_numbers.size(), 5);
    ASSERT_EQ(sorted_numbers[0], 1);
    ASSERT_EQ(sorted_numbers[1], 3);
    ASSERT_EQ(sorted_numbers[2], 5);
    ASSERT_EQ(sorted_numbers[3], 42);
    ASSERT_EQ(sorted_numbers[4], 666);
}

TEST(sorting_searching_suite, sort_descending)
{
    std::vector<int> numbers = { 3, 5, 1, 666, 42 };
    auto sorted_numbers = sort_descending(numbers);
    ASSERT_EQ(sorted_numbers.size(), 5);
    ASSERT_EQ(sorted_numbers[0], 666);
    ASSERT_EQ(sorted_numbers[1], 42);
    ASSERT_EQ(sorted_numbers[2], 5);
    ASSERT_EQ(sorted_numbers[3], 3);
    ASSERT_EQ(sorted_numbers[4], 1);
}

TEST(sorting_searching_suite, find_by_name_found)
{
    std::vector<Person> persons = {{"Joerg", "1966-06-29", 174},
                                   {"Johanna", "1995-06-11", 164},
                                   {"Caro", "1997-04-25", 161},
                                   {"Philipp", "1986-0004-06", 176}
    };

    auto person = find_person_by_name(persons, "Caro");
    ASSERT_EQ(person.name, "Caro");
    ASSERT_EQ(person.birth, "1997-04-25");
    ASSERT_EQ(person.height, 161);
}

TEST(sorting_searching_suite, find_by_name_notfound)
{
    std::vector<Person> persons = {{"Joerg", "1966-06-29", 174},
                                   {"Johanna", "1995-06-11", 164},
                                   {"Caro", "1997-04-25", 161},
                                   {"Philipp", "1986-0004-06", 176}
    };

    auto person = find_person_by_name(persons, "Eva");
    ASSERT_EQ(person.name, "");
    ASSERT_EQ(person.birth, "");
    ASSERT_EQ(person.height, 0);
}
