#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, C, K;

	while (cin >> N >> M >> C >> K && (N != 0 || M != 0 || C != 0 || K != 0)) {

		vector<int> dist(N, -1);
		vector<bool> visitado(N, false);
		vector<vector<int>> adj(N, vector<int>(N, -1));

		for (int i = 0; i < M; i++) {
			int u, v, p;
			cin >> u >> v >> p;
			if (adj[u][v] == -1 || adj[u][v] > p) {
				adj[u][v] = p;
				adj[v][u] = p;
			}
		}

		dist[K] = 0;

		for (int i = 0; i < N; i++) {
			int u = -1;
			for (int j = 0; j < N; j++) {
				if (!visitado[j] && dist[j] != -1) {
					if (u == -1 || dist[j] < dist[u]) {
						u = j;
					}
				}
			}

			if (u == -1) break;
			visitado[u] = true;
			if (u < C - 1) {
				if (adj[u][u+1] != -1) {
					int peso = adj[u][u+1];
					int novaDist = dist[u] + peso;
					if (dist[u+1] == -1 || novaDist < dist[u+1]) {
						dist[u+1] = novaDist;
					}
				}
			}
			else {
				for (int v = 0; v < N; v++) {
					if (adj[u][v] != -1 && !visitado[v]) {
						int novaDist = dist[u] + adj[u][v];
						if (dist[v] == -1 || novaDist < dist[v]) {
							dist[v] = novaDist;
						}
					}
				}
			}
		}

		cout << dist[C-1] << endl;
	}

	return 0;
}
