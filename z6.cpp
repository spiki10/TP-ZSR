#include <iostream>
#include <vector>
using namespace std;


bool TestPeriod(vector<double> v, int p){
    if(p<2 || p>=v.size()) return false;
    for(int i = 0; i<v.size()-p;i++)
        if(v[i]!=v[i+p]) return false;
    return true;
}

int OdrediOsnovniPeriod(vector<double> v){
    int out;
    for(int i = 1;i<v.size();i++)
        if(v[0]==v[i] && TestPeriod(v,i)) return i;
    return 0;
}

int main(){
    cout<<"Unesite slijed brojeva (0 za kraj): ";
    vector<double> v;
    for(;;){
        double n;
        cin>>n;
        if(n==0) break;
        v.push_back(n);
    }
    int period = OdrediOsnovniPeriod(v);
    if(period)
        cout<<"Slijed je periodican sa osnovnim periodom: "<<period;
    else
        cout<<"Slijed nije periodican!";
}   