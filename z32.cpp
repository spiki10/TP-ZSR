#include <iostream>
#include <vector>
using namespace std;


int faktorijel(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    int output = 1;
    for(int i = 1; i<=n; i++)
        output*=i;
    return output;
}


vector<int> fun(vector<int> &v){
    vector<int> output;
    for(int i = 0; i<v.size(); i++)
        output.push_back(faktorijel(v[i]));
    return output;
}


int main(){
    int n;
    cout<<"Unesite velicinu vektora: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Unesite elemente vekora: ";
    for(int &el : v) cin>>el;
    for(int el : fun(v)) cout<<el<<" ";
}