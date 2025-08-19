#include <iostream>

class One
{
    int x = 10;

public:
    One(int x) : x{x} {}
    void dispalay()
    {
        std::cout << x << std::endl;
    }
};

int main()
{
    One one(10);
    one.dispalay();
    return 0;
}
