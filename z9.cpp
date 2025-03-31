#include <iostream>
#include <string>
#include <cctype>

bool isSamoglasnik(char &c){
    char maloSlovo = std::tolower(c);
    return maloSlovo == 'a' || maloSlovo == 'e' || maloSlovo == 'i' || maloSlovo == 'o' || maloSlovo == 'u';
}


void Ruraliziraj1(std::string &s){
    for(int i = 0; i<s.length(); i++)
        if(isSamoglasnik(s[i]))
            s.insert(s.begin() + (++i), std::tolower(s[i])); // nije preporuceno ko fold ovo za radit od strane gpta mada mislim da izvodi treba pretrazit Juriceve materijale
}

// Juriceva izvedba najbolja po mom svidjanju
void Ruraliziraj(std::string &s) {
    for(int i = 0; i < s.length(); i++)
        if(std::string("aeiouAEIOU").find(s[i]) != std::string::npos) {
            s.insert(s.begin() + i + 1, std::tolower(s[i]));
            i++;
        }
}

// cool je funkcija find za stringove




int main(){
    std::string s;
    std::cout<<"Unesite receinuc: ";
    std::getline(std::cin, s);
    Ruraliziraj(s);
    std::cout<<"Modificirana recenica: "<<s;
}
