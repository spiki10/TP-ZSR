#include <iostream>
#include <vector>

typedef std::vector<int> vektor;

bool trocifren(vektor &v){
    for(int el : v)
        if(el>=100 && el<=999) 
            return true;
    return false;
}


int main(){
    int n;
    std::cout<<"Unesite velicinu vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    vektor v(n);
    for(int i = 0; i < n; i++) std::cin>>v[i];
    trocifren(v) ? std::cout<<"Ima trocifren broj!!!" : std::cout<<"Nema trocifren broj";
}