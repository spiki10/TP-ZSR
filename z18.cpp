#include <iostream>
#include <vector>
typedef std::vector<int> vektor;

vektor fun(int *p, int vel){
    int start=0;
    vektor output;
    for(int i = 0;i<vel;i++)
        output.push_back(p[i]);
    for(int i = 0; i < vel; i++){
        if(output[i]%2==0){
            int tmp = output[i];
            output.erase(output.begin()+i); // key thing
            output.insert(output.begin()+start,tmp); // the other key thing
            start++;
        }
    }
    return output;
}


int main(){
    int niz[10];
    std::cout<<"Unesite 10 elemenata niza: ";
    for(int i = 0; i<10; i++){
        int n;
        std::cin>>n;
        niz[i] = n;
    }
    for(int el : fun(niz,10)) std::cout<<el<<" ";
}