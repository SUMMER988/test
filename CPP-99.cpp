#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <unordered_map>
class Solution
{
public:
    int findRepeatNumber(std::vector<int> &nums)
    {
        std::unordered_map<int, bool> map;
        for (int num : nums)
        {
            if (map[num])
                return num;
            map[num] = true;
        }
        return -1;
    }
};

int main()
{
    std::vector<int> mappp;
    srand((unsigned int)time(0));
    for (int i = 0; i < 5; i++)
    {
        mappp.push_back(rand() % 5);
    }
    for (int val : mappp)
    {
        std::cout << val << '\t';
    }
    std::cout << std::endl;

    Solution AAA;
    int x = AAA.findRepeatNumber(mappp);
    std::cout << "The repeated number is " << x << std::endl;
    return 0;
}