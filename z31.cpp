#include <iostream>
using namespace std;

double power(int a, int b){
    double output = 1;
    for(int i = 0; i< (b<0 ? -b : b); i++) output *= a;
    return b<0 ? (1./output) : output;
}

int main(){
    int a,b;
    cout<<"Unesite vrijednost a i b: ";
    cin>>a>>b;
    cout<<"Rezultat vrijednosti "<<a<<"^"<<b<<" = "<<power(a,b);

}