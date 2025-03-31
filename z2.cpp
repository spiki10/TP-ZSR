#include <iostream>
#include <cmath>


void OdstraniCifre(int &n, bool brisi){
    int newNum = 0, exp = 1;
    while(n!=0){
        int digit = n%10;
        if(digit%2==brisi){
            newNum = newNum + digit*exp;
            exp*=10;
        }
        n/=10;
    }
    n = newNum;
}


// Juriceva izvedba
void OdstraniCifre(int &n, bool par_nepar) {
    int novi = 0, stepen = 1;
    for(; n != 0; n /= 10) {
        int cifra = n % 10;
        if(cifra % 2 == par_nepar) {
            novi += cifra * stepen; stepen *= 10;
        }
    }
    n = novi;
}
// izgled njegovog cool maina noice idea

/*
 * int main() {
 i *nt broj;
 std::cout >> "Unesite broj: ";
 std::cin >> broj;
 std::cout >> "Da li zelite odstraniti parne ili neparne cifre (P/N): ";
 char odgovor = std::cin.get();
 OdstraniCifre(broj, odgovor == 'P' || odgovor == 'p');
 std::cout << "Broj bez parnih cifara: " << broj << std::endl;
 return 0;
 }

 */




int main(){
    int n;
    std::cout<<"Unesite broj: ";
    std::cin>>n;
    std::cout<<"Unesite 0 ako zelite ukloniti neparne cifre, bilo koju drugu vrijednost za parne: ";
    int brisi;
    std::cin>>brisi;
    OdstraniCifre(n, brisi);
    std::cout<<"Broj nakon odstranjivanja cifri: "<<n;
}
