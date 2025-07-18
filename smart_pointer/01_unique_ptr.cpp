#include <iostream>
#include <memory>

template <typename T>
class Demo
{
private:
    T *ptr;

public:
    Demo(T *val) : ptr(val)
    {
        std::cout << "ctor called" << std::endl;
    };

    ~Demo()
    {
        std::cout << "dtro clalled" << std::endl;
        delete ptr;
    }
};

int main()
{
    Demo<int> O1(new int(10));
    return 0;
}