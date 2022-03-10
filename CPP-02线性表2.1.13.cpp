//找出最小的未出现的整数
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

bool cmp(int x, int y)
{
    return x > y;
}
class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                std::swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main()
{
    Solution AA;
    std::vector<int> v;
    srand((unsigned int)time(0));
    for (int i = 0; i < 5; i++)
    {
        v.push_back(rand() % 5);
    }
    std::cout << "原容器为:" << std::endl;
    for (int val : v)
    {
        std::cout << val << "\t";
    }
    std::cout << std::endl;

    std::cout << "排序后:" << std::endl;
    // sort(v.begin(), v.end(), cmp);
    sort(v.begin(), v.end());
    for (int val : v)
    {
        std::cout << val << "\t";
    }
    std::cout << std::endl;

    int x = AA.firstMissingPositive(v);
    std::cout << x << std::endl;
    return 0;
}
