#include <iostream>

using namespace std;

int adj[26][26]; //lista de adjacencia
int grau[26]; //numero de vizinhos

int visitado[26];

// lista temporaria pra ordenar e imprimir os componentes
int lista[30];
int tam_lista;

void dfs(int u) {
	visitado[u] = 1;

	lista[tam_lista] = u;
	tam_lista++;

	for (int i = 0; i < grau[u]; i++) {
		int v = adj[u][i];
		if (visitado[v] == 0) {
			dfs(v);
		}
	}
}

// ordena na ordem alfabetica
void ordenar_lista() {
	for (int i = 0; i < tam_lista - 1; i++) {
		for (int j = 0; j < tam_lista - i - 1; j++) {
			if (lista[j] > lista[j + 1]) {
				int temp = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = temp;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int caso = 1; caso <= N; caso++) {
		int V, E;
		cin >> V >> E;

		for (int i = 0; i < 30; i++) {
			visitado[i] = 0;
			grau[i] = 0;
		}

		for (int i = 0; i < E; i++) {
			char u_char, v_char;
			cin >> u_char >> v_char;

			int u = u_char - 'a';
			int v = v_char - 'a';

			// adiciona v na lista de u
			adj[u][grau[u]] = v;
			grau[u]++;

			// adiciona u na lista de v
			adj[v][grau[v]] = u;
			grau[v]++;
		}

		cout << "Case #" << caso << ":" << endl;

		int qtd_componentes = 0;

		for (int i = 0; i < V; i++) {
			if (visitado[i] == 0) {
				qtd_componentes++;
				tam_lista = 0;

				dfs(i);

				ordenar_lista();

				for (int j = 0; j < tam_lista; j++) {
					cout << (char)('a' + lista[j]) << ",";
				}
				cout << endl;
			}
		}

		cout << qtd_componentes << " connected components" << endl;
		cout << endl;
	}

	return 0;
}
