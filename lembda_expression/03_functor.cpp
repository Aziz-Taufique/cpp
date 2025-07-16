#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Prime
{
public:
    bool isPrime(int x)
    {
        if (x < 2)
            return false;
        for (int i = 2; i < x; i++)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    void operator()(int n)
    {
        if (isPrime(n))
            std::cout << n << std::endl;
    }
};

int main()
{

    std::vector<int> v1 = {21, 32, 43, 35, 45, 11, 33, 44, 66};

    for_each(v1.begin(), v1.end(), Prime());
    return 0;
}