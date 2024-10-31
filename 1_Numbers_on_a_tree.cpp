#include <iostream>
#include <string>
#include <cmath>
//https://open.kattis.com/problems/numbertree
using namespace std;
//pe fiecare nivel se afal 2^nivel noduri
//valoarea radacinii va fi 2^0+2^1+...+2^inaltime
// deci 2^(inaltime+1)-1
int main() {
    int h;
    string ruta;
    cin >> h >> ruta;

    // calculam valoarea radacinii
    int radacina = pow(2, h + 1)-1;
    
    int scazator=1;
    


    // pt fiecare nod se va stabili scazatorul raportat la nivelul anterior
    //iar valoarea scazatorului va creste de fiecare data
    //si se va scade la final din radacina +1 pentru a se obtine valoarea nodului

    for (char i : ruta) {
        scazator = scazator * 2;
        if (i == 'R')
            scazator++;
    }
    
    int nod = radacina - scazator + 1;
    cout <<nod << endl;
    return 0;
}
