#include <iostream>
#include <memory>

class Demo
{
private:
    std::unique_ptr<int> ptr;

public:
    // default cons
    Demo(int val)
    {
        ptr = std::make_unique<int>(val);
    }

    // move cons
    Demo(std::unique_ptr<int> p)
    {
        ptr = std::move(p);
    }

    void show() const
    {
        if (ptr)
            std::cout << "Vaue is : " << *ptr << std::endl;
        else
            std::cout << "Pointer is null\n";
    }
};

int main()
{
    Demo d1(10);
    d1.show();

    std::unique_ptr<int> rawPtr = std::make_unique<int>(33);
    Demo d2(std::move(rawPtr));
    d2.show();

    if (!rawPtr)
        std::cout << "rawPtr is null after move\n";
    return 0;
}