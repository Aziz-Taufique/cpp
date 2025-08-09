// TOPIC: std::mutex::try_lock().

// 1. try_lock() tries to lock the mutex. Returns immediately. On successful lock acquisition returns true otherwise returns false.
// 2. If try_lock() is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking.
// 3. If try_lock() is called again by the same thread which owns the mutex, the behavior is undefined.
// It is a dead lock situation with undefined behaviour. (if you want to be able to lock the same mutex by same thread more than one time then go for recursive_mutex).

// THERE ARE SO MANY try_lock functio
/*
3. Complete List of try_lock Functions
Function	                                                Type	Available Since
bool mutex::try_lock()	                                    Member	C++11
bool recursive_mutex::try_lock()	                        Member	C++11
bool timed_mutex::try_lock()	                            Member	C++11
bool recursive_timed_mutex::try_lock()	                    Member	C++11
bool shared_mutex::try_lock()	                            Member	C++17
bool shared_mutex::try_lock_shared()	                    Member	C++17
bool shared_timed_mutex::try_lock()	                        Member	C++14
bool shared_timed_mutex::try_lock_shared()	                Member	C++14
bool timed_mutex::try_lock_for(duration)	                Member	C++11
bool timed_mutex::try_lock_until(time_point)	            Member	C++11
bool recursive_timed_mutex::try_lock_for(duration)	        Member	C++11
bool recursive_timed_mutex::try_lock_until(time_point)	    Member	C++11
bool shared_timed_mutex::try_lock_for(duration)	            Member	C++14
bool shared_timed_mutex::try_lock_until(time_point)	        Member	C++14
bool shared_timed_mutex::try_lock_shared_for(duration)	    Member	C++14
bool shared_timed_mutex::try_lock_shared_until(time_point)	Member	C++14
int std::try_lock(L1&, L2&, ...)	                        Non-member	C++11
*/

#include <iostream>
#include <thread>
#include <mutex>

int cnt = 0;
std::mutex mtx;

void inc()
{
    for (int i = 0; i < 100000; i++)
    {
        if (mtx.try_lock())
        {
            cnt++;
            mtx.unlock();
        }
    }
};

int main()
{
    std::thread t1(inc);
    std::thread t2(inc);

    t1.join();
    t2.join();
    std::cout << cnt << std::endl;
    return 0;
}