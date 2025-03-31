#include <iostream>
#include <stdexcept>
#include <string>

// Juricev kod uglavnom
// jedan od mnogih nacina
std::string IzdvojiRijec(const std::string& s, int k) {
    int duzina = s.length();
    int brojac = 0;

    for (int i = 0; i < duzina; i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            brojac++;
            if (brojac == k) {
                std::string rijec;
                while (i < duzina && s[i] != ' ') {
                    rijec += s[i++];
                }
                return rijec;
            }
        }
    }

    throw std::range_error("Pogresan redni broj rijeci");
}



std::string IzdvojiRijec(const std::string& s, int k) {
    int i = 0;
    int duzina = s.length();
    int brojac = 0;

    while (i < duzina) {
        // Preskoči razmake
        while (i < duzina && s[i] == ' ') {
            i++;
        }

        // Provjera da li smo došli do kraja niza
        if (i != duzina) {
            brojac++;
            int j = i;

            // Izdvoji riječ
            while (i < duzina && s[i] != ' ') {
                i++;
            }

            if (brojac == k) {
                return s.substr(j, i - j);
            }
        }
    }

    throw std::range_error("Pogresan redni broj rijeci");
}


int main() {
    int r_broj;
    std::cout << "Unesite redni broj rijeci: ";
    std::cin >> r_broj;

    std::cout << "Unesite recenicu: ";
    std::string recenica;
    std::cin.ignore(10000, '\n');  // Ignorišemo prethodni unos da bismo mogli koristiti getline
    std::getline(std::cin, recenica);

    try {
        std::string rijec = IzdvojiRijec(recenica, r_broj);
        std::cout << "Rijec na poziciji " << r_broj << " je " << rijec << std::endl;
    } catch (const std::range_error& izuzetak) {
        std::cout << "IZUZETAK: " << izuzetak.what() << "!" << std::endl;
    }

    return 0;
}







