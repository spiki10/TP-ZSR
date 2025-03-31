#include <iostream>
#include <string>
#include <cctype>
#include <vector>
// zadacina
/*

std::string myLower(const std::string &s){
    std::string output = "";
    for(int i = 0; i<s.length(); i++) output+= std::tolower(s[i]);
    return output;
}


void IzdvojiKrajnjeRijeci(const std::vector<std::string> &v, std::string &first, std::string &last){
    if(v.size()==0){
        first = ""; last = ""; return;
    }
    first = myLower(v[0]); last = myLower(v[0]);
    for(int i = 1; i<v.size(); i++){
        if(myLower(v[i])<first) first = myLower(v[i]);
        if(myLower(v[i])>last) last = myLower(v[i]);
    }
}

int BrojDuplikata(std::vector<std::string> v){
    int counter = 0;
    for(int i = 0; i<v.size(); i++){
        std::string tmp  = v[i];
        for(int j = i+1; j<v.size(); j++)
            if(v[j]==tmp){
                counter++;
                while(j<v.size()){
                    if(v[j]==tmp){
                        v.erase(v.begin()+j);
                        j--;

                    }
                    j++;
                }
            }
    }
    return counter;
}*/

// Juriceve izvedbe
void IzdvojiKrajnjeRijeci(const std::vector<std::string> &v, std::string &prva,
                          std::string &posljednja) {
    prva = posljednja = (v.size() != 0 ? v[0] : "");
    std::string prva_vs = prva;
    for(char &c : prva_vs) c = std::toupper(c);
    std::string posljednja_vs = prva_vs;
    for(const auto &s : v) {
        std::string s_vs = s;
        for(char &c : s_vs) c = std::toupper(c);
        if(s_vs < prva_vs) {
            prva = s; prva_vs = s_vs;
        }
        if(s_vs > posljednja_vs) {
            posljednja = s; posljednja_vs = s_vs;
        }
    }
}
// stvarno preglupo ali i predobro
int BrojDuplikata(const std::vector<std::string> &v) {
    int brojac_duplikata = 0;
    for(int i = 0; i < v.size(); i++) {
        auto s = v[i];
        int brojac_pojavljivanja = 0;
        for(int j = 0; j < i; j++)
            brojac_pojavljivanja += v[j] == s;
        brojac_duplikata += brojac_pojavljivanja == 1;
    }
    return brojac_duplikata;
}

void ZadrziSamoDuplikate(std::vector<std::string> &v) {
    int j = 0;
    for(int i = 0; i < v.size(); i++) {
        auto s = v[i];
        bool bio_prije = false, ima_ga_poslije = false;
        for(int j = 0; j < i && !bio_prije; j++)
            if(v[j] == s) bio_prije = true;
            for(int j = i + 1; j < v.size() && !ima_ga_poslije; j++)
                if(v[j] == s) ima_ga_poslije = true;
                if(!bio_prije && ima_ga_poslije) v[j++] = s;
    }
    v.resize(j);
}

int main() {
    int n;
    std::cout << "Koliko zelite unijeti rijeci: ";
    std::cin >> n;
    std::vector<std::string> v(n);
    std::cout << "Unesite rijeci: ";
    for(auto &s : v) std::cin >> s;
    std::string prva, posljednja;
    IzdvojiKrajnjeRijeci(v, prva, posljednja);
    std::cout << "Prva rijec po abecednom poretku: " << prva << std::endl;
    std::cout << "Posljednja rijec po abecednom poretku: " << posljednja << std::endl;
    int broj_duplikata = BrojDuplikata(v);
    if(broj_duplikata != 0) {
        std::cout << "Broj duplikata: " << BrojDuplikata(v) << std::endl;
        ZadrziDuplikate(v);
        std::cout << "Rijeci koje se ponavljaju su: ";
        for(const std::string &s : v) std::cout << s << " ";
        std::cout << std::endl;
    }
    else std::cout << "Nema rijeci koje se ponavljaju\n";
    return 0;
}



