// Mutex: Mutual Exclusion

// RACE CONDITION:
// 1. Race condition is a situation where two or more threads/process happend to change a common data at the same time.
// 2. If there is a race condition then we have to protect it and the protected section is called critical section/region.

// MUTEX:
//  1. Mutex is used to avoid race condition.
//  2. We use lock(), unlock() on mutex to avoid race condition.

#include <iostream>
#include <thread>
#include <mutex>

int cnt = 0;
std::mutex m;
void fun()
{
    for (int i = 0; i < 10000; i++)
    {
        m.lock();
        cnt++; // this is line of code is called critical rection/region.
        m.unlock();
    }
};

int main()
{
    std::thread t1(fun);
    std::thread t2(fun);

    t1.join();
    t2.join();
    std::cout << cnt << std::endl;
    return 0;
}