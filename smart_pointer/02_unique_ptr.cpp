#include <iostream>
#include <memory>

class Demo
{
private:
    std::unique_ptr<int> ptr;

public:
    Demo(int val)
    {
        ptr.reset(new int(val));
        std::cout << "ctor clalled" << std::endl;
    }

    void update(int newVal)
    {
        ptr.reset(new int(newVal));
    }

    void clear()
    {
        ptr.reset();
    }
    void display()
    {
        if (ptr)
            std::cout << "Value is : " << *ptr << std::endl;
        else
            std::cout << "Pointer is null\n";
    }
};

int main()
{

    Demo d(11);
    d.update(22);
    d.clear();
    d.display();

    return 0;
}