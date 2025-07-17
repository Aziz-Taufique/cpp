#include <iostream>
#include <vector>

class Array
{
private:
    int arr[10] = {0};
    int size;

public:
    Array()
    {
        size = 10;
    }

    void insertELement(int index, int val)
    {
        if (index >= 0 && index < 10)
        {
            if (arr[index] == 0)
                arr[index] = val;
        }
        else
        {
            std::cout << "Invalid Index" << std::endl;
        }
    }

    void getElement(int index)
    {
        std::cout << arr[index] << std::endl;
    }
};

int main()
{
    Array a1;
    a1.insertELement(0, 2);
    a1.insertELement(1, 4);
    a1.getElement(0);
    a1.getElement(1);
    a1.getElement(2);

    return 0;
}