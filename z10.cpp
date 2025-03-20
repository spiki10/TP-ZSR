#include <iostream>
#include <cmath>
#include <vector>
typedef std::vector<int> vek;


bool isFun(vek &v){
    for(int el : v){
        int i = 1;
        while(i*i<=el){
            if(i*i==el) return true;
            i++;
        }
    }
    return false;
}

// malo efikasnija izvedba

bool isFun2(vek &v){
    for(int el : v){
        if(el>=1){
            int korjien = int(sqrt(el));
            if(korjien*korjien == el) return true;
        }
    }
    return false;
}

int main(){
    int n;
    std::cout<<"Unesite velicinu vektora: ";
    std::cin>>n;
    vek v(n);
    std::cout<<"Unesite elemente vektora: ";
    for(int i = 0; i<n; i++) std::cin>>v[i];
    std::cout<<"U datom vektoru ";
    isFun2(v) ? std::cout<<"ima potpunih kvadrata!" : std::cout<<"nema potpunih kvadrata!";
}