#include <iostream>
#include <vector>

typedef std::vector<double> vek;

bool SviElementiSuRazliciti(vek &v){
    for(int i = 0; i<v.size(); i++)
        for(int j = i+1; j<v.size(); j++)
            if(v[i]==v[j])
                return false;
    return true;
}

bool SviElementiSuJednaki(vek &v){
    if(v.size()==0) return true;
    double el = v[0];
    for(double check : v)
        if(check!=el)
            return false;
    return true;
}

int main(){
    int n;
    std::cout<<"Unesite velicinu vektora: ";
    std::cin>>n;
    vek v(n);
    for(int i = 0; i < n; i++)
        std::cin>>v[i];
    std::cout<<"Rezultat funkcjie SviElementiSuRazliciti = "<<std::boolalpha<<SviElementiSuRazliciti(v)
             <<"\nRezultat funkcije SviElementiSuJednaki = "<<SviElementiSuJednaki(v);
}
