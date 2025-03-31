#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::string IzvrniRedoslijedRijeci(std::string s) {
    std::string izvrnuti;
    for(int i = 0; i < s.length(); i++)
        if(s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            std::string rijec;
            while(i < s.length() && s[i] != ' ') rijec += s[i++];
            if(izvrnuti == "") izvrnuti = rijec;
            else izvrnuti = rijec + ' ' + izvrnuti;
        }
        return izvrnuti;
}

// meni draze od Jurica
std::string IzvrniRedoslijedRijeci(std::string s) {
    std::string izvrnuti;
    for(int i = 0; i < s.length(); i++) {
        while(i < s.length() && s[i] == ' ') i++;
        std::string rijec;
        while(i < s.length() && s[i] != ' ') rijec += s[i++];
        if(rijec == "") izvrnuti = rijec;
        else if(rijec != "") izvrnuti = rijec + ' ' + izvrnuti;
    }
    return izvrnuti;
}

int main() {
    std::string s;
    std::cout << "Unesite string: ";
    std::getline(std::cin, s);
    std::cout << "Izvrnuti string: " << IzvrniRedoslijedRijeci(s);
    return 0;
}
