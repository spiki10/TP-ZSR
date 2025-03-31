#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>


bool DaLiJeSimetrican(std::string s) {
    for(int i = 0, j = s.length() - 1; i < j; i++, j--)
        if(s[i] != s[j]) return false;
        return true;
}

std::vector<std::string> NadjiSimetricnePodstringove(std::string s) {
    std::vector<std::string> simetricni;
    for(int i = 0; i < s.length(); i++)
        for(int k = 2; k <= s.length() - i; k++)
            if(std::string podstring = s.substr(i, k); DaLiJeSimetrican(podstring))
                simetricni.push_back(podstring);
    return simetricni;
}

// std::vector<std::string> NadjiSimetricnePodstringove(const std::string &s) {
//     std::vector<std::string> simetricni;
//     for(int i = 0; i < s.length() - 1; i++) {
//         std::string podstring(1, s[i]);
//         for(int j = i + 1; j < s.length(); j++) {
//             podstring += s[j];
//             if(DaLiJeSimetrican(podstring)) simetricni.push_back(podstring)
//         }
//     }
//     return simetricni;
// }




int main() {
    std::cout << "Unesite string: ";
    std::string s;
    std::getline(std::cin, s);
    std::cout << "Simetricni podstringovi:\n";
    for(auto e : NadjiSimetricnePodstringove(s)) std::cout << e << std::endl;
    return 0;
}


