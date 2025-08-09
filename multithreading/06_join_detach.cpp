// Topic use of join(), detach() and joinable() in thread in cpp;

// JOIN NOTES.
// 1. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 2. Double join will result into program termination.
// 3. If needed we should check thread is joinable before joining. (using joinable() fuction).

// DETACH NOTES.
// 1. This is used to detach newly create thread from the parent thread.
// 2. Always check before detaching a thread that it is joinable otherwise we may end up doulbe detaching and double detach() will result into program terminaltion.
// 3. If we have detached thread and main function is returning then the detached thread execution is suspended.

// NOTES:
// Either join() or detach() should be called on thered object, otherwise during thread object's destructor it will terminate the program. Because inside destructor it checks if thred is still joinable? if yes then it terminates the program.

#include <iostream>
#include <chrono>
#include <thread>

void run(int cnt)
{
    while (cnt--)
    {
        std::cout << cnt << "Aziz" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Thread finished." << std::endl;
}

int main()
{
    std::thread t(run, 10);
    std::cout << "main()" << std::endl;
    // t.join();
    // t.join(); // terminate program

    // if (t.joinable())
    // {
    //     t.join();
    // }

    t.detach();
    if (t.joinable())
    {
        t.detach();
    }
    std::cout << "after main()" << std::endl;

    // std::this_thread::sleep_for(std::chrono::seconds(3)); // sleep main thread.
    return 0;
}