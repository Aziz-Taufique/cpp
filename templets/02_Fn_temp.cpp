#include <iostream>

template <class X>
// X big(X a, X b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }

bool big(X a, X b)
{
    return (a > b) ? true : false;
}

int main()
{
    std::cout << big(3, 5) << std::endl;
    std::cout << big(6.44, 5.33) << std::endl;
    return 0;
}