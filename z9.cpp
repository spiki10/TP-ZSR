#include <iostream>
#include <deque>
using namespace std;

int SumaCifara(int n){
    int output=0;
    if(n<0) n*=(-1);
    while(n>0){
        int digit = n%10;
        output+=digit;
        n/=10;
    }
    return output;
}

std::deque<int> IzdvojiElemente(std::deque<int> d, bool par_nepar) { 
    std::deque<int> d1; 
    for(int i = d.size() - 1; i >= 0; i--) 
        if(SumaCifara(d[i]) % 2 == !par_nepar) 
            d1.push_front(d[i]); 
    return d1; 
} 

void IspisiDek(std::deque<int> d) { 
    for(int i = 0; i < d.size(); i++) { 
        std::cout << d[i]; 
        if(i != d.size() - 1) 
            std::cout << ","; 
        else 
            std::cout << std::endl; 
    } 
} 

int main() { 
    int n; 
    std::cout << "Koliko zelite unijeti elemenata: "; 
    std::cin >> n; 
    std::deque<int> a(n); 
    std::cout << "Unesite elemente: "; 
    for(int i = 0; i < n; i++) 
        std::cin >> a[i]; 
    auto b = IzdvojiElemente(a, true), c = IzdvojiElemente(a, false); 
    if(b.size() == 0) 
        std::cout << "---\n"; 
    IspisiDek(b); 
    if(c.size() == 0) 
        std::cout << "---\n"; 
    IspisiDek(c); 
    return 0; 
}
