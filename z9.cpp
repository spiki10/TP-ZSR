#include <iostream>
using std::cout, std::cin;

bool prime(int a){
    if(a%3==0 && a!=3 || a%2==0 && a!=2) return false;
    for(int i = 3;i*i<=a;i+=2){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<"Unesite n: ";
    cin>>n;
    for(int i = 2;i<n;i++){
        if(n%i==0 && prime(i)){
            cout<<i<<" ";
            while(n%i==0) n/=i;
        }
    }
    // uvijek ce nam ostat neka vrijednost za n a ako je ona veca od jedan znaci imamo jos jedna faktor koji je prost i cini neki faktor od n
    if(n>1) cout<<n;
    
}