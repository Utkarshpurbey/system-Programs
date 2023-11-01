#include<iostream>
using namespace std;

int sumFunctional(int n){
    if(n == 0)
        return 0;
    return n+sumFunctional(n-1);
}

int main()
{
    cout<<sumFunctional(5);
    return 0;
}