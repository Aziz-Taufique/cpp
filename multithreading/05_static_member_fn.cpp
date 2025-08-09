// 4. static member function

#include <iostream>
#include <thread>
class Base
{
public:
    static void run(int x)
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
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}