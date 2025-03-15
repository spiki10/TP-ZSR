#include <iostream>
using std::cin,std::cout;


int main(){
    double n;
    cout<<"Unesite broj: ";
    cin>>n;
    if(!cin){
        cout<<"Uneseni podatak nije broj.";
    }else if(n==int(n) && n>0){
        cout<<"Uneseni podatak je prirodan broj.";
    }else if(n==int(n)){
        cout<<"Uneseni podatak je cijeli broj, ali nije prirodan";
    }else{
        cout<<"Uneseni podatak je realan broj, ali nije cijeli.";
    }
}