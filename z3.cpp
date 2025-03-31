#include <iostream>
#include <vector>

int BrojStacionarnih(std::vector<std::vector<int>> a) {
    int brojac = 0, m = a.size();

    for (int i = 0; i < m; i++) {
        int n = a[i].size();

        if (n != a[0].size())
            throw std::domain_error("Neispravna matrica");

        for (int j = 0; j < n; j++) {
            int e = a[i][j];

            brojac += (i == 0 || e == a[i - 1][j]) &&
                      (i == m - 1 || e == a[i + 1][j]) &&
                      (j == 0 || e == a[i][j - 1]) &&
                      (j == n - 1 || e == a[i][j + 1]);
        }
    }

    return brojac;
}

int BrojStacionarnihPoboljsana(std::vector<std::vector<int>> a) {
    int brojac = 0, m = a.size();

    for (int i = 0; i < m; i++) {
        int n = a[i].size();

        for (int j = 0; j < n; j++) {
            int e = a[i][j];
            brojac += (i == 0 || j >= a[i - 1].size() || e == a[i - 1][j]) &&
                      (i == m - 1 || j >= a[i + 1].size() || e == a[i + 1][j]) &&
                      (j == 0 || e == a[i][j - 1]) &&
                      (j == n - 1 || e == a[i][j + 1]);
        }
    }

    return brojac;
}

int main() {
    int m, n;
    std::cout << "Unesite dimenzije matrice: ";
    std::cin >> m >> n;

    std::vector<std::vector<int>> mat(m, std::vector<int>(n));
    std::cout << "Unesite elemente: ";
    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat[i].size(); j++)
            std::cin >> mat[i][j];

    std::cout << "Broj stacionarnih elemenata: " << BrojStacionarnih(mat);

    return 0;
}
