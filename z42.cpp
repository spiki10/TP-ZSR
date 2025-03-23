#include <iostream>
#include <vector>

typedef std::vector<int> vektor;

vektor NajduziMonotoniPodniz(vektor &v){
    vektor output;
    int start = 0, end = 1,vel = 0;
    int bitnistart(0), bitniend(0);
    bool flag = (v[1] > v[0]);

    while(end<v.size()){
        if(flag)
            while(end<v.size() && v[end-1]<=v[end]) end++;
        else
            while(end<v.size() && v[end-1]>=v[end]) end++;

        if(end - start > vel){
            bitniend = end;
            bitnistart = start;
            vel = bitniend - bitnistart;
        }

        start = end-1;
        end++;
        flag = !flag;
    }
    for(int i = bitnistart; i<bitniend && i<v.size(); i++)
        output.push_back(v[i]);
    return output;
}




int main(){
    std::cout<<"Unesite elemente vektora: "<<std::endl;
    vektor v;
    while(true){
        int n;
        std::cin>>n;
        if(!std::cin) break;
        v.push_back(n);
    }
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    for(int el : NajduziMonotoniPodniz(v)) std::cout<<el<<" ";
}