#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

bool DaLiJeNulMatrica(Matrica a) {
    for (auto red : a) {
        for (double element : red) {
            if (element != 0)
                return false;
        }
    }
    return true;
}

Matrica PomnoziMatrice(Matrica mat1, Matrica mat2) {
    Matrica mat3(mat1.size(), std::vector<double>(mat2[0].size()));

    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat2[0].size(); j++) {
            double suma = 0;

            for (int k = 0; k < mat2.size(); k++)
                suma += mat1[i][k] * mat2[k][j];

            mat3[i][j] = suma;
        }
    }

    return mat3;
}

bool DaLiJeNulMatrica(Matrica a) {
    for (auto red : a) {
        for (double element : red) {
            if (element != 0)
                return false;
        }
    }
    return true;
}

int IndeksNilpotentnosti(Matrica a) {
    int n = a.size();

    for (auto red : a) {
        if (red.size() != n)
            return 0;
    }

    if (DaLiJeNulMatrica(a))
        return 1;

    Matrica stepen = a;

    for (int k = 2; k <= n; k++) {
        stepen = PomnoziMatrice(stepen, a);

        if (DaLiJeNulMatrica(stepen))
            return k;
    }

    return 0;
}

int main() {
    Matrica m(3, std::vector<double>(3));
    std::cout << "Unesite elemente (3x3): ";
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> m[i][j];
        }
    }
    
    int indeks_np = IndeksNilpotentnosti(m);
    
    if (indeks_np != 0) {
        std::cout << "Indeks nilpotentnosti: " << indeks_np;
    } else {
        std::cout << "Matrica nije nilpotentna";
    }
    
    return 0;
}