// std::try_lock()

// 1. std::try_lock() is different from mutex::try_lock().
// 2. std::try_lock() tries to lock all the lockable objects passed in it one by one in given order.
// 3. SYNTAX: std::try_lock(m1, m2, m3, m4..., mn);
// 4. The actual use of std::try_lock() function is, it can try to lock multiple mutex objects at the same time.
// 4. on success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
// 5. if it fails to lock any of the mutex then it will release all the mutex it locked before.
// 6. If a call to try_lock results in an exception, unlock is called for any locked objects before rethrowing.

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int X = 0, Y = 0;
std::mutex m1, m2;

void doSomeWorkForSecond(int sec)
{
    std::this_thread::sleep_for(std::chrono::seconds(sec));
};

void incrementXY(int &XorY, std::mutex &m, const char *desc)
{
    for (int i = 0; i < 5; i++)
    {
        m.lock();
        XorY++;
        std::cout << desc << XorY << std::endl;
        m.unlock();
        doSomeWorkForSecond(1);
    }
};

void consumeXY()
{
    int useCount = 5;
    int XplusY = 0;
    while (1)
    {
        int lockResult = std::try_lock(m1, m2);
        if (lockResult == -1)
        {
            if (X != 0 && Y != 0)
            {
                useCount++;
                XplusY += X + Y;
                X = 0;
                Y = 0;
                std::cout << "XplusY " << XplusY << std::endl;
            }
            m1.unlock();
            m2.unlock();
            if (useCount == 0)
                break;
        }
    }
};

int main()
{
    std::thread t1(incrementXY, std::ref(X), std::ref(m1), "X ");
    std::thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y ");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
