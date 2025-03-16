#include <iostream>
using namespace std;

double UnesiBroj(){
    cout<<"Unesite broj: "<<endl;
    double tmp;
    for(;;){
        cin>>tmp;
        if(!cin){
            cout<<"Neispravan unos. Molimo, pokušajte ponovo.”"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }else return tmp;
    }
}


int main(){
    double a,b,c;
    a = UnesiBroj();
    b = UnesiBroj();
    c = UnesiBroj();
    if(a == 0) cout<<"Nema rjesenja nije moguce dijeljenje sa nulom!!!";
    else cout<<"Rjesenje je: "<<(c-b)/a;
}