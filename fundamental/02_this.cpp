// this pointer in cpp.

// Notes:-
// 1. this pointer used to hold the address of current obj(using which we have called particular member function).
// 2. this pointer is a const pointer.
// 3. this pointer is passed as hidden argument to non-static member functions.
// 4. compiler automatic changes all data member access with this pointer.
// 5. It is not passed in static member function.

#include <iostream>

class Base
{
    int x;

public:
    Base(int a) : x{a} {}

    int getVal() { return this->x; };
    // int getVal(Base * const this){ return this} // compiler convert like this.

    void setVal(int x) { this->x = x; }
    // void setVal(Base *const this, int x) { this->x = x; };
};

int main()
{
    Base b(12), b2(33);
    std::cout << b.getVal() << std::endl;
    // Base::getVal(&b);       ---\  compiler convert like this
    // Base::setVal(&b, 23);   ---/
    std::cout << b2.getVal() << std::endl;

    return 0;
}
