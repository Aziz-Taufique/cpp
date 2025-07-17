#include <iostream>
#include <vector>

template <class T>
class Array
{
private:
    T arr[10];
    int size;

public:
    Array()
    {
        size = 10;
    }

    void insertELement(int index, T val)
    {
        if (index >= 0 && index < 10)
        {
            arr[index] = val;
        }
        else
        {
            std::cout << "Invalid Index" << std::endl;
        }
    }

    T getElement(int index)
    {
        if (index >= 0 && index < 10)
            return arr[index];
        else
            std::cout << "Invalid index" << std::endl;
    }

    void printArr()
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << "El at index " << i << " " << arr[i] << std::endl;
        }
    }
};

int main()
{
    Array<std::string> a1; // sting obj
    a1.insertELement(0, "ch");
    a1.insertELement(1, "ln");
    std::cout << a1.getElement(0) << std::endl;
    ;
    std::cout << a1.getElement(1) << std::endl;
    std::cout << a1.getElement(2) << std::endl;
    a1.printArr();

    std::cout << "------------------------------" << std::endl;

    Array<int> a2; // int obj
    a2.insertELement(0, 43);
    a2.insertELement(1, 4);
    std::cout << a2.getElement(0) << std::endl;
    std::cout << a2.getElement(1) << std::endl;
    std::cout << a2.getElement(2) << std::endl;
    a2.printArr();

    std::cout << "------------------------------" << std::endl;

    Array<double> a3; // int obj
    a3.insertELement(0, 43.434);
    a3.insertELement(1, 4.43);
    std::cout << a3.getElement(0) << std::endl;
    std::cout << a3.getElement(1) << std::endl;
    std::cout << a3.getElement(2) << std::endl;
    a3.printArr();

    return 0;
}