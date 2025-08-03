#include <iostream>
#include <thread>

// 2. Lambda function.
int main()
{
    int sum = 0;

    // we can directly inject lambda at thread creation time.
    auto fun = [&](int x)
    {
        while (x-- > 0)
        {
            sum += x;
            std::cout << x << std::endl;
        }
        std::cout << sum << std::endl;
    };

    std::thread t(fun, 10);
    t.join();
    return 0;
}