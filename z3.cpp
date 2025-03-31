#include <iostream>
#include <complex>

int main() {
    const double PI = 4 * std::atan(1);
    int n;
    std::cout << "Unesite broj elemenata: ";
    std::cin >> n;
    std::cout << std::endl;
    std::complex<double> suma;
    for(int i = 1; i <= n; i++) {
        double z, fi;
        std::cout << "Z" << i << " = ";
        std::cin >> z;
        std::cout << "fi" << i << " = ";
        std::cin >> fi;
        suma += 1. / std::polar(z, fi * PI / 180);
        std::cout << std::endl;
    }
    suma = 1. / suma;
    std::cout << "Paralelna veza ovih elemenata ima Z = " << std::abs(suma) 
              << " i fi = " << std::arg(suma) * 180 / PI << ".\n";
    return 0;
}
