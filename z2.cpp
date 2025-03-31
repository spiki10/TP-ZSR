#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<int>> matrix;

matrix PascalovTrougao(int n){
    if(n<0) throw std::domain_error("Broj redove ne moze biti negativan");
    matrix output(n);
    for(int i = 0; i<n; i++){
        output[i].resize(i+1);
        output[i][0] = 1;
        output[i][i] = 1;
        for(int j = 1; j<i; j++)
            output[i][j] = output[i-1][j-1] + output[i-1][j];
    }
    return output;
}

int NajvecaSirina(matrix m) {
    int najveci = 0;
    for (std::vector<int> red : m)
        for (int x : red) {
            int brojac = x <= 0;

            for (; x != 0; x /= 10)
                brojac++;

            if (brojac > najveci)
                najveci = brojac;
        }
    return najveci + 1;
}





int main(){
    int n;
    std::cout << "Unesite broj redova: ";
    std::cin >> n;

    auto a = PascalovTrougao(n);
    int sirina = NajvecaSirina(a) + 1;

    std::cout << std::endl;

    for (auto red : a) {
        for (int x : red)
            std::cout << std::setw(sirina) << x;

        std::cout << std::endl;
    }
}