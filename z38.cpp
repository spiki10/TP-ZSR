#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    if(n<2 || n!=2 && n%2==0 || n!=3 && n%3==0) return false;
    for(int i = 5; i<=n/i; i+=2)
        if(n%i==0)
            return false;
    return true;
}

vector<int> ProstiBrojevi(int n){
    vector<int> output;
    for(int i = 2; i<=n; i++)
        if(isPrime(i))
            output.push_back(i);
    return output;
}

vector<int> ProstiBrojeviBlizanci(int n){
    vector<int> output;
    for(int i = 2;output.size()!=2*n;i++){
        if(isPrime(i) && isPrime(i+2)){
            output.push_back(i);
            output.push_back(i+2);
            i+=2;
        }
    }
    return output;
}

vector<int> ProstiFaktori(int n){
    vector<int> output;
    if(isPrime(n)) return output;
    for(int i = 2; i<=n/i; i++){
        if(n%i==0 && isPrime(i)){
            while(n%i==0){
                output.push_back(i);
                n/=i;
            }
        }
    }
    if(n>1)
        output.push_back(n);
    return output;
}

vector<int> Djelioci(int n){
    vector<int> output;
    for(int i = 1; i<n; i++)
        if(n%i==0)
            output.push_back(i);
    return output;
}


int main(){
    int n;
    std::cout<<"Unesite n: ";
    std::cin>>n;
    std::cout<<"ProstiBrojevi: ";
    for(int el : ProstiBrojevi(n)) std::cout<<el<<" ";
    std::cout<<"\nProstiBrojeviBlizanci: ";
    for(int el : ProstiBrojeviBlizanci(n)) std::cout<<el<<" ";
    std::cout<<"\nDjelioci: ";
    for(int el : Djelioci(n)) std::cout<<el<<" ";
    std::cout<<"\nProstiFaktori: ";
    for(int el : ProstiFaktori(n)) std::cout<<el<<" ";
}