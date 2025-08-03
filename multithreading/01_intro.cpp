#include <iostream>
#include <chrono>
#include <algorithm>
#include <thread>
#include <mutex>

long long evenSum = 0;
long long oddSum = 0;
std::mutex mtx;
void findOdd(long long start, long long end)
{
    long long localSum = 0;
    for (long long i = start; i <= end; i++)
    {
        if (i % 2 != 0)
            localSum += i;
    }
    std::lock_guard<std::mutex> lock(mtx);
    oddSum += localSum;
};

void findEven(long long start, long long end)
{
    long long localSum = 0;
    for (long long i = start; i <= end; i++)
    {
        if (i % 2 == 0)
            localSum += i;
    }
    std::lock_guard<std::mutex> lock(mtx);
    evenSum += localSum;
}
int main()
{
    long long start = 0;
    long long end = 1900000000;

    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread t1(findOdd, start, end);
    std::thread t2(findEven, start, end);

    t1.join();
    t2.join();

    // findOdd(start, end);
    // findEven(start, end);

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    std::cout << "EvenSum is " << evenSum << std::endl;
    std::cout << "OddSum is " << oddSum << std::endl;

    std::cout << "Total Duration  " << duration.count() / 1000000 << " second" << std::endl;
}