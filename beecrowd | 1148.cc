#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, E;
    
    while (cin >> N >> E && (N != 0 || E != 0)) {
        
        vector<vector<int>> dist(N + 1, vector<int>(N + 1, -1));

        for (int i = 1; i <= N; ++i) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < E; ++i) {
            int u, v, h;
            cin >> u >> v >> h;
            
            if (dist[u][v] == -1 || dist[u][v] > h) {
                dist[u][v] = h;
            }
        }

        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= N; ++j) {
                    
                    if (dist[i][k] != -1 && dist[k][j] != -1) {
                        int novaDist = dist[i][k] + dist[k][j];
                        
                        if (dist[i][j] == -1 || dist[i][j] > novaDist) {
                            dist[i][j] = novaDist;
                        }
                    }
                    
                }
            }
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][j] != -1 && dist[j][i] != -1) {
                    dist[i][j] = 0;
                }
            }
        }

        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= N; ++j) {
                    
                    if (dist[i][k] != -1 && dist[k][j] != -1) {
                        int novaDist = dist[i][k] + dist[k][j];
                        
                        if (dist[i][j] == -1 || dist[i][j] > novaDist) {
                            dist[i][j] = novaDist;
                        }
                    }
                    
                }
            }
        }

        int K;
        cin >> K;
        while (K--) {
            int O, D;
            cin >> O >> D;
            
            if (dist[O][D] == -1) {
                cout << "Nao e possivel entregar a carta" << endl;
            } else {
                cout << dist[O][D] << endl;
            }
        }
        
        cout << endl;
    }

    return 0;
}
