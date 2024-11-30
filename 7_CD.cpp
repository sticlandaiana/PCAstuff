//LINK: https://open.kattis.com/problems/cd

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n{}, m{}, jack{}, jill{}, comune{ 0 };

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        unordered_set<int> cds;

       
        for (int i = 0; i < n; i++) {
            cin >> jack;
            cds.insert(jack);
        }

        
        comune = 0; // 
        for (int i = 0; i < m; i++) {
            cin >> jill;
            if (cds.find(jill) != cds.end()) {
                comune++;
            }
        }

        cout << comune << endl; 
    }

    return 0;
}
