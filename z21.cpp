#include <iostream>
using namespace std;
// cool zadacic
void nr(){cout<<endl;}
void masna(int m, int n){
    // gornja polovica
    for(int i = 0; i<n/2; i++){
        for(int j = 0; j<i;j++)
            cout<<" ";
        cout<<"*";
        for(int k = 0; k<m-2*i-2; k++)
            cout<<" ";
        // provjera ima li dovoljno mjesta za ispis znaka
        if (m - 2 * i - 2 > 0)
            cout << "*";
        nr();
    }

    // srednja linija
    for(int i = 0;i<m-n/2;i++)
        i<n/2 ? cout<<" " : cout<<"*";
    nr();

    // donji dio
    for(int i = n/2-1; i>=0; i--){
        for(int j = 0;j<i;j++) cout<<" ";
        cout<<"*";
        for(int k = 0; k<m-2*i-2;k++)
            cout<<" ";
        if (m - 2 * i - 2 > 0)
            cout << "*";
        nr();
    }
}




int main(){
    int m,n;
    cout<<"Unsite vrijednosti m i n: ";
    cin>>m>>n;
    masna(m,n);
    nr();
}