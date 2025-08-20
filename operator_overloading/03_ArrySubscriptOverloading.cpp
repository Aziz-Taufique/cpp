// TOPIC:- Overloadin [] operator in cpp (Array subscript operator).

// POINT:-
// 1. Array subscript opertaor can be used to check out of bound cases.
// 2. Array subscript operator can not be friend and other too (-> , (), =).

#include <iostream>

class Point
{
    int arr[2];

public:
    Point(int x = 0, int y = 0)
    {
        arr[0] = x;
        arr[1] = y;
    }
    int &operator[](int pos)
    {
        if (pos == 0)
            return arr[0];
        else if (pos == 1)
            return arr[1];
        else
        {
            std::cout << "out of bound" << std::endl;
            exit(0);
        }
    }
    void display()
    {
        std::cout << "x : " << arr[0] << " y : " << arr[1] << std::endl;
    }
};

int main()
{
    Point p(1, 3);
    p.display();
    p[0] = 2;
    p[1] = 4;
    p.display();
    p[2] = 6;
    p.display();
    return 0;
}