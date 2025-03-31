#include <iostream>
#include <complex>


int main(){
    int n;
    std::cout<<"Unesite broj elemenata: ";
    std::cin>>n;
    std::complex<double> suma = 0;
    for(int i = 0; i<n; i++){
        std::cout<<"Z_"<<i+1<<"= ";
        std::complex<double>z;
        std::cin>>z;
        suma+=1./z;
    }
    std::cout<<"\nPralelna veza ovih elemanta ima impedansu Z_ = "<<1./suma<<".\n";
}