#include <iostream>
int main()
{
    int a = 4;
    int b = 5;
    std::cout << a << " " << b << std::endl;

    // captured by value.
    auto add = [=](int x) -> int
    {
        return a + b + x;
    };

    std::cout << add(5) << std::endl;

    [](int &a, int b) -> void
    {
        std::cout << a << " " << b << " " << std::endl;
        a = 10;
        b = 30;
    }(a, b);
    std::cout << a << " " << b << std::endl;

    ///////////////////////

    // captured by refrence.
    [&]() -> void
    {
        a = 40;
        b = 80;
    }();

    std::cout << a << " " << b << " " << std::endl;
    return 0;
}