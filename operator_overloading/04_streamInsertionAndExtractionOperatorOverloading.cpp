// TOPIC:- << and >> operator overloading.
// << stream extraction operator.
// >> stream insertion operator

// POINT:-
// 1. When we need overload << and >> ?
//  cout<<(user defined type) or cin>>(user defined type).
// 2. It can't be class member function, we have to make friend function of class.

#include <iostream>

class Test
{
    int x;

public:
    Test(int x = 0) : x{x} {}
    friend std::istream &operator>>(std::istream &input, Test &obj);
    friend std::ostream &operator<<(std::ostream &output, Test &obj);

    void display()
    {
        std::cout << x << std::endl;
    }
};

std::istream &operator>>(std::istream &input, Test &obj)
{
    input >> obj.x;
    return input;
}

std::ostream &operator<<(std::ostream &output, Test &obj)
{
    output << obj.x << std::endl;
    return output;
}

int main()
{
    Test t;
    std::cin >> t;
    std::cout << t;
    return 0;
}