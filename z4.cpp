#include <iostream>
#include <vector>
// ovo je neki zadatak iz ZSR 1
using namespace std;

bool DaLiJeProst(int n){
    if(n%2==0&&n!=2 || n%3==0 && n!=3) return false;
    for(int i = 5;i<=n/i;i+=2){
        if(n%i==0) return false;
    }
    return true;
}

vector<int> ProstiBrojeviUOpsegu(int a, int b){
    vector<int> output;
    for(int i = a; i<=b; i++){
        if(DaLiJeProst(i)){
            output.push_back(i);
        }
        if(i==b) break;
    }
    return output;
}



int main(){
    int a,b;
    cout<<"Unesite pocetnu i krajnu vrijednost: ";
    cin>>a>>b;
    auto result = ProstiBrojeviUOpsegu(a,b);
    if(result.size()){
        cout<<"Prosti brojevi u rasponu od "<<a<<" do "<<b<<" su: ";
        for(int i = 0;i<result.size();i++){
            if(i<result.size()-1)
                cout<<result[i]<<", ";
            else   
                cout<<result[i];
        }
    }else
        cout<<"Nema prostih brojeva u rasponu od "<<a<<" do "<<b<<"!";  
}