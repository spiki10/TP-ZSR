#include <iostream>
#include <array>
// Rijeseni Zadaci 2 Zadatak 12
bool DaLiSadrzeIstuCifru(int p, int q) {
    std::array<bool, 10> markirana{};
    if (p == 0) 
        markirana[0] = true;
    for (; p != 0; p /= 10) 
        markirana[std::abs(p % 10)] = true;;
    if (q == 0 && markirana[0]) 
        return true;
    for (; p != 0; p /= 10) 
        if (markirana[std::abs(q % 10)]) 
            return true;
    return false;
}

int main() {
    int broj_1, broj_2;
    std::cout << "Unesite dva broja: ";
    std::cin >> broj_1 >> broj_2;
    std::cout << "Uneseni brojevi ";
    if (DaLiSadrzeIstuCifru(broj_1, broj_2)) 
        std::cout << " sadrze istu cifru";
    else 
        std::cout << "ne sadrze nijednu istu cifru";
    return 0;
}
