// Thread or process Syncronization.
// NOTE:- we will only use thread example to explain this topic.

// POINTS:
// 1. Thread or process syncronize to access critical section.
// 2. Critical section is one or collection of program statments which should be executed by one thread or process at a time.
#include <iostream>
#include <thread>
#include <mutex>

long long balance = 0;
std::mutex m;

void addMoney(long long amount)
{
    m.lock();
    balance += amount;
    m.unlock();
};

int main()
{
    std::thread t1(addMoney, 100);
    std::thread t2(addMoney, 200);

    t1.join();
    t2.join();

    std::cout << "Total balance : " << balance << std::endl;
    return 0;
}
