#include <iostream>
#include <vector>


bool check(int n){
    if(n<0) n = -n;
    bool flag = n%2;
    while(n!=0){
        int digit = n%10;
        if(digit%2!=flag) return false;
        n/=10;
    }
    return true;
}


void parnost(std::vector<int> &v){
    if(v.size() == 0) return;
    for(int i = 0; i<v.size();i++){
        if(!check(v[i])){
            v.erase(v.begin()+i);
            i--;
        }
    }
}


// Juriceva izvedba
bool TestCifara(int n) {
    for(int prva_cifra = n % 10; n != 0; n /= 10)
        if(n % 2 != prva_cifra % 2) return false;
        return true;
}
// ova je malo brza i vise cool
// prolazi kroz citav vektor jednom ako nadjes element koji zadovoljava rjesenje
// stavi ga na poecetak vektora pa resize vektor na broj vrijednosti koji zadovoljavaju rjesenje
void Odstrani(std::vector<int> &v) {
    int j = 0;
    for(int i = 0; i < v.size(); i++)
        if(TestCifara(v[i])) v[j++] = v[i];
        v.resize(j);
}





int main(){
    int n;
    std::cout<<"Unesite velicinu vektora: ";
    std::cin>>n;
    std::vector<int> v(n);
    std::cout<<"Unesite elemente vektora: ";
    for(int &el : v) std::cin>>el;
    parnost(v);
    std::cout<<"Izgled vektora nakon uklanjanja elemenata: ";
    for(int &el : v) std::cout<<el<<" ";

    return 0;
}
