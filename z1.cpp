#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
typedef std::vector<std::vector<int>> matrica;

int dajBrojCifri2(int a){
    return floor(log10(a)) + 1;
}

int dajBrojCifri(int n){
    int brojac = n<=0;
    for(; n!=0; n/=10) brojac++;
    return brojac;
}

int dajDuzinu(matrica &v){
    int output = INT_MIN;
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[0].size(); j++){
            int c = dajBrojCifri(v[i][j]);
            if(output<c) output = c;
        }
    }
    return output;
}


matrica KroneckerovProizvod( std::vector<int> &v1, std::vector<int> &v2){
    matrica output(v1.size(), std::vector<int>(v2.size()));
    for(int i = 0; i<v1.size(); i++)
        for(int j = 0; j<v2.size();j++)
            output[i][j] = v1[i] * v2[j];
    return output;
}


// Juriceva implementacija koja se jedino razlikuje od moje
int NajvecaSirina(matrica m) {
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
    std::cout<<"Unesite velicinu prvog vektora: ";
    std::cin>>n;
    std::vector<int> v1(n);
    std::cout<<"Unesite elemente prvog vektora: ";
    for(int &el : v1) std::cin>>el;
    std::cout<<"Unesite elemente drugog vektora: ";
    std::cin>>n;
    std::vector<int> v2(n);
    std::cout<<"Unesite elemente drugog vektora: ";
    for(int &el : v2) std::cin>>el;
    matrica kp = KroneckerovProizvod(v1,v2);
    int duzinaIspisa = dajDuzinu(kp);
    for(int i = 0; i<kp.size(); i++){
        for(int j = 0; j<kp[0].size(); j++)
            std::cout<<std::setw(duzinaIspisa+1)<<kp[i][j]<<" ";
        std::cout<<std::endl;
    }

}