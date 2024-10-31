//https://codeforces.com/problemset/problem/165/B

#include <iostream>
#include <cmath>
using namespace std;

bool liniiScrise(int v, int k, int n); 

int main() {
    int n, k;
    cin >> n >> k;

   //vom cauta cu cautare binara cel mai mic v care indepineste cond. ceruta
    int left = 1;
    int right = n; //cautam pe intervalul [1,n]
    int rez = n; 

    while (left <= right) {
        int mid = (left + right) / 2;
        if (liniiScrise(mid, k, n)) { //verificam daca vasia poate sa scrie nr de linii cu v ul dat
            rez = mid; 
            right = mid - 1; //cautam un v mai mic
        }
        else {
            left = mid + 1; //cautam un v mai mare
        }
    }

    cout << rez;
    return 0;
}

bool liniiScrise(int v, int k, int n) { //functia verifica daca cu v ul ales se poate scrie nr de linii propus
    int liniiTotal = 0;
    int kp = 1;
    int linii = v;
    while (linii > 0) {
        liniiTotal += linii;
        kp *= k;
        linii = v / kp;

    }

    return liniiTotal >= n;
}
