#include <iostream>
#include <vector>
typedef std::vector<int> vektor;
vektor kvadrati(int n){
    vektor output;
    // for(int i = 1; i<n; i++)
    //     if(i*i<n) 
    //         output.push_back(i*i);
    // mada moze i ovako
    for(int i = 1; i*i < n; i++)
        output.push_back(i*i);
    return output;
}


int main(){
    int n;
    std::cout<<"Unesite n: ";
    std::cin>>n;
    std::cout<<"Elementi vektora su: ";
    for(int el : kvadrati(n)) std::cout<<el<<" ";
}