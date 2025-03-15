#include <iostream>
#include <cmath>
using std::cout,std::cin;
// mrsko mi je clean up kodove al trebalo bi da je svakako citko


int main(){
    double a,b,c;
    cout<<"Unesite koefiicjente a,b,c:\n";
    cin>>a;
    cin.ignore(1000000,'\n');
    cin>>b;
    cin.ignore(1000000,'\n');
    cin>>c;
    cin.ignore(1000000,'\n');
    // Predvidite i mogućnost postojanja kompleksnih rješenja, koje ćete ispisivati kao uređene parove realnih brojeva
    // ovo govori da se koristi std::complex ali nije se radilo na ovom predavanju to pa cemo morati to rucno raditi
    double d  = b*b - 4 * a * c;
    if(a==b && b==c && c==0){
        cout<<"Ovo je identicki jednak izraz"; return 1;
    }else if(a==0 && b!=0){
        cout<<"Ovo ima linearne rjesenje koje glasi: "<<-c/b; return 1;
    }else if(a==b && b==0 && c!=0){
        cout<<"Ovo nije kvadratna jednacina!"; return 1;
    }
    // rjesenje nek se uzme po volji ja mislim da je bilo ciljano ovo iznad sa koeficijentima

    if(d>0){
        // imamo dva rjesenja
        double x1 = (-b + sqrt(d))/(2.*a);
        double x2 = (-b - sqrt(d))/(2.*a);
        cout<<"Rjesenja kvadratne jednacine su: \nx1 = "<<x1<<"\nx2 = "<<x2;
    }else if(d==0){
        //imamo jedno duplo rjesenje
        // x = -b+-sqrt(d)/2a u ovom slucaju samo je jedan znak dovoljan
        cout<<"Rjesenja kvadratne jednacine je jedinstveno i iznosi: "<<(-b/(2*a));
    }else{
        // imamo imaginarna rjesenja
        double var1 = (-b)/(2.*a);
        double var2 = abs((abs(sqrt(d))/(2.*a)));
        cout<<"Rjesenja kvadratne jednacine su kompleksna i ona su: \nx1 = ("<<var1<<", "<<var2<<")\nx2 = ("<<var1<<", -"<<var2<<")";

    }
}