#include <iostream>
using namespace std;

bool isDivisible(int n){
    int sum = 0, copy = n;
    while(n>0){
        int digit = n%10;
        sum+=digit;
        n/=10;
    }
    return copy%sum==0 ? 1 : 0;
}

void ispis(int a, int b){
    int counter = 0;
    for(int i = a; i<=b; i++){
        if(isDivisible(i)){ 
            counter++;
        }
    }
    cout<<"\n"<<counter;
}

int main(){
    int a,b;
    cout<<"Unesite vrijednosti a i b: ";
    cin>>a>>b;
    cout<<"Svi brojevi u datom opsegu koji su djeljivi sa svojom sumom cifara su: ";
    ispis(a,b);

}