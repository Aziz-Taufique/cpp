#include <iostream>
using namespace std;
int main()
{
    int x = 9;
    int y = 3;

    int *ptr = &x;
    // ptr = 5; we cannot do this as ptr only stores address nothing else.

    // *ptr = &y; we cannot do this as *ptr is integer bucket but &y is address.

    cout << "Address of  x is : " << &x << endl;
    cout << "Address stored insider ptr : " << ptr << endl;
    cout << "Address of ptr itself: " << &ptr << endl; // prints the address of ptr bucket not the address stored in ptr.

    return 0;
}