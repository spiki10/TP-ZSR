#include <iostream>
#include <cmath>
using namespace std;


int main(){
    double counter = 0,n,totalA = 0,totalG = 1;
    cout<<"Unesite elemente: ";
    
    for(;;){
        cin>>n;
        if(n==0) break;
        totalA+=n;
        totalG *= n;
        counter++;
    }
    cout<<"Aritmeticka sredina: "<< totalA/counter
        <<"\nGeometrijska sredina: "<< pow(totalG,1./counter);
}