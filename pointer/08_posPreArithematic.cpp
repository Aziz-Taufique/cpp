#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6] = {1, 44, 3, 23, 35, 46};
    int *ptr = &arr[0];
    cout << ptr << " " << *ptr << endl;
    cout << ptr + 1 << " " << *(ptr + 1) << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << *(ptr + i) << endl;
    }

    cout << *ptr++ << " " << *ptr << endl;
    cout << arr[0] << " " << arr[1] << endl;

    int newArr[2] = {3, 44};
    int *ptrn = &newArr[0];
    cout << (*ptrn)++ << endl;
    cout << newArr[0] << " " << newArr[1] << endl;
    return 0;
}