#include <iostream>
#include <vector>
#include <array>
#include <cmath>


int digRoot(int n){
    if(n<0) n=-n;
    while(true){
        int suma = 0;
        while(n!=0){
            suma+=n%10;
            n/=10;
        }
        if(suma<10) return suma;
        n = suma;
    }
    return 0;
}


std::array<std::vector<int>,10> Razvrstaj(const std::vector<int> &v){
    std::array<std::vector<int>,10> output;
    for(int el : v)
        output[digRoot(el)].push_back(el);
    return output;
}



int main(){
    int n;
    std::cout<<"Koliko ima brojeva: ";
    std::cin>>n;
    std::cout<<"Unesite brojeve: ";
    std::vector<int> v(n);
    for(int &el : v) std::cin>>el;
    auto result = Razvrstaj(v);
    for(int i = 0; i<10; i++){
        std::cout<<"Digitalni korjien "<<i<<": ";
        for(int el : result[i]) std::cout<<el<<" ";
        std::cout<<std::endl;
    }
}
