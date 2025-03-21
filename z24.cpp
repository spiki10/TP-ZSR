#include <iostream>
#include <vector>

typedef std::vector<int> vektor;

bool oscilatoran(vektor &v){
    if(v.size()<=2) return true;
    bool pattern = v[1]>v[0]; // ovo daje tacno ako niz raste tako znamo da iduci clan mora da opada
    for(int i = 2; i<v.size(); i++){
        if(pattern && (i%2==0 && v[i-1]<v[i] || i%2==1 && v[i-1]>v[i]))
            return false;
        else if

    }
    return true;
}

int main(){
    int size;
    std::cout<<"Unesite velicinu vektora: ";
    std::cin>>size;
    std::cout<<"Unesite elemente vektora: ";
    vektor v(size);
    for(int &el : v) std::cin>>el;
    oscilatoran(v) ? std::cout<<"Vektor je oscilatoran!!!" : std::cout<<"Vektor nije oscilatoran!!!";
}