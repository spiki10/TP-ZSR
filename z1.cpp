#include <iostream>
using std::cout, std::cin;


int main(){
    int h1,min1,s1;
    cout<<"Unesite prvo vrijeme (h min s): ";
    cin>>h1>>min1>>s1;
    cout<<"Unesite drugo vrijeme (h min s): ";
    int h2,min2,s2;
    cin>>h2>>min2>>s2;
    int dif = (h2*3600+min2*60+s2) - (h1*3600+min1*60+s1);
    // int sati = dif/3600;
    // dif-=(sati*3600);
    // int minute = dif/60;
    // dif-=(minute*60);
    // cout<<"izmedju ova dva trenutka proteklo je "<<sati<<"h "<<minute<<"min "<<dif<<"s";
    // kraca varijanta odnosno varijanta bez dodatnih promjenljivih
    cout<<"Izmedju ova dva trenutka proteklo je "<<dif/3600<<"h "<<(dif%3600)/60<<"min "<<dif%60<<"s";
    
}