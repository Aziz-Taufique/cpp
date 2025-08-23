// what is the difference between reference and pointer in cpp;

#include <iostream>

int main()
{
    int i = 10;

    int &r = i;  // reference, address of i is copied in r.
    int *p = &i; // pointer

    int val = 80;
    r = val; // i will becore 80;

    p = &val; // will store add of val.
    *p = val; // 60 will assign to val.

    std::cout << &i << " " << &r << std::endl; // print same address.
    std::cout << &p << std::endl;
    return 0;
}

// Memory address in not given to references.
// Reassignment is not possible with reference.
// null value :- you cannot initialize null to ref and you cannot make ref to empty and initilize it later.
// Arithematic operations :- are not provided for references.
// Indirection:- is not given in references.