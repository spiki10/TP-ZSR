#include <iostream>
#include <vector>
using namespace std;
// bez upotrebe nekih data structures popu setova i mapa drugacije nije moguce uraditi

vector<int> OdstraniDuplikate(vector<int> &v){
    vector<int> output;
    for(int i = 0; i<v.size(); i++){
        int flag = 1;
        for(int j = 0; j<output.size(); j++){
            if(output.size()!=0 && output[j]==v[i]){
                flag = 0;
                break;
            }
        }
        if(flag) output.push_back(v[i]);
    }
    return output;
}


int BrojDuplikata(vector<int> &v){
    vector<int> pomocni;
    for(int i = 0; i<v.size(); i++){
        bool found = false, other = false;
        for(int j = i+1;j<v.size(); j++){
            if(v[j]==v[i]){
                found = true; 
                break;
            }   
        }
        if(found){
        for(int k = 0; k<pomocni.size(); k++)
            if(pomocni[k]==v[i]){
                other = true;
                break;
            }
        }
        if(found && !other) pomocni.push_back(v[i]);
    }
    return pomocni.size();
}


int main(){
    int n;
    cout<<"Unesite velicinu vektora: ";
    cin>>n;
    cout<<"Unesite elemente vektora: ";
    vector<int> v(n);
    for(int &el : v) cin>>el;
    cout<<"Broj duplikata je: "<<BrojDuplikata(v)<<endl;
    cout<<"Vektor bez duplikata: ";
    auto var = OdstraniDuplikate(v);
    for(int i = 0; i<var.size(); i++)
        i!=var.size()-1 ? cout<<var[i]<<", " : cout<<var[i]<<'\n';
}