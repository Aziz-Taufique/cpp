// Topic unary operator overloading.

// unary operator overloading need only one operand. (+, -, ++, --, !, etc).

#include <iostream>
class Point
{
    int x;
    int y;

public:
    Point(int x = 0, int y = 0) : x{x}, y{y} {}

    Point operator-()
    {
        return Point(-x, -y);
    }

    Point operator!()
    {
        return Point(!x, !y);
    }

    Point operator++()
    {
        return Point(++x, ++y);
    }
    void display()
    {
        std::cout << "x : " << x << " y : " << y << std::endl;
    }
};

int main()
{
    Point p1(1, 3), p2(3, 3);
    Point p3 = -p1;
    Point p4 = !p1;
    Point p5 = ++p2;

    p3.display();
    p4.display();
    p5.display();
    return 0;
}