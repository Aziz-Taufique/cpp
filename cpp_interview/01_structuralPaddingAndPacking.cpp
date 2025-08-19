// Question:- What is structural padding and packing in c and cpp?
// Ans:- It is a way to spped up cpu optimizatioin.
#include <iostream>

#pragma pack(1) // disables padding

class Base
{
    char a;
    char b;
    char c;
    int d;
};

int main()
{
    std::cout << sizeof(Base) << std::endl;
    return 0;
}
