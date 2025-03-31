#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    if(n<2 || n%2==0 && n!=2 || n%3==0 && n!=3) return false;
    for(int i = 5; i<=n/i; i+=2)
        if(n%i==0) return false;
    return true;
}


// vector<int> ProstiFaktori(int n){
//     vector<int> output;
//     for(int i = 2; i<n;i++){
//         if(n%i==0 && isPrime(i)){
//             output.push_back(i);
//             while(n%i==0)
//                 n/=i;
//         }
//     }
//     return output;
// }

// vector<int> ProstiFaktoriSPonavljanjem(int n){
//     vector<int> output;
//     for(int i = 2; i<n; i++){
//         if(n%i==0 && isPrime(i)){
//             while(n%i==0){
//                 output.push_back(i);
//                 n/=i;
//             }
//         }
//     }
//     return output;
// }

// Malo efikasnije i bolje Juriceve izvedbe

vector<int> ProstiFaktori(int n){
    vector<int> output;
    int d = 2;
    while(n>2){
        while(n%d!=0) d++;
        output.push_back(d);
        while(n%d==0) n/=d;
    }
    return output;
}


vector<int> ProstiFaktoriSPonavljanjem(int n){
    vector<int> output;
    int d = 2;
    while(n>2){
        while(n%d!=0) d++;
        output.push_back(d);
        n/=d;
    }
    return output;
}

int main(){
    int n;
    cout<<"Unesite broja: ";
    cin>>n;
    auto prva = ProstiFaktori(n);
    auto druga = ProstiFaktoriSPonavljanjem(n);
    if(prva.size()==0 || druga.size() == 0){
        cout<<"Broj nema prostih faktora!"<<endl;
    }else{
        cout<<"Prosti faktori: ";
        for(auto el : prva) cout<<el<<" ";
        cout<<"\nProsti faktori s ponvaljanjem: ";
        for(auto el : druga) cout<<el<<" ";
    }
}