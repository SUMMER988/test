#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

int main()
{
    srand((unsigned int)time(0));
    vector<int> nums;
    for (size_t i = 0; i < 7; i++)
    {
        nums.push_back(rand() % 10);
    }
    sort(nums.begin(), nums.end());
    for (auto val : nums)
        cout << val << "\t";
    cout << endl;

    {
        int times = 5;
        while (times--)
        {
            for (auto &val : nums)
            {
                val = 11 + rand() % 9;
            }
            sort(nums.begin(), nums.end());
            for (auto it = nums.begin(); it != nums.end(); it++)
            {
                cout << *it << "\t";
            }
            cout << endl;
        }
    }
    string sss("ABCD");
    for (auto ch : sss)
        cout << ch << "\t";
    return 0;
}