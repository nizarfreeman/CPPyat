#include <iostream>
#include "Array.hpp"

class A
{
    public:
        int x;    
        A() : x(0) {}
        A(int v) : x(v) {}
};

std::ostream& operator<<(std::ostream& o, const A& a)
{
    o<<a.x;
    return o;
}

int main()
{
    std::cout<<"empty test\n";
    try
    {
        Array<int> e;
        std::cout<<e.size()<<"\n";
        std::cout<<e[0]<<"\n"; // throws
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<"\n";
    }

    std::cout<<"\nint test\n";
    Array<int> a(3);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i + 1;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout<<a[i]<<" ";
    std::cout<<"\n";

    std::cout<<"\nout of range\n";
    try
    {
        std::cout<<a[10]<<"\n"; // throws
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<"\n";
    }

    std::cout<<"\ncopy test\n";
    Array<int> b = a;
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout<<b[i]<<" ";
    std::cout<<"\n";

    std::cout<<"\nconst test\n";
    const Array<int> c(a);
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout<<c[i]<<" ";
    std::cout<<"\n";

    std::cout<<"\nclass test\n";
    Array<A> d(3);
    for (unsigned int i = 0; i < d.size(); i++)
        d[i] = A(i + 10);
    for (unsigned int i = 0; i < d.size(); i++)
        std::cout<<d[i]<<" ";
    std::cout<<"\n";

    return 0;
}