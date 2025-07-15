#include <bits/stdc++.h>
using namespace std;

void process(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << endl;
    }

    *(arr + 1) = 100;
}
int main()
{
    int arr[3] = {2, 3, 4};
    int n = 3;

    cout << *(arr + 1) << endl;
    process(arr, n);
    cout << *(arr + 1) << endl;
    return 0;
}