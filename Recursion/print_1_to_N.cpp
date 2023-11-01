#include<iostream>
using namespace std;

void linear_print(int n){
    if(n==0)
        return;
    linear_print(n-1);
    cout<<n<<" ";
}

int main(){
    linear_print(5);
}