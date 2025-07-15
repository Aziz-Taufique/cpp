#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[3] = {34, 54, 64};

    int (*ptr)[3] = &arr;

    cout << ptr << " " << arr << " " << *ptr << " " << *arr << endl;
    return 0;
}