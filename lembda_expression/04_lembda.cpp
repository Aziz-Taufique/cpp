#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{

    std::vector<int> v1 = {21, 32, 43, 35, 45, 11, 33, 44, 66};

    for_each(v1.begin(), v1.end(), [](int &x)
             {
        bool flag = true;
        for(int i=2;i<x;i++){
            if(x%i==0){
                flag = false;
                break;
            } 
        };
        
        if(flag) std::cout<<x<<std::endl; });
    return 0;
}