#include <iostream>
#include <vector>
typedef std::vector<std::vector<double>> matrix;


void AnalizaMatrice(const matrix &v, std::vector<int> &nulRed, std::vector<int> &nulKolona){
    nulRed.resize(0);
    nulKolona.resize(0);

    //obilazak redova i provjera
    int m = v[0].size();
    for(int i = 0; i<v.size(); i++){
        if(v[i].size()!=m) throw std::domain_error("Grbava matrica");
        bool flag = true;
        for(int j = 0; j<m; j++){
            if(v[i][j]!=0){
                flag = false;
                break;
            }
        }
        if(flag) nulRed.push_back(i);
    }

    if(v.size()==0) return;
    // obilazak nulKolona
    for(int i = 0;i<m; i++){
        bool flag = true;
        for(int j = 0;j<v.size();j++){
            if(v[j][i]!=0){
                flag = false;
                break;
            }
        }
        if(flag) nulKolona.push_back(i);
    }
}

// Juriceva izvedba, doslovno identicna samo imena varijabli i format se razlikuju
void AnalizaMatrice(const std::vector<std::vector<double>> &m,
                    std::vector<int> &nul_redovi, std::vector<int> &nul_kolone) {
    nul_redovi.resize(0); nul_kolone.resize(0);
    for(int i = 0; i < m.size(); i++) {
        if(m[i].size() != m[0].size()) throw std::domain_error("Grbava matrica");
        bool sve_nule = true;
        for(int j = 0; j < m[i].size() && sve_nule; j++)
            if(m[i][j] != 0) sve_nule = false;
            if(sve_nule) nul_redovi.push_back(i);
    }
    if(m.size() == 0) return;
    for(int j = 0; j < m[0].size(); j++) {
        bool sve_nule = true;
        for(int i = 0; i < m.size() && sve_nule; i++)
            if(m[i][j] == 0) sve_nule = false;
            if(sve_nule) nul_kolone.push_back(j);
    }
}




int main(){
    std::cout<<"Unesite dimenzije: ";
    int n,m;
    std::cin>>n>>m;
    std::cout<<"Unesite elemente: ";
    matrix v(n,std::vector<double>(m));
    for(auto &red : v)
        for(double &el : red)
            std::cin>>el;
    std::vector<int>nulRed,nulKolona;
    AnalizaMatrice(v,nulRed,nulKolona);
    std::cout<<"Nul-redovi: ";
    for(int el : nulRed) std::cout<<el<<" ";
    std::cout<<"\nNul-kolone: ";
    for(int el : nulKolona) std::cout<<el<<" ";
}
