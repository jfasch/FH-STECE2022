#include <gtest/gtest.h>

#include <uniq.h>
#include <average.h>


TEST(lab_exercise_suite, uniq)
{
    std::vector<std::string> names = {
        "Joerg",
        "Caro",
        "Johanna",
        "Philipp",
        "Caro",
        "Joerg",
    };

    // eliminate duplicates while preserving order
    auto unique_names = make_unique(names);

    ASSERT_EQ(unique_names.size(), 4);
    ASSERT_EQ(unique_names[0], "Joerg");
    ASSERT_EQ(unique_names[1], "Caro");
    ASSERT_EQ(unique_names[2], "Johanna");
    ASSERT_EQ(unique_names[3], "Philipp");
}

TEST(lab_exercise_suite, average)
{
    using measurement = std::pair<unsigned long/*timestamp*/, double/*temperature*/>;
    std::vector<measurement> measurements = {
        { 1718859439, 37.5 },
        { 1718859442, 36.5 },
        { 1718859444, 36.7 },
        { 1718859446, 37.0 },
    };

    double avg = average(measurements);

    ASSERT_DOUBLE_EQ(avg, 36.925);
}

TEST(lab_exercise_suite, xxx)
{
    using measurement = std::pair<std::string/*sensor-name*/, std::pair<unsigned long/*timestamp*/, double/*temperature*/>>;
    std::vector<measurement> measurements = {
        { "links-oben", { 1718859439, 37.5 }},
        { "rechts-oben", { 1718859442, 36.5 }},
        { "links-oben", { 1718859444, 36.7 }},
        { "rechts-oben", { 1718859446, 37.0 }},
    };

    auto avg_per_sensor = averages(measurements);

    ASSERT_EQ(avg_per_sensor.size(), 2);
    ASSERT_NE(avg_per_sensor.find("links-oben"), avg_per_sensor.end());
    ASSERT_NE(avg_per_sensor.find("rechts-oben"), avg_per_sensor.end());

    auto links_oben = avg_per_sensor.find("links-oben");
    ASSERT_DOUBLE_EQ(links_oben->second, 37.1);

    auto rechts_oben = avg_per_sensor.find("rechts-oben");
    ASSERT_DOUBLE_EQ(rechts_oben->second, 36.75);
}
