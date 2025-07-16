#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i < sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void printPrime(int n)
{
    if (isPrime(n))
        std::cout << n << " " << "Yes" << std::endl;
    else
        std::cout << n << " " << "No" << std::endl;
}

int main()
{

    std::vector<int> v1 = {21, 32, 43, 35, 45, 11, 33, 44, 66};

    // printPrime(8);

    for_each(v1.begin(), v1.end(), printPrime);
    return 0;
}