// How to return an array from function in C and C++;
// ans:-
// 1. create array in heap.
// 2. use static keyword.

#include <iostream>
// this function give error because arr in local variable in stack and it destroy when fn works finish.
// int *fn()
// {
//     int arr[3] = {1, 2, 3};
//     return arr;
// }

// it works , create array in head memory.
// int *fn()
// {
//     int *arr = new int[3];
//     arr[0] = 1;
//     arr[1] = 2;
//     arr[2] = 3;
//     return arr;
// }

// it also work by using static keyword,
int *fn()
{
    static int arr[3] = {1, 2, 3};
    return arr;
}

int main()
{
    int *arr = fn();
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[2] << std::endl;

    return 0;
}