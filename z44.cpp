#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> vektor;
using namespace std;

enum class Kriterij {Veca, Manja, Jednaka};


int brCifra(int n){
    return floor(log10(n))+1;
}

int otpotrnost(int n){
    if(n<0) n = -n;
    if(n==0) return 0;
    int output = 0;
    while(brCifra(n)!=1 && n!=0){ // mogao je i uslov n<10
        int helper = n, prolaz = 1;
        while(helper!=0){
            prolaz *= helper%10;
            helper/=10;
        }
        n = prolaz;
        output++;
    }
    return output;
}

// DRUGA MALO BOLJA IZVEDBA ZA RACUNANJE OTPORNOSTI 
int otpornost2(int n){
    long long n,m,v(0),d(1);
    m=n;
    while (1){
        while (m!=0){ 
            d=d*(m%10); 
            m=m/10;
        } 
        v++; 
        if (d<10) break; 
        else {
            m=d; 
            d=1;
        }
    }
    return v;
}

vektor IBSZMU(vektor &v, int var, Kriterij uslov){
    vektor output;
    for(int el : v){
        switch (uslov)
        {
        case Kriterij::Veca:
            if(otpotrnost(el)>var) output.push_back(el);
            break;
        case Kriterij::Jednaka:
            if(otpotrnost(el) == var) output.push_back(el);
            break;
        case Kriterij::Manja:
            if(otpotrnost(el)<var) output.push_back(el);
            break;
        default:
            break;
        }
    }
    return output;
}


int main(){
    vektor v;
    for(;;){
        int n;
        std::cin>>n;
        if(!std::cin) break;
        v.push_back(n);
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    
    auto prvi = IBSZMU(v,0,Kriterij::Veca);
    auto drugi = IBSZMU(v,3,Kriterij::Jednaka);
    auto treci = IBSZMU(v,3,Kriterij::Manja);
    std::cout<<"Za veca od 1 vektor: ";
    for(int el : prvi) std::cout<<otpotrnost(el)<<" ";
    std::cout<<"\nZa jednaka 1 vektor: ";
    for(int el : drugi) std::cout<<el<<" ";
    std::cout<<"\nZa manja od 1: ";
    for(int el : treci) std::cout<<el<<" ";
}