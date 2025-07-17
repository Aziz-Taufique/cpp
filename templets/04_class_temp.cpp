#include <iostream>
#include <string>

template <class T>
class MyClass
{
private:
    T data;

public:
    MyClass(T val)
    {
        data = val;
    }

    void show()
    {
        std::cout << data << std::endl;
    }
};

int main()
{

    MyClass<int> obj1(10); // integer
    obj1.show();

    MyClass<double> obj2(32.232); // double
    obj2.show();

    MyClass<std::string> obj3("hehe"); // string
    obj3.show();
    return 0;
}