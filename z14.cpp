#include <iostream>
#include <vector>

typedef std::vector<int> vektor;

vektor djelioci(int n){
    vektor output;
    for(int i = 2; i<n; i++)
        if(n%i==0)
            output.push_back(i);
    return output;
}

int main(){
    int n;
    std::cout<<"Unesite n: ";
    std::cin>>n;
    std::cout<<"Svi djelioci broja "<<n<<" su: ";
    for(int el : djelioci(n)) std::cout<<el<<" ";
}
