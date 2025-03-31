#include <iostream>
#include <vector>
#include <cmath>

void TransformirajVecktor1(std::vector<int> &v){
    for(int i = 0; i<v.size(); i++){
        if(v[i]<=0) {
            v.erase(v.begin()+i);
            i--;
            continue;
        }
        for(int j = 1; j<v[i];j++) v.insert(v.begin()+i,v[i]);
        i+=v[i]-1;
    }
}

// Juriceva izvedba
// dosta slicno samo koristeni principi c++17 standarda
void TransformirajVektor(std::vector<int> &v) {
    for(int i = 0; i < v.size(); i++)
        if(int e = v[i]; e > 0) {
            for(int j = 1; j < e; j++) v.insert(v.begin() + i, e);
            i += e - 1;
        }
        else {
            v.erase(v.begin() + i);
            i--;
        }
}

int main(){
    int n;
    std::cout<<"Koliko ima elemenata: ";
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    std::vector<int> v(n);
    for(int &el : v) std::cin>>el;
    std::cout<<"Transformirani vektor: ";
    TransformirajVecktor(v);
    for(int el : v) std::cout<<el<<" ";
}
