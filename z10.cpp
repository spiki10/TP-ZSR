#include <iostream>
#include <vector>
#include <string>
#include <cctype>
// moja izvedba
bool isPalindrome(const std::string &s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
        if (std::toupper(s[i]) != std::toupper(s[j])) return false;
    }
    return true;
}

std::vector<std::string> IzdvojiSimetricneRijeci1(const std::string &s) {
    std::vector<std::string> output;

    for (int i = 0; i < s.length(); i++) {
        while (i < s.length() && s[i] == ' ') i++;
        int start = i;
        while (i < s.length() && std::isalpha(s[i])) i++;
        std::string word = s.substr(start, i - start);
        if (!word.empty() && word.length() > 1 && isPalindrome(word))
            output.push_back(word);
    }

    return output;
}


// Juriceva izvedba stvari
bool DaLiJeSimetricna(std::string rijec) {
    int duzina = rijec.length();
    for(int i = 0; i <= duzina / 2; i++)
        if(std::toupper(rijec[i]) != std::toupper(rijec[duzina - 1 - i])) return false;
        return true;
}

std::vector<std::string> IzdvojiSimetricneRijeci(std::string s) {
    std::vector<std::string> v;
    for(int i = 0; i < s.length(); i++)
        if(std::isalpha(s[i]) && (i == 0 || !std::isalpha(s[i - 1]))) {
            std::string rijec;
            while(i < s.length() && std::isalpha(s[i])) rijec += s[i++];
            if(rijec.length() >= 2 && DaLiJeSimetricna(rijec)) v.push_back(rijec);
        }
        return v;
}

int main() {
    std::cout << "Unesite string: ";
    std::string s;
    std::getline(std::cin, s);

    auto result = IzdvojiSimetricneRijeci(s);

    if (!result.empty()) {
        std::cout << "Simetricne rijeci: ";
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) std::cout << ", ";
            std::cout << result[i];
        }
        std::cout << std::endl;
    } else {
        std::cout << "Nema simetricnih rijeci!" << std::endl;
    }

    return 0;
}
