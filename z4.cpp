#include <iostream>
#include <vector>
#include <cmath>

enum class VrstaMatrice {Grbava, Nekvadratna, KvadratnaNeortogonalna, Ortogonalna};

bool Jednaki(double x, double y){
    return std::fabs(x-1)<=1e-5 * (std::fabs(x) + std::fabs(y));
}


VrstaMatrice DajVrstuMatrice(std::vector<std::vector<double>> a) {
    int n = a.size();
    if (n == 0)
        return VrstaMatrice::Ortogonalna;

    int m = a[0].size();
    for (int i = 1; i < n; i++)
        if (a[i].size() != m)
            return VrstaMatrice::Grbava;

    if (m != n)
        return VrstaMatrice::Nekvadratna;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double c = 0;

            for (int k = 0; k < n; k++)
                c += a[k][i] * a[k][j]; 
            if (!Jednaki(c, i == j))
                return VrstaMatrice::KvadratnaNeortogonalna;
        }
    }

    return VrstaMatrice::Ortogonalna;
}

int main() {
    int n;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> n;

    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::cout << "Unesite elemente matrice: ";
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++)
            std::cin >> a[i][j];
    }

    if (DajVrstuMatrice(a) == VrstaMatrice::Ortogonalna)
        std::cout << "Matrica je ortogonalna" << std::endl;
    else
        std::cout << "Matrica nije ortogonalna" << std::endl;

    return 0;
}

