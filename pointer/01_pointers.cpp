#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 10;
    float y = 3.14;
    cout << "Address of x is : " << &x << " , Address of y is : " << &y << endl;
    int *ptr = &x;    // store address of int valriable.
    float *ptr2 = &y; // store address of float variable.
    cout << "address stored inside prt is : " << ptr << endl;
    cout << ptr2 << endl;

    // Dereference operator:-
    cout << "value present at the address stored in ptr is : " << *ptr << endl; // print actual value
    cout << *ptr2 << endl;

    //-------------------------------

    x = 40; // the bucked x is updated the value from 10 to 40 but ptr is still pointing to same bucket
            // now if we dereference ptr, we will get 40.
    cout << x << endl;
    cout << *ptr << endl;

    *ptr = 50;
    cout << x << endl;
    cout << *ptr << endl;

    int val = *ptr;
    cout << val << endl;

    ///////////////////

    int *ptr3;
    cout << ptr3 << endl;

    int marks = 99;
    ptr3 = &marks;

    cout << ptr3 << endl;

    return 0;
}