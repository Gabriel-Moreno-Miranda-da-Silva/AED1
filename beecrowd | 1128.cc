#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>>& grafo, vector<bool>& visitado, int& contagem) {
    visitado[u] = true;
    contagem++;

    for (int v : grafo[u]) {
        if (!visitado[v]) {
            dfs(v, grafo, visitado, contagem);
        }
    }
}

int main() {
    int N, M;
    while (cin >> N >> M && (N != 0 || M != 0)) {
        vector<vector<int>> adj(N + 1);
        vector<vector<int>> rev_adj(N + 1);

        for (int i = 0; i < M; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            
            adj[u].push_back(v);
            rev_adj[v].push_back(u);

            if (p == 2) {
                adj[v].push_back(u);
                rev_adj[u].push_back(v);
            }
        }

        vector<bool> visitado1(N + 1, false);
        int alcançados1 = 0;
        
        dfs(1, adj, visitado1, alcançados1);

        if (alcançados1 < N) {
            cout << 0 << endl;
        } 
        else {
            vector<bool> visitado2(N + 1, false);
            int alcançados2 = 0;

            dfs(1, rev_adj, visitado2, alcançados2);

            if (alcançados2 < N) {
                cout << 0 << endl; 
            } else {
                cout << 1 << endl;
            }
        }
    }

    return 0;
}
