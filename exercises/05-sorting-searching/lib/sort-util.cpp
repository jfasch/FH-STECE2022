#include "sort-util.h"

#include <algorithm>


std::vector<int> sort_ascending(std::vector<int> nums)
{
    std::sort(nums.begin(), nums.end());
    return nums;
}

std::vector<int> sort_descending(std::vector<int> nums)
{
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    //std::sort(nums.rbegin(), nums.rend());
    return nums;
}
