#include <iostream>
#include <vector>
typedef std::vector<int> vektor;
int sumaCifara(int n){
    if(n<0) n*=(-1);
    int suma = 0;
    while(n!=0){
        suma+=n%10;
        n/=10;
    }
    return suma;
}

vektor sumeCifara(vektor &v){
    vektor output;
    for(int i = 0; i<v.size(); i++)
        output.push_back(sumaCifara(v[i]));
    return output;
}

int main(){
    int size;
    std::cout<<"Unsite velicinu vektora: ";
    std::cin>>size;
    std::cout<<"Unesite elemente vektora: ";
    vektor v(size);
    for(int i = 0; i<size; i++) std::cin>>v[i];
    for(int el : sumeCifara(v)) std::cout<<el<<" ";
}

