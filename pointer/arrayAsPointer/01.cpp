#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[3] = {32, 43, 55};
    int *ptr = arr;
    cout << ptr << " " << arr << endl;
    cout << *ptr << " " << *arr << endl;
    cout << arr + 1 << " " << *(arr + 1) << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << arr << " " << *(arr + i) << endl;
    }
    return 0;
}