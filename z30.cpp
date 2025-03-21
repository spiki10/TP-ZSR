#include <iostream>
#include <vector>
using namespace std;

void fun(vector<int> &v) {
    int i = 0;
    while (i < v.size()) {
        int copy = v[i];
        int first_parity = (copy % 10) % 2;
        bool same_parity = true;
        
        while (copy > 0) {
            if ((copy % 10) % 2 != first_parity) {
                same_parity = false;
                break; 
            }
            copy /= 10;
        }

        if (same_parity) { 
            for (int j = i; j < v.size() - 1; j++) 
                v[j] = v[j + 1];
            v.resize(v.size() - 1);
        } else {
            i++; 
        }
    }
}

int main() {
    int n;
    cout << "Unesite velicinu vektora: ";
    cin >> n;
    vector<int> v(n);
    
    cout << "Unesite elemente vektora: ";
    for (int &el : v) cin >> el;

    fun(v);

    cout << "Vektor nakon odstranjivanja: ";
    for (int el : v) cout << el << " ";
    cout << endl;

    return 0;
}
