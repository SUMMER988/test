//主元素 去不同，键值对map
#include <iostream>
#include <ctime>
#include <map>
// #include <bits/stdc++.h>

bool hashmappp(int arr[], int length, int &x)
{
    std::map<int, int> mappp;
    for (int i = 0; i < length; i++)
    {
        mappp[arr[i]]++;
    }
    int temp, count = 0;
    for (auto element : mappp)
    {
        if (element.second > count)
        {
            temp = element.first;
            count = element.second;
        }
    }
    if (count > length / 2)
    {
        x = temp;
        return true;
    }
    else
        return false;
}
int main()
{
    int x;
    int arr[8] = {0};
    // for (auto element : arr)
    // {
    //     std::cout << element << " ";
    // }
    // std::cout << std::endl;
    std::srand((unsigned int)time(0));
    for (int i = 0; i < 8; i++)
    {
        // std::cin >> arr[i];
        arr[i] = rand() % 2;
    }
    for (auto element : arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    int length = sizeof(arr) / sizeof(arr[0]);
    if (hashmappp(arr, length, x))
    {
        std::cout << "The main element is " << x << std::endl;
    }
    else
    {
        std::cout << "-1" << std::endl;
    }
    return 0;
}