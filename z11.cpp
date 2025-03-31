#include <iostream>
#include <vector>
using namespace std;
enum class VrstaNiza {Aritmeticki, Geometrijski, Nespecificni};


VrstaNiza OdrediVrstuNiza(vector<int> v){
    if(v.size()<2) return VrstaNiza::Nespecificni;
    bool aritmeticki = true;
    int razlika = v[1]-v[0];
    for(int i = 2; i<v.size();i++)
        if(v[i]-v[i-1]!=razlika) aritmeticki = false;
    if(aritmeticki) return VrstaNiza::Aritmeticki;
    if(v[0]==0) return VrstaNiza::Nespecificni;
    double kolicnik = double(v[1]/v[0]);
    for(int i = 2; i<v.size();i++)
        if(v[i-1]==0 || double(v[i]/v[i-1])!=kolicnik)
            return VrstaNiza::Nespecificni;
    return VrstaNiza::Geometrijski;
}

int main(){
    int n;
    cout<<"Broj elemenata: ";
    cin>>n;
    cout<<"Unesite elemente niza: ";
    vector<int>v(n);
    for(int i = 0; i<n;i++) cin>>v[i];
    const char *tekstovi[3] {"Aritmeticki", "Geometrijski", "Nespecificirani"};
    cout<<"Niz je "<< tekstovi[int(OdrediVrstuNiza(v))];
    return 0;
}
