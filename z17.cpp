#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <limits>
#include <stdexcept>



template <typename TipBrojeva>
std::vector<TipBrojeva> BrojeviUStringu(std::string_view s) {
    std::vector<TipBrojeva> v;
    std::range_error prevelik("Broj izvan opsega");
    TipBrojeva najmanji = std::numeric_limits<TipBrojeva>::lowest();
    TipBrojeva najveci = std::numeric_limits<TipBrojeva>::max();
    for(int i = 0; i < s.length(); i++)
        if((i == 0 || s[i - 1] == ' ') &&
            (s[i] == '+' || s[i] == '-' || std::isdigit(s[i]))) {
            bool nenegativan = s[i] != '-';
        if(s[i] == '+' || s[i] == '-') i++;
        if(i == s.length() || !std::isdigit(s[i])) continue;
        int tekuca_pozicija = i;
            while(i < s.length() && std::isdigit(s[i])) i++;
            if(i != s.length() && std::isalpha(s[i])) continue;
            i = tekuca_pozicija;
            TipBrojeva broj = 0;
            while(std::isdigit(s[i])) {
                int cifra = s[i] - '0';
                if(nenegativan) {
                    if(broj > najveci / 10) throw prevelik;
                    broj *= 10;
                    if(broj > najveci - cifra) throw prevelik;
                    broj += cifra;
                }
                else {
                    if(broj < najmanji / 10) throw prevelik;
                    broj *= 10;
                    if(broj < najmanji + cifra) throw prevelik;
                    broj -= cifra;
                }
                i++;
            }
            v.push_back(broj);
            }
            return v;
}



int main() {
    std::string s;
    std::cout << "Unesite string: ";
    std::getline(std::cin, s);
    try {
        auto v = BrojeviUStringu<long long int>(s);
        if(v.size() == 0)
            std::cout << "Uneseni string ne sadrzi nijedan broj!\n";
        else {
            std::cout << "Brojevi unutar stringa: ";
            for(auto e : v) std::cout << e << " ";
        }
    }
    catch(...) {
        std::cout << "PROBLEM: Uneseni string sadrzi broj izvan opsega!!!\n";
    }
    return 0;
}
