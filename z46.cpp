#include <iostream>
#include <vector>
using namespace std;

bool compare(vector<int> &v1, vector<int> &v2){
    for(int i = 0; i<v1.size(); i++)
        if(v1[i]!=v2[i])
            return false;
    return true;
}


bool provjera(vector<int> &v1, vector<int> &v2, int pomak){
    vector<int> helper;
    for(int i = 0; i<v1.size()-pomak; i++)
        helper.push_back(v1[i+pomak]);
    for(int i = 0; i<pomak; i++)
        helper.push_back(v1[i]);
    return compare(v2,helper);
}


int CiklickaPermutacija(vector<int> &sek1, vector<int> &sek2){
    if(sek1.size()!=sek2.size()) return -1;
    if(compare(sek1, sek2)) return 0;
    for(int i = 1; i<sek1.size();i++)
        if(provjera(sek1,sek2,i))
            return i;
    return -1;
}

int main(){
    std::cout<<"Unesite prvu sekvencu: ";
    vector<int> sek1,sek2;
    for(;;){
        int n;
        std::cin>>n;
        if(!std::cin){
            cin.clear();
            cin.ignore(10000,'\n');
            break;
        }
        sek1.push_back(n);
    }
    std::cout<<"\nUnesite drugu sekvencu: ";
    for(;;){
        int n;
        std::cin>>n;
        if(!std::cin){
            break;
        }
        sek2.push_back(n);
    }
    int pomak = CiklickaPermutacija(sek1, sek2);
    pomak!=-1 ? std::cout<<"Vrijednost pomaka je: "<<pomak : std::cout<<"Ovo nije ciklicka permutacija!!!";
}