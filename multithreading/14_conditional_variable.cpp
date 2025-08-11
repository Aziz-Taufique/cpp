// TOPIC :- conditional variable.
// IMPORTANT POINT: coditional variable are used for two purpose.
// A. Notify other threads.
// B. Waiting for some conditions.

// 1. Conditional variable allows running threads to wait on some conditions and once those condidtions are met the waiting thread is notified useing :
//   a. notify_one();
//   b. notify_all();
// 2. You need mutex to use condition variable.
// 3. If some thread want to wait on some condition then it has to do these things:
// a. Acquired the mutex lock using std::unique_lock<std::mutex> lock(m);.
// b. Execute wait, wait_for or wait_until. The wait operations atomically release the mutex and suspend the execution of the thread.
// c. When the condition variable is notified the thread is awakened, and the mutex is atomically reacquired. The thread should then check the condition and resume waiting if the wake up was spurious.

// NOTE:
// 1. Condition variables are used to sysnchronize two or more threads.
// w. Best use case of condition variable is producer/consumer problem.

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable cv;
std::mutex m;
int balance = 0;

void addMoney(double amount)
{
    std::lock_guard<std::mutex> lg(m);
    balance += amount;
    std::cout << "Amount added current balance is " << balance << std::endl;
    cv.notify_one();
}

void withdrowMoney(double amount)
{
    std::unique_lock<std::mutex> ul(m);
    cv.wait(ul, []
            { return (balance != 0) ? true : false; });
    if (balance >= amount)
    {
        balance -= amount;
        std::cout << "Amount deducterd " << amount << std::endl;
    }
    else
    {
        std::cout << "Amount can't deducted current balance is less" << std::endl;
    }
    std::cout << "Current balance is " << balance << std::endl;
}

int main()
{
    std::thread t1(withdrowMoney, 500);
    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();

    return 0;
}