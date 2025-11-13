#include <iostream>

using namespace std;

int main() {
	int N_casos_teste;
	cin >> N_casos_teste;

	for (int caso = 0; caso < N_casos_teste; ++caso) {
		int M_alunos;
		cin >> M_alunos;

		int ordem_chegada[1000];
		int ordem_reordenada[1000];

		for (int i = 0; i < M_alunos; ++i) {
			cin >> ordem_chegada[i];
			ordem_reordenada[i] = ordem_chegada[i];
		}

		for (int i = 0; i < M_alunos - 1; ++i) {
			for (int j = 0; j < M_alunos - i - 1; ++j) {
				if (ordem_reordenada[j] < ordem_reordenada[j + 1]) {
					int temp = ordem_reordenada[j];
					ordem_reordenada[j] = ordem_reordenada[j + 1];
					ordem_reordenada[j + 1] = temp;
				}
			}
		}

		int contador_iguais = 0;
		for (int i = 0; i < M_alunos; ++i) {
			if (ordem_chegada[i] == ordem_reordenada[i]) {
				contador_iguais++;
			}
		}

		cout << contador_iguais << endl;
	}

	return 0;
}
