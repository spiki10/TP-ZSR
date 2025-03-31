#include <iostream>
#include <streing_view>
#include <string>
#include <exception>
// Juriceva izvedba
template <typename TipBroja>
void UnosBroja(std::string_view prompt, std::string_view upozorenje, TipBroja &broj) {
    for(;;) {
        std::cout << prompt;
        if(std::cin >> broj) {
            char sljedeci = std::cin.get();
            while(sljedeci == ' ' || sljedeci == '\t') sljedeci = std::cin.get();
            if(sljedeci == '\n') return;
        }
        std::cout << upozorenje;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}
int main(){
}
