#include <iostream>
#include <string>
#include <cctype>

bool  isSamoglasnik(char c){
    c = std::tolower(c);
    return c=='o' || c=='a' || c=='i' || c=='u' || c=='e';
}


std::string Satrovacki1(std::string s){
    std::string output = "";
    for(int i = 0; i<s.length();i++){
        output+=s[i];
        if(isSamoglasnik(s[i])){
            char c = std::tolower(s[i]); // ovo mora jer tolower vraca ascii vrijednost karaktera
            output = output + 'p' + c;
        }
    }
    return output;
}

// malo ljepsa izvedba
std::string Satrovacki (const std::string &s){
    std::string output = "";
    for(int i = 0; i<s.length();i++){
        char znak = s[i], mali = std::tolower(s[i]);
        output+=znak;
        if(std::string("aeiou").find(znak)!=std::string::npos)
            output = output + 'p' + znak;
    }
    return output;
}


int main(){
    std::cout<<"Unesite recenicu: ";
    std::string s;
    std::getline(std::cin,s);
    std::cout<<"Satrovacki: "<<Satrovacki(s);
}