#include <iostream>
#include <vector>
#include <cmath>

// bukvalno su nam identicne izvedbe
void DodajSuprotne(std::vector<int> &v){
    for(int i = 0; i<v.size(); i+=2)
        v.insert(v.begin()+i+1, -v[i]);
}

int main(){
    std::cout<<"Koliko ima brojeva: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite brojeve: ";
    std::vector<int> v(n);
    for(int &el : v) std::cin>>el;
    std::cout<<"Brojevi nakon dodavanja: ";
    DodajSuprotne(v);
    for(int &el : v) std::cout<<el<<" ";
}
