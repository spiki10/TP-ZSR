#include <iostream>
#include <vector>

bool isPrime(int n){
    if(n<2 || n%2==0 && n!=2 || n%3==0 && n!=3) return false;
    for(int i = 5; i <= n/i; i+=2)
        if(n%i==0) return false;
    return true;
}

std::vector<int> fun(std::vector<int> &v){
    std::vector<int> output;
    for(int el : v)
        if(!isPrime(el)) 
            output.push_back(el);
    return output;
}


int main(){
    int size;
    std::cout<<"Unesite velicinu vektora: ";
    std::cin>>size;
    std::cout<<"Unesite elemente vektora: ";
    std::vector<int> v(size);
    for(int i = 0; i < size; i++) std::cin>>v[i];
    for(int el : fun(v)) std::cout<<el<<" ";
}