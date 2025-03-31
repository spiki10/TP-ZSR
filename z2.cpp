#include <iostream>
#include <complex>
using namespace std;


int main(){
    int n;
    cout<<"Unesite broj elmenata: ";
    cin>>n;
    complex<double> suma=0;
    for(int i = 1;i<=n;i++){
        double realni,imaginarni;
        cout<<"\nR"<<i<<"= ";
        cin>>realni;
        cout<<"X"<<i<<" = ";
        cin>>imaginarni;
        suma+=1./complex<double>(realni,imaginarni);
    }
    suma = 1./suma;
    cout<<"Paralelna veza ovih elemenata ima R = "<<suma.real()<<" i X = "<<suma.imag();
}