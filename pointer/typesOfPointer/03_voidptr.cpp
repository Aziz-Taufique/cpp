#include <iostream>
using namespace std;
int main()
{
    float f = 32.34;
    int x = 10;
    void *ptr = &f;
    ptr = &x;

    // cout << *ptr << endl;  void pointer cannot be derefrence

    int *integerPointer = (int *)ptr;
    cout << *integerPointer << endl;
    return 0;
}