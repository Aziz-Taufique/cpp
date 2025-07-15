#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5] = {32, 43, 34, 23, 22};

    int *ptr = (arr + 2);
    cout << *ptr << endl;

    *(ptr + 1) = 100;
    cout << *(ptr + 1) << endl;
    cout << arr[3] << endl;
    return 0;
}