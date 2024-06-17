#include <gtest/gtest.h>

#include <vector-into-map.h>

TEST(vector_into_map_suite, basic)
{
    using my_pair = std::pair<std::string, int>;
    using my_pair_array = std::vector<my_pair>;
    my_pair_array pair_array{{"eins", 1}, {"zwei", 2}, {"drei", 3}};

    using my_pair_map = std::map<std::string, int>;

    my_pair_map pair_map = vector_into_map(pair_array);

    ASSERT_EQ(pair_map.size(), 3);
    ASSERT_EQ(pair_map["eins"], 1);
    ASSERT_EQ(pair_map["zwei"], 2);
    ASSERT_EQ(pair_map["drei"], 3);
}

TEST(vector_into_map_suite, no_overwrites)
{
    using my_pair = std::pair<std::string, int>;
    using my_pair_array = std::vector<my_pair>;
    my_pair_array pair_array{{"eins", 1}, {"zwei", 2}, {"drei", 3}, {"eins", 1000}};

    using my_pair_map = std::map<std::string, int>;

    my_pair_map pair_map = vector_into_map(pair_array);

    ASSERT_EQ(pair_map.size(), 3);
    ASSERT_EQ(pair_map["eins"], 1);
    ASSERT_EQ(pair_map["zwei"], 2);
    ASSERT_EQ(pair_map["drei"], 3);
}
