// NOTES:
// 1. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if sucess otherwise false.
// 2. Member function:
//    a. lock
//    b. try_lock
//    c. try_lock_for     -----\ These two functions makes it different
//    d. try_lock_until   -----/ from mutex.
//    e. unlock

// EXAMPLE; try_lock_for();
// Waits until specified timeout_duration has elapsed or the lock is acquired, whichever coems first.
// On successful lock acquisition returns true, otherwise returns false.

// try_lock.
/*
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int cnt = 0;
std::timed_mutex m;

void fn(int i)
{
    if (m.try_lock_for(std::chrono::seconds(1)))
    {
        ++cnt;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Thread " << i << " Entered" << std::endl;
        m.unlock();
    }
    else
    {
        std::cout << "Thread " << i << " Couldn't enter" << std::endl;
    }
};

int main()
{
    std::thread t1(fn, 1);
    std::thread t2(fn, 2);

    t1.join();
    t2.join();

    std::cout << cnt << std::endl;
    return 0;
}
*/

// try_lock_until.

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int cnt = 0;
std::timed_mutex m;

void fn(int i)
{
    auto now = std::chrono::steady_clock::now();
    if (m.try_lock_until(now + std::chrono::seconds(1)))
    {
        ++cnt;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Thread " << i << " Entered" << std::endl;
        m.unlock();
    }
    else
    {
        std::cout << "Thread " << i << " Couldn't enter" << std::endl;
    }
};

int main()
{
    std::thread t1(fn, 1);
    std::thread t2(fn, 2);

    t1.join();
    t2.join();

    std::cout << cnt << std::endl;
    return 0;
}
