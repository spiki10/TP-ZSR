#include <iostream>
#include <vector>
#include <exception>
#include <limits>
typedef std::vector<std::vector<double>> matrica;

// Juriceva izvdeba
void Minimax(const std::vector<std::vector<double>> &m,
             double &minimax, double &maximin) {
    if(m.size() == 0) throw std::domain_error("Neispravna matrica");
    minimax = std::numeric_limits<double>::max();
    maximin = std::numeric_limits<double>::lowest();
    for(const auto &red : m) {
        if(red.size() != m[0].size())
            throw std::domain_error("Parametar nema formu matrice");
        if(red.size() == 0) throw std::domain_error("Neispravna matrica");
        double min_reda = red[0], max_reda = red[0];
        for(double element : red) {
            if(element < min_reda) min_reda = element;
            if(element > max_reda) max_reda = element;
        }
        if(max_reda < minimax) minimax = max_reda;
        if(min_reda > maximin) maximin = min_reda;
    }
}

int main() {
    int n, m;
    std::cout << "Unesite dimenzije matrice: ";
    std::cin >> m >> n;
    std::vector<std::vector<double>> mat(m, std::vector<double>(n));
    std::cout << "Unesite elemente: ";
    for(auto &red : mat)
        for(double &e : red) std::cin >> e;
        double p, q;
    Minimax(mat, p, q);
    std::cout << "Minimax vrijednost po redovima: " << p << std::endl;
    std::cout << "Maximin vrijednost po redovima: " << q << std::endl;
    return 0;
}

