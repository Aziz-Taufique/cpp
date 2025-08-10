// TOPIC: Recursive mutex. (std::recursive_mutex)

// NOTES:-
// 1. If thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1, now as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue.

// 2. But if T1 have aquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock it 10 times otherwise no other thread will be able to lock mutex m1.
// It means recursive_mutex keeps count how many times it was locked so that many times it should be unlocked.
// 3. How many time we can lock recursivce_mutex is not defined but when that number reaches and if we were calling lock() it will return std;:system_error OR if we were calling try_lock() then it will return false.

// BOTTOM LINE:
// 1. It is similar to mutex but have extra facitiltity that it can be locked multiple time by same thread.
// 2. If we can avoid recursive_mutex then we should because it brings overhead to the system.
// 3. If can be used in loop also.

// EXAMPLE 1:-

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::recursive_mutex m;
int buffer = 0;

void recursion(char c, int cnt)
{
    if (cnt < 0)
        return;

    m.lock();
    std::cout << c << " " << buffer++ << std::endl;
    recursion(c, --cnt);
    m.unlock();
    std::cout << "unlock by thread " << c << std::endl;
}
int main()
{
    std::thread t1(recursion, '0', 10);
    std::thread t2(recursion, '1', 10);

    t1.join();
    t2.join();
    return 0;
}

// EXAMPLE 2 :- WITH LOOP.

int main()
{
    for (int i = 0; i < 5; i++)
    {
        m.lock();
        std::cout << "locked" << i << std::endl;
    }

    for (int i = 0; i < 5; i++)
    {
        m.unlock();
        std::cout << "unlocked" << i << std::endl;
    }
    return 0;
}