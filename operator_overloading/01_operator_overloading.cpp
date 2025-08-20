// OPERATOR OVERLOADING:-
// In cpp it is possible the change the behaviour of operator (+,-,*...).
// But we can change the behaviour for user defined types (class, struct) only.

// If we use them our program become more intutive.

// There are few operator which we can't overload.
// 1. ::
// 2. ?:  (termary operator)
// 3. .
// 4. .*
// 5. sizeof
// 5. typeid

#include <iostream>

class Point
{
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x{x}, y{y} {};
    Point operator+(const Point &rhs)
    {
        Point p;
        p.x = x + rhs.x;
        p.y = y + rhs.y;
        return p;
    }

    Point operator-(const Point &rhs)
    {
        Point p;
        p.x = x - rhs.x;
        p.y = y - rhs.y;
        return p;
    }

    Point operator*(const Point &rhs)
    {
        Point p;
        p.x = x * rhs.x;
        p.y = y * rhs.y;
        return p;
    }

    Point add(const Point &rhs)
    {
        Point p;
        p.x = x + rhs.x;
        p.y = y + rhs.y;
        return p;
    }

    void print()
    {
        std::cout << "val of x is : " << x << std::endl;
        std::cout << "val of y is : " << y << std::endl;
    }
};

int main()
{
    Point p1(3, 3), p2(4, 3);
    Point p3 = p1 + p2;
    Point p4 = p3 - p1;
    Point p5 = p3 * p4;
    Point p6 = p5.add(p4);
    p3.print();
    p4.print();
    p5.print();
    p6.print();
    return 0;
}