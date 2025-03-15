#include <iostream>
#include <iomanip>
using std::cin, std::cout, std::endl;
// kako se trazi zaokruzivanje decimala onda cemo samo koristit cjelobrojne tipove da se spasimo zaokruzivanja
int main(){
    int G,p;
    cout<<"Unesite galvnicu G: "; 
    cin>>G; cin.ignore(100000,'\n');
    cout<<"Unesite kamtnu stopu p: ";
    cin>>p; cin.ignore(10000,'\n');
    int K = G*p/100;
    int S = G+K;
    // za ispis nam treba iomanip radi poravnanja i postavljanje sirine mada i mozemo sa manipulacijom izlazno toka (cout) postici nesto slicno
    // nejasan je broj razmaka poslije rijeci a prije ispisa broja sa sirinom broja 6 tako da to je vjerovatno ostavljeno na nama da napisemo da lici samo na nesto
    cout<<"Glavnica:      "<<std::setw(6)<<std::right<<G
        <<"\nKamatna stopa: "<<std::setw(6)<<std::right<<p
        <<"\nKamate:        "<<std::setw(6)<<std::right<<K
        <<"\nNova svota:    "<<std::setw(6)<<std::right<<S;
    
}