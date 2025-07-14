#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;

    int *ptrx = &x;
    int *ptry = &y;

    int result; // declear result so it has garbage value;
    cout << result << endl;

    int *ptr_result = &result;
    // *ptr_result = 100;

    // cout << result << endl;
    // cout << *ptr_result << endl;

    *ptr_result = *ptrx + *ptry;
    cout << *ptr_result << " " << result << endl;

    /*
    -> *ptrx -> 10
    -> *ptry -> 20
    -> *ptrx + *ptry -> 30;
    -> *ptr_result = 30; we stored 30 on the address stored in *ptr_result.
    -> result -> 30
    */
    return 0;
}