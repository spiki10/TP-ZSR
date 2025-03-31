#include <iostream>
#include <iomanip>
using std::cout, std::cin, std::endl;
//moj pokusaj
void trougao(int h){
    char sign = cout.fill(' ');
    for(int i = 1; i<h; i++){
        cout<<std::setfill(' ')<<std::setw(h-i+1)<<"*";
        if(i!=1)
            cout<<std::setw(2*i-2)<<"*";
        if(i+1==h)
            cout<<"\n"<<std::setfill('*')<<std::setw(2*i+1)<<"";
        cout<<endl;
    }
    cout<<std::setfill(sign);
}


//Juric best take po mom ukusu
/*
Ovo rjesenje je prekreativno
Prvo ispisuje sirine sa fill manipulatorom na izlazni tok, pa se onda ispisuje zvjezdica jedna bezuvjetno nakon toga bilo da je uslo u if bilo da nije
ako ispisujemo za drugi red prvo ispisi zvjezdicu pa ispisuj 2*i-3 razmaka a kad dodjes do 2*i-3te iteracije onda ispisi zvjezdicu koja se nalazi van if uslova
za sta je u biti ta petlja i uslov jer kada dodjemo do posljednjeg reda ispisujemo samo zvjezdice a one sto su van su nam bitne jer se one ne nalaze izmedju razmaka
nego razmaci izmedju te dvije zvjezdice
*/ 
void juric(int visina){
    for(int red = 1; red <= visina; red++) { 
        std::cout.width(visina - red + 1); 
            if(red != 1) { 
                std::cout << "*"; 
                for(int i = 1; i <= 2 * red - 3; i++) 
                    std::cout << (red == visina ? "*" : " "); 
                } 
        std::cout << "*" << std::endl; 
    }
}

//matematicki nacin
void juric2(int visina){
    for(int red = 1; red <= visina; red++) { 
        for(int kolona = 1; kolona < 2 * visina; kolona++) 
            std::cout << ((kolona == visina + 1 - red || kolona == visina - 1 + red || red == visina) ? "*" : " "); 
                std::cout << std::endl; 
    } 
}
int main(){
    int h;
    cout<<"Unesite visinu trougla: ";
    cin>>h;
    trougao(h);
    cout<<endl;
    juric(h);

    return 0;
}