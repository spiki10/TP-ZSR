#include <iostream>
using namespace std;

int Podbroj(int n, bool parnost){
    int output = 0, eksponent = 1;
    if(n<0) n*=(-1);
    while(n!=0){
        int digit = n%10;
        if(parnost && digit%2==0 || !parnost&&digit%2==1){
            output += digit * eksponent;
            eksponent*=10;
        }
        n/=10;
    }
    return output;
}


int main(){
    int n;
    do{
        cout<<"Unesite n: ";
        cin>>n;
        if(n!=0)
            cout<<Podbroj(n,true)<<"\n"<<Podbroj(n,false)<<endl;
        else
            cout<<"Kraj programa!!!";
    }while(n!=0);


}