///LINK: https://codeforces.com/contest/2/problem/A


//mike 3
//andrew 5
//mike 2
//ne vom folosi de map-uri pentru a stoca numele jucatorului
//si scorul aferent
//pentru a inregistra numele si scorul folosim un vector de perechi
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<string, int> scor; 
     
    int n;
    cin >> n;

    string nume;
    string winner;
    int puncte;

    vector<pair<string, int>> ordine;
    for (int i = 0; i < n; i++) {
        cin >> nume >> puncte;
        scor[nume] += puncte; 

        //adaugam informatiile in vectorul de perechi
        //vect. va contine toate act. de scor in ordi. procesarii
        //{"mike", 3}, {"andrew", 5}, {"mike", 2}
        ordine.push_back({ nume, scor[nume] });
    }

    
    int maximScor = INT_MIN;

    //cautam prin map cel mai mare punctaj (cu .second, adica valoarea asociata cheii)
    for (const auto& pair : scor) {
        if (pair.second > maximScor) {
            maximScor = pair.second;
        }
    }

    
    //il cautam pe jucatorul cu scorul maxim (cu cheia .first) si cand il gasim
    //iesim ca sa-l luam fix pe primul
    for (const auto& p : ordine) {
        if (scor[p.first] == maximScor) {
            winner = p.first; 
            break;
        }
    }

    cout << winner;
    return 0;
}
