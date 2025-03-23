#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int obrni(int n){
    if(n==0) return 0;
    int output = 0,exp = 1;
    bool flag = false;
    if(n<0){
        n=-n;
        flag = true;
    }
    for (int i = 0; i < int(log10(n)); i++) 
        exp *= 10;
    while(n!=0){
        output += (n%10)*exp;
        exp/=10;
        n/=10;
    }
    if(flag)
        return -output;
    return output;
}

vector<int> SlikeUOgledalu(vector<int> &v){
    vector<int> output;
    for(int el : v)
        output.push_back(obrni(el));
    return output;
}


int main(){
    vector<int> v;
    for(;;){
        int n;
        std::cout<<"Umesite element vektora (0 za kraj): "<<std::endl;
        std::cin>>n;
        if(n==0) break;
        v.push_back(n);
    }
    auto result = SlikeUOgledalu(v);
    for(int i = 0; i<v.size(); i++){
        std::cout<<"Slika u ogledalu broja "<<v[i]<<" glasi "<<result[i]<<endl;
    }
}