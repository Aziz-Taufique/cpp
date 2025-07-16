#include <bits/stdc++.h>
using namespace std;
int printHighestMarks(int **ptr, int *size, int classs)
{
    int maxi = 0;
    for (int i = 0; i < classs; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            if (maxi < ptr[i][j])
                maxi = ptr[i][j];
        }
    }
    return maxi;
}
int main()
{
    int *ptr[3];
    int marks;
    int a[] = {13, 23, 43, 65, 45};
    int b[] = {84, 33, 43, 89};
    int c[] = {77, 87, 88};
    int sizeofPtr[] = {5, 4, 3};

    ptr[0] = a;
    ptr[1] = b;
    ptr[2] = c;

    marks = printHighestMarks(ptr, sizeofPtr, 3);
    cout << "Highest marks is : " << marks << endl;
    return 0;
}