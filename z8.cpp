#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

std::string Pretvorba(int n, int B) {
    if(B < 2 || B > 36) throw std::domain_error("Nedozvoljena baza");
    std::string s;
    bool negativan = n < 0;
    do {
        int cifra = std::abs(n % B);
        s = (cifra < 10 ? char('0' + cifra) : char(cifra - 10 + 'A')) + s;
        n /= B;
    } while(n != 0);
    if(negativan) s = '-' + s;
    return s;
}

std::vector<string> PretvoriUBazu(const std::vector<int> &v, int baza){
    std::vector<std::string> w;
    for(int n : v) w.push_back(Pretvorba(n, baza));
    return w;
}

int main(){
    int n, b;
    std::cout << "Koliko ima brojeva: ";
    std::cin >> n;
    std::vector<int> v(n);
    std::cout << "Unesite brojeve: ";
    for(int i = 0; i < n; i++) std::cin >> v[i];
    std::cout << "Unesite bazu: ";
    std::cin >> b;
    std::cout << "Zapis u bazi " << b << ": ";
    for(auto s : PretvoriUBazu(v, b)) std::cout << s << " ";
}
