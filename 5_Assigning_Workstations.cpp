//https://open.kattis.com/problems/workstations


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n; //numarul de oameni de stiinta
    int m; //numarul de minute dupa care se inchide worstation-ul
    cin >> n >> m;
    vector<pair<int, int>> cercetatori(n); //folosim un vector de perechi pentru a salva atat momentul sosirii cat si numarul de minute petrecute

    int a; //omul de stiinta ajunge dupa a minute
    int s; //sta s minute


    for (int i = 0; i < n; i++) {
        cin >> a >> s;
        cercetatori[i].first = a;
        cercetatori[i].second = s; 
    }

    //ordonam cercetatorii dupa momentul sosirii
    sort(cercetatori.begin(), cercetatori.end());




    multiset<int> available_workstations;
    int saved_unlocks = 0;

    for (auto& researcher : cercetatori) {
        int sosire = researcher.first;
        int durata = researcher.second;

        //verificam daca avem o statie disponibila
        auto it = available_workstations.lower_bound(sosire - m);

       //*ti ----comparam obiectul, nu iteratorul
        if (it != available_workstations.end() && *it <= sosire) {
            saved_unlocks++;
            available_workstations.erase(it);
        }

       
        available_workstations.insert(sosire + durata);
    }

    cout << saved_unlocks << endl;
    return 0;
}
