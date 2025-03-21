#include <iostream>
#include <vector>
using namespace std;

bool isPerfect(int n){
    if(n<0) n*=(-1);
    int sum = 0;
    // svi djelioci nekog broja idu do n/2
    for(int i = 1; i<=n/2; i++){
        if(n%i==0) sum+=i;
    }
    if(sum==n) return true;
    return false;
}


vector<int> perf(vector<int> &v){
    vector<int> output;
    for(int i = 0; i<v.size(); i++)
        if(isPerfect(v[i]))
            output.push_back(v[i]);
    return output;
}

int main(){
    cout<<"Unesite elemente vaseg vektora (0 za kraj unosa): ";
    vector<int> v;
    int n;
    do{
        cin>>n;
        if(n!=0) v.push_back(n);
    }while(n!=0);
    cout<<"Svi elementi tog vektora koji su savrseni su: ";
    for(int el : perf(v)) cout<<el<<" ";
}