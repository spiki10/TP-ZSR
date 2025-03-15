#include <iostream>
#include <cmath>

int IzbaciNule(int n){
    int output = 0,exp = 1;
    while(n!=0){
        int digit = n%10;
        if(digit!=0){
            output += digit*exp;
            exp*=10;
        }
        n/=10;
    }
    return output;
}


int main(){
    int n,var;
    std::cout<<"Unsite broj: ";
    std::cin>>n;
    var = IzbaciNule(n);
    std::cout<<var;


    return 0;
}