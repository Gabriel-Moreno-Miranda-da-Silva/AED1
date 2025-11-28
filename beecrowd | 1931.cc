#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C, V;
    if (cin >> C >> V) {

        vector<vector<pair<int, int>>> adj(C + 1);

        for (int i = 0; i < V; ++i) {
            int u, v, g;
            cin >> u >> v >> g;
            adj[u].push_back({v, g});
            adj[v].push_back({u, g});
        }

        int tamanho_total = (C + 1) * 2;
        vector<int> dist(tamanho_total, -1);

        vector<bool> na_fila(tamanho_total, false);

        vector<int> fila;

        int inicio = 2;
        
        dist[inicio] = 0;
        fila.push_back(inicio);
        na_fila[inicio] = true;

        int head = 0; 

        while (head < fila.size()) {
            int atual = fila[head];
            head++;
            
            na_fila[atual] = false;

            int u = atual / 2;
            int p = atual % 2;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int peso = adj[u][i].second;

                int novo_p = 1 - p;
                int proximo = v * 2 + novo_p;
                int nova_dist = dist[atual] + peso;

                if (dist[proximo] == -1 || nova_dist < dist[proximo]) {
                    dist[proximo] = nova_dist;

                    if (!na_fila[proximo]) {
                        fila.push_back(proximo);
                        na_fila[proximo] = true;
                    }
                }
            }
        }

        cout << dist[C * 2] << endl;
    }

    return 0;
}
