#include <iostream>

using namespace std;

bool desistiu[100001];
int filaInicial[50000];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> filaInicial[i];
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int idDesistente;
        cin >> idDesistente;
        desistiu[idDesistente] = true;
    }

    bool primeiroImpresso = true;
    for (int i = 0; i < N; i++) {
        int idAtual = filaInicial[i];
        
        if (!desistiu[idAtual]) {
            if (primeiroImpresso) {
                cout << idAtual;
                primeiroImpresso = false;
            } else {
                cout << " " << idAtual;
            }
        }
    }
    cout << endl;

    return 0;
}
