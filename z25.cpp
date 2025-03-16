#include <iostream>
using namespace  std;


int main(){
    cout<<"Unesite broj clanova pseudo niza: ";
    int n;
    cin>>n;
    cout<<"Unesite taj broj elemenata sada: ";
    double sum=0, fractionSum = 0;
    while(n>0){
        double var;
        cin>>var;
        sum += var;
        fractionSum += 1./sum;
        n--;
    }
    cout<<"Rezultat je: "<<fractionSum; 
}