// 4. Non-static member function

#include <iostream>
#include <thread>
class Base
{
public:
    void run(int x)
    {
        while (x)
        {
            std::cout << x << std::endl;
            x--;
        }
    }
};

int main()
{
    Base b;
    std::thread t(&Base::run, &b, 10);
    t.join();
    return 0;
}