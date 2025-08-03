// TOPIC : Types of thred creation.
// There are 5 different types we can create threads using callback objects.

// If you create multiple thread at same time it doesn't guarantee which one will start first.

// 1. Function pointer.
// This is very basic form of thread creation.

#include <iostream>
#include <thread>

void fun(int x)
{
    while (x-- > 0)
    {
        std::cout << x << std::endl;
    }
}

int main()
{
    std::thread t1(fun, 10);
    std::thread t2(fun, 11);

    t1.join();
    t2.join();
    return 0;
}