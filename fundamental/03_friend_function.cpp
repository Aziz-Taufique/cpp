// Friend function and friend class in cpp.

// NOTES:-
// Keyword "friend" is used to make some [function or class] as friend of your class.
// Friend function or friend class can access private/public/protected data member of member function of another class.
// Function cannot become friend of another function.
// Class cannot become friend of function.
// Friendship is not mutual. If a calss A is friend of B, then B does't become frient of A automatically.
// Friendship is not inherited.

#include <iostream>

class Base
{
    int x;

public:
    Base(int a) : x{a} {}
    friend void setVal(Base &, int);
    friend int getVal(Base &);
    void display()
    {
        std::cout << x << std::endl;
    }
};

void setVal(Base &obj, int b)
{
    obj.x = b;
};

int getVal(Base &obj)
{
    return obj.x;
}
int main()
{
    Base b(10);
    std::cout << getVal(b) << std::endl;
    setVal(b, 20);
    b.display();
    std::cout << getVal(b) << std::endl;
    b.display();
    return 0;
}