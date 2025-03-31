#include <iostream>
#include <string>
#include <vector>

enum class Smjer {Nadesno, Nalijevo};
enum class Pravci {Sjever, Istok, Jug, Zapad};

void Idi(int &x, int &y, Pravci orijentacija, int korak);
void Rotiraj(Pravci &orijentacija, Smjer na_koju_stranu);
void IspisiPoziciju(int x, int y, Pravci orijentacija);

void Idi(int &x, int &y, Pravci orijentacija, int korak) {
    int dx[]{0, 1, 0, -1}, dy[]{1, 0, -1, 0};
    x += korak * dx[int(orijentacija)]; y += korak * dy[int(orijentacija)];
}

void Rotiraj(Pravci &orijentacija, Smjer na_koju_stranu) {
    orijentacija = Pravci((int(orijentacija) + 2 * int(na_koju_stranu) + 1) % 4);
}

void IspisiPoziciju(int x, int y, Pravci orijentacija) {
    const char *tekstovi[]{"Sjever", "Istok", "Jug", "Zapad"};
    std::cout << "Robot se nalazi na poziciji (" << x << ", " << y << ") i gleda na "
    << tekstovi[int(orijentacija)] << ".\n";
}


int main() {
    int x = 0, y = 0;
    Pravci orijentacija = Pravci::Sjever;
    Idi(x, y, 5);
    Rotiraj(orijentacija, Smjer::Nalijevo);
    Idi(x, y, 3);
    IspisiPoziciju(x, y, orijentacija);
    return 0;
}
