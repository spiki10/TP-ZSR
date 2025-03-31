#include <iostream>
#include <array>
#include <string>
#include <cctype>

std::array<int, 26> Prebrojavanje1(std::string s) {
    std::array<int, 26> brojaci;
    for(char znak = 'A'; znak < 'Z'; znak++) {
        int brojac = 0;
        for(char c : s)
            if(std::toupper(c) == znak) brojac++;
            brojaci[znak - 'A'] = brojac;
    }
    return brojaci;
}

// meni draza i mojoj ideji najslicnija verzija
std::array<int, 26> Prebrojavanje(std::string s) {
    std::array<int, 26> brojaci{};
    for(char c : s)
        if(std::isalpha(c)) brojaci[std::toupper(c) - 'A']++;
        return brojaci;
}



int main() {
    std::string s;
    std::cout << "Unesite string: ";
    std::getline(std::cin, s);
    auto a = Prebrojavanje(s);
    for(int i = 0; i < 26; i++) {
        std::cout << char('A' + i) << ":" << a[i] << " ";
        if(i == 12) std::cout << std::endl;
    }
    return 0;
}
