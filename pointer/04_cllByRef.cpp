#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    // cout << a << " " << b << endl;
}

int main()
{
    int a = 29;
    int b = 30;
    cout << a << " " << b << endl;
    int *p1 = &a;
    int *p2 = &b;
    swap(p1, p2);
    cout << a << " " << b << endl;
    return 0;
}