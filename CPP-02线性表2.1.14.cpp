#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int MinDistance(int a[], int b[], int c[], int a_length, int b_length, int c_length)
    {
        if (a_length <= 0 || b_length <= 0 || c_length <= 0)
        {
            return -1;
        }
        int min = INT_MAX;
        int dis = 0, first = 0, second = 0, third = 0;
        for (int i = 0, j = 0, k = 0; i < a_length && j < b_length && k < c_length;)
        {
            dis = max(max(abs(a[i] - b[j]), abs(a[i] - c[k])), abs(b[j] - c[k]));
            if (dis < min)
            {
                min = dis;
                first = i;
                second = j;
                third = k;
            }
            if (a[i] < b[j])
            {
                if (a[i] < c[k])
                {
                    ++i;
                }
                else
                {
                    ++k;
                }
            }
            else
            {
                if (b[j] < c[k])
                {
                    ++j;
                }
                else
                {
                    ++k;
                }
            }
        }
        cout << "First : " << first << " ,Second : " << second << " ,Third : " << third << endl;
        return min;
    }
};

int main()
{
    Solution A;
    int a[] = {5, 16, 20};
    int b[] = {13, 14, 15, 17, 35};
    int c[] = {19, 22, 24, 29, 32, 42};
    int l = 3, m = 5, n = 6;
    int result = A.MinDistance(a, b, c, l, m, n);
    cout << "The shortest distance is : " << result << endl;

    return 0;
}