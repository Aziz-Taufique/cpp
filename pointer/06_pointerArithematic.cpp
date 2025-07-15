#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Increment/decrement:- here increment of a pointer value refer ot shift in memeory loc that pointer is point to.
    // Shift is depend on the size of variable.

    int x = 10;
    double d = 3.5;

    int *ptr = &x;
    double *ptrd = &d;

    cout << ptr << endl;
    cout << (ptr + 1) << endl;

    cout << ptrd << endl;
    cout << (ptrd + 3) << (ptrd - 1) << endl;
    return 0;
}