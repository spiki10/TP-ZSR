#include <iostream>
#include <vector>


int BrojPrijateljskihParova(std::vector<int> v) {
    std::vector<int> sume_djelilaca;
    for (int element : v) {
        int suma = 0;
        for (int k = 1; k < element; k++)
            if (element % k == 0)
                suma += k;
        sume_djelilaca.push_back(suma);
    }

    int brojac = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            if (sume_djelilaca[i] == v[j] && sume_djelilaca[j] == v[i])
                brojac++;
    return brojac;
}


int main() {
    int n;
    std::cout << "Koliko ima brojeva: ";
    std::cin >> n;
    std::cout << "Unesite brojeve: ";
    std::vector<int> v(n);
    for (int i = 0; i < v.size(); i++)
        std::cin >> v[i];

    std::cout << "Broj prijateljskih parova: " << BrojPrijateljskihParova(v);
    return 0;
}
