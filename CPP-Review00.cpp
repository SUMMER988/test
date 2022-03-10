#include <iostream>
//头文件 vector
#include <vector>
//头文件 algorithm 用于实现排序 查找
#include <algorithm>
#include <ctime>

using namespace std;
#define Size 10
//引用自:https://blog.csdn.net/weixin_43350051/article/details/97945841
bool cmp(int x, int y) /// cmp函数传参的类型不是vector<int>型，是vector中元素类型,即int型
{
    return x > y;
}

//打印容器元素
void PrintVector(vector<int> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    cout << endl;
}
//查找元素返回对应下标
int FindElement00(vector<int> v, int key)
{
    unsigned int len = v.size();
    for (size_t i = 0; i < len; i++)
    {
        if (v.at(i) == key)
        {
            return i;
        }
    }
    return -1;
}
//查找元素返回对应下标
int FindElement01(vector<int> v, int key)
{
    vector<int>::iterator it;
    it = find(v.begin(), v.end(), key);
    if (it != v.end())
    {
        return distance(v.begin(), it);
    }
    return -1;
}
//查找元素结果显示
void PrintFindResult(vector<int> v, int key)
{
    if (FindElement00(v, key) == -1)
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找元素下标为" << FindElement00(v, key) << endl;
    }
    cin.clear();
    cout << "错误状态为" << cin.rdstate() << endl; //再次查看错误状态 对应0 无错误
    cin.sync();                                    //清理缓冲区内容
}
//排序
void SortVector(vector<int> &v)
{
    sort(v.begin(), v.end());
}
int main()
{
    //定义vector

    //定义容器数组 此处为含有5个容器的容器数组
    // vector<int>a(5);

    //定义容器数组并且设置默认值 此处为含有5个容器的容器数组且默认值为10
    // vector<int>a(5, 10);

    //定义容器数组并分别设置默认值 此处为含有3个容器的容器数组默认值分别为 2 3 4
    // vector<int>a{2,3,4};

    //定义单个容器
    int num = 7;
    // cin >> num;
    vector<int> a;

    //定义一个二维向量
    //未进行扩展
    // vector<vector<int>>b;
    srand((unsigned int)time(0));
    for (int i = 0; i < num; i++)
    {
        //向容器中压入元素
        a.push_back(rand() % 10);
    }
    // a[num - 1] = 10;

    //遍历方法1

    cout << "原容器:" << endl;
    // a.size() :a矢量的元素个数
    for (int i = 0; i < a.size(); i++)
    {
        //访问vector元素的方法1:用[]取值
        cout << a[i] << "\t";
    }
    cout << endl;
    //遍历方法2
    // for (it = a.begin(); it != a.end(); it++)
    //访问vector元素的方法2:用指针取值
    //	cout << *it << "\t";

    //通过函数对vector进行操作需要加上& 如 (vector<int>& a)
    //遍历方法3
    /*for (int val : a)
    {
        cout << val << "\t";
    }*/

    //可用以下方法为a向量赋值
    /*
    for (int &val : a)
    {
        cin >> val;
    }
    */

    //排序 从小到大
    //头文件 algorithm
    cout << "排序后:" << endl;
    //加上cmp函数 为从大到小排序
    // sort(a.begin(), a.end());
    // sort(a.begin(), a.end(), cmp);
    SortVector(a);
    PrintVector(a);
    // //展示排序结果是否正确
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << "\t";
    // }
    // cout << endl;

    // //迭代器定义 与find函数的使用 需要algorithm头文件
    // vector<int>::iterator it;
    // it = find(a.begin(), a.end(), -21);
    // if (it != a.end())
    // {
    //     cout << distance(a.begin(), it) << endl;
    // }
    // int key, findtimes;
    // findtimes = 7;
    // while (findtimes--)
    // {
    //     cin >> key;
    //     PrintFindResult(a, key);
    // }
    // cout << FindElement00(a, 3) << endl;
    // cout << FindElement01(a, 9) << endl;
    auto it = find(a.begin(), a.end(), 1);
    if (it != a.end())
    {
        cout << it - a.begin() << endl;
    }
    cout << "OVER" << endl;
    string sss = "ABC";
    for (auto ch : sss)
        cout << ch << endl;
    return 0;
}
