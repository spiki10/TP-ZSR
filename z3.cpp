#include <iostream>
#include <iomanip>
#include <cmath>


using std::cout, std::cin, std::endl;

int main(){
    int a,b;
    cout<<"Unesite pocetnu i krajnju vrijednost: ";
    cin>>a>>b;
    cout<<"\n"
    << "+---------+----------+----------+-----------+\n"
    << "| Brojevi | Kvadrati | Korijeni | Logaritmi |\n"
    << "+---------+----------+----------+-----------+\n";
    for(int i = a;i<=b;i++){
        cout<<"| "<<std::left<<std::setw(8)<<i<<"|"
            <<std::right<<std::setw(9)<<i*i<<" |"
            <<std::right<<std::setw(9)<<std::fixed<<std::setprecision(3)<<sqrt(i)<<" |"
            <<std::right<<std::setw(10)<<std::setprecision(5)<<log(i)<<" |\n";
    }
    cout << "+---------+----------+----------+-----------+\n";

}