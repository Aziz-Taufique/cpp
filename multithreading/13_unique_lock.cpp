// TOPIC:- unique lock (std::unique_lock<mutex> lock(m1))

/*
NOTES:
1. The class unique_lock is a mutex ownership wrappper.
2. It Allows.
    a. Can have diferent lockign strategies.
    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
    c. recursive locking
    d. transfer of lock ownership (move not copy)
    e. condition variables.

// Locking strategies.
//      TYPE             ERRECTS
// 1. defer_lock         do not acquire ownership of the mutex.
// 2. try_to_lock        try to acquire ownership of the mutex without blocking.
// 3. adopt_lock         assume the calling thread already has ownership of the mutex.
 */

// example 1.

#include <iostream>
#include <thread>
#include <mutex>

int buffer = 0;
std::mutex m;
void fun(int cnt, const char *c)
{
    std::unique_lock<std::mutex> lock(m); // Automatically calls lock on mutex m.
    for (int i = 0; i < cnt; i++)
    {
        std::cout << c << " " << buffer++ << std::endl;
    }
};

int main()
{
    std::thread t1(fun, 10, "t1");
    std::thread t2(fun, 10, "t2");

    t1.join();
    t2.join();

    std::cout << buffer << std::endl;
    return 0;
}

// example 2.

void fun(int cnt, const char *c)
{
    std::unique_lock<std::mutex> lock(m, std::defer_lock); // Does not call lock on mutex m, because used defer_lock.
    m.lock();                                              // But when we will have to explicitly tell to lock  when ever we want to lock mutex m.
    for (int i = 0; i < cnt; i++)
    {
        std::cout << c << " " << buffer++ << std::endl;
    }
};