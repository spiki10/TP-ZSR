#include <iostream>
#include <vector>
using namespace std;

int sumaCifara(int n){
    int output = 0;
    if(n<0) n*=(-1);
    while(n!=0){
        output+=(n%10);
        n/=10;
    }
    return output;
}

vector<int> fun(int n){
    vector<int> output;
    for(int i = 1; i<=n; i++)
        if(i%(sumaCifara(i))==0) 
            output.push_back(i);
    return output;
}


int main(){
    int n;
    cin>>n;
    auto result = fun(n);
    for(int i = 0; i<result.size(); i++)
        i!=result.size()-1 ? cout<<result[i]<<", " : cout<<result[i];

}