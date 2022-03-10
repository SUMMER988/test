#include <iostream>
//头文件 vector
#include <vector>
//头文件 algorithm 用于实现排序 查找
#include <algorithm>

//引用自:https://blog.csdn.net/weixin_43350051/article/details/97945841
bool cmp(int x, int y) /// cmp函数传参的类型不是vector<int>型，是vector中元素类型,即int型
{
    return x > y;
}

//通过函数对vector进行操作需要加上& 如 (vector<int>& a)

using namespace std;
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
    vector<int> a;

    //定义一个二维向量
    //未进行扩展
    // vector<vector<int>>b;

    for (int i = 0; i < 10; i++)
    {
        //向容器中压入元素
        a.push_back(-i * 10);
    }
    a[9] = 1;

    //遍历方法1

    cout << "原容器:" << endl;
    // a.size() :a矢量的元素个数
    for (int i = 0; i < a.size(); i++)
    {
        //访问vector元素的方法1:用[]取值
        cout << a[i] << "\t";
    }
    //遍历方法2
    // for (it = a.begin(); it != a.end(); it++)
    //访问vector元素的方法2:用指针取值
    //	cout << *it << "\t";

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
    cout << endl
         << "排序后:" << endl;
    //加上cmp函数 为从大到小排序
    sort(a.begin(), a.end() /*, cmp*/);

    //展示排序结果是否正确
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }

    //迭代器定义 与find函数的使用 需要algorithm头文件
    vector<int>::iterator ite;
    ite = find(a.begin(), a.end(), 1);
    cout << endl
         << "元素1的前一个值:" << *--ite;

    return 0;
}
