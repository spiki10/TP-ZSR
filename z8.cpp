#include <iostream>
#include <string>
#include <algorithm>
// pohvaljena izvedba od Jurica
void Izvrni(std::string &s){
    for(int i = 0, j = s.length()-1; i<j; i++,j--){
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
// Juriceva verzija sa algorithm druge su iste kao ona iznad
void izvrni(std::string &s){
    for(int i = 0, j = s.length()-1;i<=j; i++,j--)
        std::swap(s[i],s[j]);
}
int main(){
    std::cout<<"Unesite string: ";
    std::string s;
    std::getline(std::cin,s);
    izvrni(s);
    std::cout<<s;

}
