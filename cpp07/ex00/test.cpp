#include <iostream>
#include <string>
using namespace std;


template <typename T>
int max_(T x, int y=1)
{
    cout<<"waaaaaaaaaa"<<sizeof(x)<<" "<<sizeof(y)<<endl;
    return (x < y) ? y : x;
}

// int max(int x, int y)
// {
//     cout<<"hello from int yo"<<endl;
//     return (x < y) ? y : x;
// }

// double max_(double x, double y)
// {
//     cout<<"hello from double"<<endl;
//     return (x < y) ? y : x;
// }

int main(int argc, char const *argv[])
{
    double a = 5.6, b = 5.4;
    double a1 = 5, b1 = 6;
    cout<<sizeof(max_(5, b1))<<endl;
    return (0);
}
