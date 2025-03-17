#include <iostream>
using namespace std;

void nr(){cout<<endl;}
// nemam pojma kako se radi uradit cu ga poslije nekad
void crtaj(int n){
}


int main(){
    int n;
    cout<<"Unesite n: ";
    for(;;){
        cin>>n;
        if(n<5 || n>24)
            cout<<"Neispravan unos!";
        else
            break;
    }
    crtaj(n);
}