#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int main() {
    int planets{}, stargates{};
    int w{}, v{}, sec{};

    cin >> planets >> stargates;

    // Initializarea matricei de adiacență
    vector<vector<int>> graph(planets+1, vector<int>(planets+1, INT_MAX));
    vector<queue<int>> occupied(planets + 1);

    // Setarea valorilor pe diagonala principala la 0 (distanta de la un nod la el insusi)
    for (int i{ 1 }; i < planets+1; i++) {
        graph.at(i).at(i) = 0;
    }

    // Citirea muchiilor
    for (int i{ 1 }; i < stargates+1; i++) {
        cin >> w >> v >> sec;

        graph.at(w).at(v) = sec;
        graph.at(v).at(w) = sec;
    }

    // Afișarea matricei
    //for (int i{ 1 }; i < planets+1; i++) {
    //    for (int j{ 1 }; j < planets+1; j++) {
    //        if (graph.at(i).at(j) == INT_MAX) {
    //            cout << "INF ";  // Afișează INF pentru distanțele inaccesibile
    //        }
    //        else {
    //            cout << graph.at(i).at(j) << " ";
    //        }
    //    }
    //    cout << endl;
    //}

    vector<int> dist(planets+1,INT_MAX);
    vector<bool> added(planets + 1, false);

    dist[1] = 0; //se porneste de la planeta 1
    int travellers{}, numOfTravellers{};

    for (int i{ 1 }; i < planets + 1; i++) {
        //planeta cu dist minima
        int min = INT_MAX, u = -1;
        for (int i = 1; i <= planets; i++) {
            if (!added[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }


        added[u] = true;
        
        cin >> numOfTravellers;

        while (numOfTravellers) {
            cin >> travellers;
            occupied[u].push(travellers);

            numOfTravellers--;
        }

        //verificam daca astronautul trebuie sa astepte
        if (!occupied[u].empty() && dist[u] == occupied[u].front()) {
            dist[u]++;
            occupied[u].pop();
        }

        for (int v = 1; v <= planets; v++) {
            if (!added[v] && graph[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    if (dist[planets] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << dist[planets];
    }
   
    return 0;
}

