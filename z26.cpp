#include <iostream>
#include <vector>
using namespace std;

bool isPet(int n){
    if(n<0) return false;
    for(int i = 1; i<=n; i++){
        int proizvod = 1;
        for(int j = 0; j<5; j++)
            proizvod *= (i+j);
        if(proizvod == n) return true;
        if(proizvod>n) break;
    }
    return false;
}


vector<bool> istina(vector<int> &v){
    vector<bool> output(v.size(),false);
    for(int i = 0; i<v.size(); i++){
        if(isPet(v[i]))
            output[i] = true;
    }
    return output;
}


int main(){
    int n;
    cout<<"Unesite velicinu vektora: ";
    cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    vector<int> v(n);
    for(int &el : v) cin>>el;
    cout<<"Izlazni vektor funkcije je: ";
    for(const bool &el : istina(v)) cout<<boolalpha<<el<<" ";
}