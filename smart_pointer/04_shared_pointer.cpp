#include <iostream>
#include <memory>

int main()
{

    std::shared_ptr<int> p1(new int(10));
    std::shared_ptr<int> p2;
    p2 = p1; // both points same.
    // counts,
    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;

    // address
    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;

    p1.reset(); // p1 points to null.

    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;

    std::cout << p1.get() << std::endl;
    std::cout << p2.get() << std::endl;

    return 0;
}