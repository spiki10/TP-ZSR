#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

complex<double> Moiever(double x, double n){
    complex<double> output = polar(1.0,x); // ovo prima parametre r i teta r = mod(kompleksni broj)
    auto help = output;
    for(int i = 1; i < int(n); i++)
        output*=help;
    return output;
}

int main(){
    double x,n;
    cout<<"Unesite x i n: ";
    cin>>x>>n;
    cout<<"Koristeci formulu: cos(n*x) + i * sin(n*x) = "<<polar(1.,x*n)
        <<"\nKoristeci komplekne brojeve direktno: "<<Moiever(x,n);
}

