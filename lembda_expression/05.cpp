#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{

    std::vector<int> v1 = {21, 32, 43};

    for_each(v1.begin(), v1.end(), [](int &x)
             { x = x * 2; });

    for (auto it : v1)
    {
        std::cout << it << std::endl;
    }
    return 0;
}