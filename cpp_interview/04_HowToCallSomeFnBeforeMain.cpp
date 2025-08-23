// how to call some fn before main fn.
// Ans:- with the use of global variable or static data member of class.

#include <iostream>

// with the use of global variable
// void fun()
// {
// std::cout << "insider fn" << std::endl;
// }

// class Base
// {
// public:
// Base()
// {
// fun();
// }
// };
//
// Base b;
int fun()
{
    std::cout << "inside fn" << std::endl;
    return 9;
}
class Base
{
    static int staticVariable;
};

int Base::staticVariable = fun();

int main()
{

    std::cout << "insider main" << std::endl;
    return 0;
}