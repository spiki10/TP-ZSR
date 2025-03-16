#include <iostream>
#include <iomanip>
using namespace std; // mrsko mi svaki put za std::cin i std::cout pisat


void nr(){
    cout<<endl;
}

int main(){
    int m,n;
    cout<<"Unesite vrijednost za n pa za m: "<<endl;
    cin>>n>>m;
    // prva prljava varijanta mada ne znam koliko je dobra uopste za neke odredjene slucajeve
    for(int i=0;i<m;i++){
        if(i==0 || i==m-1){
            for(int j = 0;j<n;j++) cout<<"*";
        }else
            cout<<"*"<<std::setw(n-1)<<right<<"*";
        cout<<endl;
    }
    cout<<endl;
    // drugaciji pristup malo
    for(int i = 0;i<m;i++){
        if(i==0 || i==m-1){
            for(int j = 0;j<n;j++) cout<<"*";
        }else{
            cout<<"*";
            if(n==1) break;
            for(int j = 0;j<n-2;j++)
                cout<<" ";
            cout<<"*";
        }
        cout<<endl;
    }


    return 0;
}