// TOPIC:- Lock guard. (std::lock_guard<mutex> lock(m1))

// Notes:-
// 1. It is very light weight wrapper for owning mutex on scoped basic.
// 2. It aquires mutex lock the moment you create the object of lock_gruard.
// 3. It automatically removes the lock while goes out of scope.
// 4. You can not explicitly unlock the lock_gurard.
// 4. You cannot copy lock_graurd.

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1;
int buffer = 0;

void fun(const char *c, int cnt)
{
    std::lock_guard<std::mutex> lock(m1);
    for (auto i = 0; i < cnt; i++)
    {
        std::cout << c << " " << buffer++ << std::endl;
    }
}

int main()
{
    std::thread t1(fun, "t1", 10);
    std::thread t2(fun, "t2", 10);

    t1.join();
    t2.join();
    return 0;
}