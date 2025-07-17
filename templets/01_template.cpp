#include <iostream>

int big(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

double big(double a, double b)
{
    return (a > b) ? a : b;
};

int main()
{
    std::cout << big(3.14, 3.4) << std::endl;
    return 0;
}