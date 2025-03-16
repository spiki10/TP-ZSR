#include <iostream>
using namespace std;

bool isPrime(int a){
    // moguce dodatne bespotrebne provjere ispravnosti
    if(a%2==0 && a!=2 || a%3==0 && a!=3) return false;
    for(int i = 5; i*i<=a;i+=2){
        if(a%i==0) return false;
    }
    return true;
}

void prime(int n, int m){
    for(int i = n;i<=m;i++){
        if(isPrime(i)) cout<<i<<" ";
    }
}

int main(){
    int n,m;
    cout<<"Unesite n i m: ";
    cin>>n>>m;
    cout<<"Svi prosti brojevi u opsegu ["<<n<<", "<<m<<"] su: "; 
    prime(n,m);

}