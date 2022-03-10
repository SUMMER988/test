#include <iostream>
int main()
{
    int *p = 0;
    delete p;
    std::cout << "OK" << std::endl;
    return 0;
}