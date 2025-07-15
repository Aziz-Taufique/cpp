#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    int *ptr;         // wind pointer.
    int *ptrn = NULL; // NUll pointer
    int *p1 = NULL;
    int *p2 = 0;
    int *p3 = '\0';

    cout << x << endl;
    cout << ptr << " " << *ptr << endl;
    cout << ptrn << " " << p1 << " " << p2 << " " << p3 << endl;

    // 0 is mostly a special reserved memory address in many os.
    // runtime error might occur on derefrencing null pointer

    // cout<<*ptrn<<endl; runtime error,  segmentation fault.

    return 0;
}