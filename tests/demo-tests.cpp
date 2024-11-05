#include <gtest/gtest.h>

#include <vector>


// -----------------------------------------------------------------
TEST(demo_suite, first_example_that_fails)
{
//    FAIL();
}

TEST(demo_suite, second_example_that_might_fail)
{
    int a = 1;
    int b = 1;

    ASSERT_EQ(a+b, 2);
}


// -----------------------------------------------------------------
struct vector_suite : public ::testing::Test
{
    vector_suite()
    {
        v_sut.push_back(3);
        v_sut.push_back(42);
        v_sut.push_back(666);
    }

    std::vector<int> v_sut; // SUT: "subject under test"
};

TEST_F(vector_suite, modify_sut)
{
    v_sut.push_back(666666);

    ASSERT_EQ(v_sut.size(), 4);
}

TEST_F(vector_suite, vector_first_test)
{
    ASSERT_EQ(v_sut.size(), 3);
}

TEST_F(vector_suite, vector_second_test)
{
    ASSERT_EQ(v_sut[0], 3);
    ASSERT_EQ(v_sut[1], 42);
    ASSERT_EQ(v_sut[2], 666);
}

