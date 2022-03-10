// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

extern int gl;

class A
{
public:
    int i;
    A();
    ~A();
    void f();
};

struct B
{
    int i;
};

A::A()
{
    i = -20;
    printf("A::A()--this=%p\n", this);
}

A::~A()
{
    printf("A::~A()\n");
}

void A::f()
{

    this->i = 20;
    printf("%d\n", i);
    printf("A::f()--&i=%p\n", &i);
    printf("this=%p\n", this);
}

void f(struct B *p)
{
    p->i = 20;
    cout << p->i << endl;
}

int main()
{
    A aa;
    aa.i = 10;
    printf("&a.i=%p\n", &aa.i);
    aa.f();
    // A b;
    // b.i = 40;
    // printf("&b.i=%p\n", &b.i);
    // b.f();

    return 0;
}