
//LINK:https://open.kattis.com/problems/doctorkattis
#include <iostream>
#include <string>
#include <queue> //vom folosi un priority_queue
#include <unordered_map>
using namespace std;


struct Pacient {
    string nume;
    int infectie;
    int ordine;

    bool operator<(const Pacient& other) const {
        if (infectie == other.infectie) { //daca infc. sunt egale mentinem ordinea
            return ordine > other.ordine; //pisica care a fost adaugata prima are ordine mai mare
        }
        return infectie < other.infectie; 
    }
    //obiectul other e o pisica mai veche cu care comparam pisica curenta
};

int main() {
    int n;
    cin >> n; // nr de comenzi

    //folosim unordered_map pt un timp de acces mai mic O(1) [map foloseste BST cu timp log(n)]
    //deci mai eficient pt inserare si cautare
    unordered_map<string, Pacient> pacient; // pacientul și informațiile sale
    //folosim un priority queue ca sa le avem in ordine (descrescatoare) automat
    priority_queue<Pacient> pq;
    int current_order = 0;

    int comanda;
    int infectie;
    string nume;

    for (int i = 0; i < n; i++) {
        cin >> comanda;
        if (comanda == 0) {
            cin >> nume >> infectie;
            Pacient p = { nume, infectie, current_order++ }; //stocam datele noului pacient
            pacient[nume] = p; //adaugam obientul in map
            pq.push(p); //adaugam obc. in priority_queue
        }
        else if (comanda == 1) {
            cin >> nume >> infectie;
            pacient[nume].infectie += infectie;
            pq.push(pacient[nume]); // adaugam actualizarea, fara a sterge ceva
        }
        else if (comanda == 2) {
            cin >> nume;
            pacient.erase(nume); //stergem pisica din map
        }
        else { // comanda == 3
            //verificam daca varful cozii are o infectie diferita fata de cea actualizata din mapa
            while (!pq.empty() && pacient[pq.top().nume].infectie != pq.top().infectie) {
                pq.pop(); // eliminam acele intrari depsite care au fost actualizate mai in fata
            }
            if (pq.empty()) {
                cout << "The clinic is empty" << endl;
            }
            else {
                cout << pq.top().nume << endl; // pisica cu cea mai mare infecție
            }
        }
    }
    return 0;
}

//VARIANTA 2 -invalid
// ** am incercat sa folosesc un multiset pentru a stoca pisicile in ordine crescatoare dupa infectii
// si pt a evida cele doua bucle for din prima varianta
// dar pentru a actualiza un element intr-n multiset, acesta trebuie sters si reintrodus
// fapt ce perturba ordinea de intrare in clinica a pisicilor
//#include <iostream>
//#include <string>
//#include <set>
//#include <map>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n; // nr de comenzi
//
//    map<string, int> pacient; // pacientul si infectia sa
//    multiset<pair<int, string>> ordine; // infecția și numele
//
//    int comanda;
//    int infectie;
//    string nume;
//
//    for (int i = 0; i < n; i++) {
//        cin >> comanda;
//        if (comanda == 0) {
//            cin >> nume >> infectie;
//            pacient[nume] = infectie;
//            ordine.insert({ infectie, nume });
//        }
//        else if (comanda == 1) {
//            cin >> nume >> infectie;
//            auto it = ordine.find({ pacient[nume], nume });
//            if (it != ordine.end()) {
//                ordine.erase(it);
//                pacient[nume] += infectie;
//                ordine.insert({ pacient[nume], nume });
//            }
//        }
//        else if (comanda == 2) {
//            cin >> nume;
//            auto it = ordine.find({ pacient[nume], nume });
//            if (it != ordine.end()) {
//                ordine.erase(it);
//                pacient.erase(nume);
//            }
//        }
//        else { // comanda == 3
//            if (ordine.empty()) {
//                cout << "The clinic is empty" << endl;
//            }
//            else {
//                cout << (*ordine.rbegin()).second << endl; // pisica cu cea mai mare infecție
//            }
//        }
//    }
//    return 0;
//}


//VARIANTA 1
//SOLUTIE INEFICIENTA CA TIMP pt ca se foloseste un vector pt ordine
// si se parcurge de doua ori pt a afla maximul si prima pisica cu infectia maxima
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//	using namespace std;
//
//	int main() {
//
//		int n;
//		map <string, int> pacient; //stocam nume si infectie
//		vector<string> ordine;
//		cin >> n; //nr comenzi
//		int comanda;
//		int infectie;
//		string nume;
//
//		for (int i = 0; i < n; i++)
//		{
//			cin >> comanda;
//			if (comanda == 0)
//			{
//				cin >> nume >> infectie;
//				pacient[nume] = infectie;
//				ordine.push_back(nume);
//			}
//			else if (comanda == 1) {
//				cin >> nume >> infectie;
//				pacient[nume] += infectie;
//
//			}
//			else if (comanda == 2) {
//				cin >> nume;
//				pacient.erase(nume);//stergem cheia coresp. pisicii
//
//				//cautam prin vector numarul de ordine al pisicului
//				auto ipisic = find(ordine.begin(), ordine.end(), nume);
//
//				//stergem pisica
//				if (ipisic != ordine.end()) {
//					ordine.erase(ipisic);
//				}
//			}
//			else {//comanda==3
//
//				if (pacient.empty())
//					cout << "The clinic is empty" << endl;
//				else {
//					int maxim = 0;
//					for (auto pisic : pacient) {
//						if (pisic.second > maxim) {
//							maxim = pisic.second;
//						}
//					}
//					for (auto numepisic : ordine) {
//						if (pacient[numepisic] == maxim) {
//							cout << numepisic << endl;
//							break;
//						}
//
//					}
//				}
//
//			}
//		}
//		return 0;
//	}
//}