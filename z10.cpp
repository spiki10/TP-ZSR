#include <iostream>
#include <cctype>
#include <string>

void Transformacija(std::string &s) {
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) s[i] = std::toupper(s[i]);
        if(s[i] == ' ' &&
            (i == 0 || i == s.length() - 1 || s[i - 1] == ' ' || s[i + 1] == ' ')) {
            s.erase(i, 1);
        i--;
            }
    }
}



int main(){
    std::cout<<"Unesite string: ";
    std::striung s;
    std::getline(std::cin, s);
    Transformacija(s);
    std::cout<<"String nakon transformacije: "<<s;
}
