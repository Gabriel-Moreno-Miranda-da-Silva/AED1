#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T > 0) {
		int inicio;
		cin >> inicio; // o ponto inicial

		int V, A;
		cin >> V >> A;

		// matriz pra marca arrestas contadas
		// matriz até 7x7, 49 nos, logo ela é 50x50
		int visitado[50][50];

		// zera a matriz
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				visitado[i][j] = 0;
			}
		}

		int contador = 0;

		for (int i = 0; i < A; i++) {
			int u, v;
			cin >> u >> v;

			// verifica se a aresta (u,v) ou (v,u) ja foi contada
			if (visitado[u][v] == 0 && visitado[v][u] == 0) {
				visitado[u][v] = 1;
				visitado[v][u] = 1;
				contador++;
			}
		}

		// O resultado e 2 movimentos por arresta (ida e volta)
		cout << contador * 2 << endl;

		T--;
	}

	return 0;
}
