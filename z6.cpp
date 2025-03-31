#include <iostream>
#include <iomanip>
using std::cout, std::cin, std::endl;
// moja implementacija
void trougao(int h){
    for(int i = 0;i<h;i++){
        for(int j = i+1;j<h;j++){
            cout<<" ";
        }
        for(int k = i;k>=0;k--)
            cout<<"*";
        for(int l = 0;l<i;l++)
            cout<<"*";
        cout<<endl;
    }
}
//jos jedna moja ideja, ali ova ne daje dobro rjesenje ja mislim
void trougao2(int h){
    for(int i = 0;i<h;i++){
        for(int j = h;j>i;j--) cout<<" ";
        for(int k = 0;k<2*i;k++) cout<<"*";
        cout<<endl;
    }
}
//Juriceva implementacija
void juric(int visina){
    for(int red = 1; red <= visina; red++) { 
        for(int i = 1; i <= visina - red; i++) 
            std::cout << " "; 
        for(int i = 1; i < 2 * red; i++) 
            std::cout << "*"; std::cout << std::endl; 
    } 
}

//bolje Juricevo rj po mn
void juric2(int visina){
    for(int red = 1; red <= visina; red++) { 
        std::cout << std::setw(visina - red) << ""; 
        for(int i = 1; i < 2 * red; i++) 
            std::cout << "*"; std::cout << std::endl; 
    } 
}
// DEFINITIVNO NAJBOLJE RJ
void juric3(int visina){
    for(int red = 1; red <= visina; red++) 
    std::cout << std::setfill(' ') << std::setw(visina - red) << "" << 
        std::setfill('*') << std::setw(2 * red - 1) << "" << std::endl; 
}



int main(){
    int h = 8;
    cout<<"Unesite visinu trougla: "<<endl;
    cin>>h;
    trougao(h);
    cout<<endl;
    juric(h);

    return 0;
}