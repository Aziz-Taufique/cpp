#include <iostream>
#include <thread>

class Base
{
public:
    void operator()(int x)
    {
        while (x > 0)
        {
            std::cout << x << std::endl;
            x--;
        }
    }
};

int main()
{
    std::thread t(Base(), 10);
    t.join();

    return 0;
}