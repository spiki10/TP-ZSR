#include <iostream>
#include <vector>
using namespace std;

int sumaCifara(int n){
    int output=0;
    if(n<0) n*=(-1);
    while(n>0){
        int digit = n%10;
        output+=digit;
        n/=10;
    }
    return output;
}

vector<int> IzdvojiElemente(vector<int> v, bool parnost){
    vector<int> output;
    for(int el : v)
        if(sumaCifara(el)%2==0&&parnost || sumaCifara(el)%2!=0 && !parnost) output.push_back(el);
        // ima malo bolja vrarijanta ove provjer
        // if(sumaCifara%2==!parnost)
    return output;
}

int main(){
    int n;
    cout<<"Koliko zelite unijeti elemenata: ";
    cin>>n;
    cout<<"Unesite elemente: ";
    vector<int> ulazni;
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        ulazni.push_back(a);
    }
    // ovo je samo cool trick
    // if(IzdvojiElemente(ulazni,true).size()==0)
    //     cout<<"---\n";
    // else
    //     for(int el : IzdvojiElemente(ulazni,true))
    //         cout<<el<<" ";
    
    // cout<<endl;
    // if(IzdvojiElemente(ulazni,false).size()==0)
    //     cout<<"---\n";
    // else
    //     for(int el : IzdvojiElemente(ulazni,false))
    //     cout<<el<<" ";
    // ovako je receno da se uradi
    auto a = IzdvojiElemente(ulazni,false);
    auto b = IzdvojiElemente(ulazni, true);
    if(b.size()==0)
        cout<<"---\n";
    else 
        for(int el : b)
            cout<<el<<" ";
    cout<<endl;
    if(a.size()==0) cout<<"---";
    else for(int el : a) cout<<el<<" ";
    
}