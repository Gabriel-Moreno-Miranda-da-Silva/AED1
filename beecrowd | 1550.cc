#include <iostream>
#include <vector>

using namespace std;

int inverter(int n) {
    int invertido = 0;
    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n = n / 10;
    }
    return invertido;
}

int bfs(int inicio, int fim) {
    vector<int> dist(10000, -1);
    vector<int> fila;

    fila.push_back(inicio);
    dist[inicio] = 0;

    int head = 0;

    while (head < fila.size()) {
        int atual = fila[head];
        head++;

        if (atual == fim) {
            return dist[atual];
        }

        int proximo = atual + 1;
        if (proximo <= 10000 && dist[proximo] == -1) {
            dist[proximo] = dist[atual] + 1;
            fila.push_back(proximo);
        }

        proximo = inverter(atual);
        if (proximo <= 10000 && dist[proximo] == -1) {
            dist[proximo] = dist[atual] + 1;
            fila.push_back(proximo);
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << bfs(A, B) << endl;
    }

    return 0;
}
