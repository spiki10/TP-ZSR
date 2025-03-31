#include <iostream>


void broj(int a){
    int helper = 0;
    for(int i = 1; i<a;i++)
        if(a%i==0)
            helper+=i;
    
    if(helper > a)
        std::cout<<"obilan!\n";
    else if(helper < a)
        std::cout<<"manjkav!\n";
    else
        std::cout<<"savrsen!\n";
    
}

int main(){
    int n;
    do{
        std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
        std::cin>>n;
        if(!std::cin || n<0){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Niste unijeli prirodan broj!\n";
            continue;
        }
        std::cout<<"Broj "<<n<<" je ";
        broj(n);
    }while(n!=0);
    std::cout<<"Dovidjenja!";
}