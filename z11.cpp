#include <iostream>
#include <string>
#include <exception>

int IzbaciRijec1(std::string &s, int n){
    if(n<0) throw std::range_error("Broj rijeci ne moze da bude negativan!!!");
    int counter = 0, i = 0;
    while(i<s.length()){
        while(s[i] == ' ' && i<s.length()) i++;
        int startIndex = i;
        while(s[i]!=' ' && i<s.length()) i++;
        counter++;
        if(counter == (n-1)){
            s.erase(startIndex,i+1-startIndex);
            counter++;
        }
        i++;
    }
    if(counter!=n) throw std::range_error("Veci indeks nego broj rijeci!!!");
    return counter;
}

// Juriceva puno bolja izvedba
// int std::string IzbaciRijec(std::string &s, int n) {
int i = 0, brojac = 0;
while(i < s.length()) {
    while(i < s.length() && s[i] == ' ') i++;
    if(i != s.length()) {
        brojac++;
        int j = i;
        while(i < s.length() && s[i] != ' ') i++;
        if(brojac == n) s.erase(j, i - j);
    }
}
if(n < 1 || n > brojac) throw std::range_error("Nekorektan redni broj rijeci");
return brojac;
}


int main(){
    std::string s;
    std::cout<<"Unesite string: ";
    std::getline(std::cin,s);
    std::cout<<"Redni broj rijeci: ";
    int n;
    std::cin>>n;
    int a = IzbaciRijec(s,n);
    std::cout<<"Modificirani string: "<<s
             <<"\nBroj rijeci: "<<a;


}
