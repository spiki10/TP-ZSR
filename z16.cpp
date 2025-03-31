#include <iostream>
#include <string>
#include <vector>

template <typename T>
bool imaGa(const std::vector<T> &v, const T &e){
    for(auto &x : v)
        if(x==e) return true;
    return false;
}


template <typename T>
std::vector<T> Presjek(const std::vector<T> &v1, const std::vector<T> &v2){
    std::vector<T> output;
    for(auto &x : v1)
        if(imaGa(v2,x) && !imaGa(output,x))
            output.push_back(x);
    return output;
}

int main() {
    int n1, n2;
    std::cout << "Test za realne brojeve...\n";
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> n1;
    std::cout << "Unesite elemente prvog vektora: ";
    std::vector<double> v1(n1);
    for(double &x : v1) std::cin >> x;
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n2;
    std::cout << "Unesite elemente drugog vektora: ";
    std::vector<double> v2(n2);
    for(double &x : v2) std::cin >> x;
    std::cout << "Zajednicki elementi su: ";
    for(double x : Presjek(v1, v2)) std::cout << x << " ";
    std::cout << std::endl << std::endl;
    std::cout << "Test za stringove...\n";
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> n1;
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa):\n";
    std::vector<std::string> vs1(n1);
    for(std::string &s : vs1) std::getline(std::cin, s);
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n2;
    std::cin.ignore(10000, '\n');
    std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa):\n";
    std::vector<std::string> vs2(n2);
    for(std::string &s : vs2) std::getline(std::cin, s);
    std::cout << "Zajednicki elementi su:\n";
    for(const std::string &s : Presjek(vs1, vs2)) std::cout << s << std::endl;
    return 0;
}
