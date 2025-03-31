#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
// killer zadatak ovo je sve naravno Juricev kod
double UzmiOperand(const std::string &s, int &pozicija, bool &cjelobrojan) {
    std::string podstring = s.substr(pozicija, s.length() - pozicija);
    std::size_t gdje_je_kraj;
    double operand = std::stod(podstring, &gdje_je_kraj);
    cjelobrojan = podstring.find_first_of(".eE") == std::string::npos
    && operand <= std::numeric_limits<int>::max()
    && operand >= std::numeric_limits<int>::lowest();
    pozicija += gdje_je_kraj;
    return operand;
}

void PreskociRazmake(const std::string &s, int &i, bool ocekuje_se_kraj = false) {
    while(i < s.length() && s[i] == ' ') i++;
    if(ocekuje_se_kraj && i != s.length() || !ocekuje_se_kraj && i == s.length()) throw "";
}

double Izracunaj(const std::string &s) {
    try {
        int i = 0;
        PreskociRazmake(s, i);
        bool cijeli1;
        double operand1 = UzmiOperand(s, i, cijeli1);
        char operacija = s[i++];
        PreskociRazmake(s, i);
        bool cijeli2;
        double operand2 = UzmiOperand(s, i, cijeli2);
        PreskociRazmake(s, i, true);
        if(operacija == '+') return operand1 + operand2;
        if(operacija == '-') return operand1 - operand2;
        if(operacija == '*') return operand1 * operand2;
        if(operacija == '/')
            if(cijeli1 && cijeli2) return int(operand1) / int(operand2);
            else return operand1 / operand2;
            throw "";
    }
    catch(...) {
        throw std::domain_error("Nelegalan izraz");
    }
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    try {
        double vrijednost = Izracunaj(s);
        std::cout << "Vrijednost izraza: " << vrijednost;
    }
    catch(...) {
        std::cout << "Neispravan izraz!";
    }
    return 0;
}





