#include <iostream>
#include <cmath>

// najveca razlika je sto ja imam jedan if viska jer nisam dobro postavio vrijednosti za c_min i c_max
int CifreJa(long long int n, int &c_max, int &c_min){
    if(n<0) n = -n;
    if(n==0){
        c_max = 0;
        c_min = 0;
        return 1;
    }
    int output = floor(log10(n))+1;
    c_max = INT_MIN;
    c_min = INT_MAX;
    while(n!=0){
        int digit = n%10;
        if(c_max<digit) c_max = digit;
        if(c_min>digit) c_min = digit;
        n/=10;
    }
    return output;
}

// Juriceva izvedba
int Cifre(long long int n, int &c_min, int &c_max) {
    int brojac = 0;
    c_min = 9; c_max = 0;
    do {
        brojac++;
        int cifra = n % 10;
        if(cifra < 0) cifra = -cifra;
        if(cifra < c_min) c_min = cifra;
        if(cifra > c_max) c_max = cifra;
        n /= 10;
    } while(n != 0);
    return brojac;
}


int main(){
    long long int n;
    std::cout<<"Unesite vas broj: ";
    std::cin>>n;
    int a,b;
    int e = Cifre(n,a,b);
    std::cout<<"Broj cifara broja je: "<<e<<"\nNajveca vrijednost je: "<<a<<"\nNajmanja vrijednost je: "<<b<<std::endl;
}
