// reference data member in cpp.

#include <iostream>

class Base
{
    int &x;

public:
    Base(int &x) : x(x) {}

    void print()
    {
        std::cout << x << std::endl;
        std::cout << "address of val in class : " << &x << std::endl;
    }
};

int main()
{
    int val = 10;
    Base b(val);
    b.print();
    std::cout << "address of val in main : " << &val << std::endl;
    // x in class is private but still you can change in fn.
    val = 33;
    b.print();
}

// val in main and x in class both boints to same data or address.