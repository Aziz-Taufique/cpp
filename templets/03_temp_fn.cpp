#include <iostream>

template <class X, class Y>

double add(X a, Y b)
{
    return b + a;
}

int main()
{
    std::cout << add(3, 3.3) << std::endl;
    return 0;
}