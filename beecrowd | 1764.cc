#include <iostream>

using namespace std;

struct Rota {
    int u, v, distancia;
};

const int MAX_M = 40000;
const int MAX_N = 50000;

Rota rotas[MAX_N];
int pai[MAX_M];

void troca(Rota &a, Rota &b) {
    Rota temp = a;
    a = b;
    b = temp;
}

void quickSort(int left, int right) {
    if (left >= right) return;

    int pivo = rotas[(left + right) / 2].distancia;
    int i = left, j = right;

    while (i <= j) {
        while (rotas[i].distancia < pivo) i++;
        while (rotas[j].distancia > pivo) j--;
        if (i <= j) {
            troca(rotas[i], rotas[j]);
            i++;
            j--;
        }
    }
    quickSort(left, j);
    quickSort(i, right);
}

int find(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = find(pai[i]);
}

void unite(int i, int j) {
    int raiz_i = find(i);
    int raiz_j = find(j);
    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
    }
}

int main() {

    int M, N;

    while (cin >> M >> N && (M != 0 || N != 0)) {
        
        for (int i = 0; i < N; i++) {
            cin >> rotas[i].u >> rotas[i].v >> rotas[i].distancia;
        }

        quickSort(0, N - 1);

        for (int i = 0; i < M; i++) {
            pai[i] = i;
        }

        int custo_total = 0;
        int arestas_usadas = 0;

        for (int i = 0; i < N; i++) {
            int u = rotas[i].u;
            int v = rotas[i].v;
            int w = rotas[i].distancia;

            if (find(u) != find(v)) {
                unite(u, v);      
                custo_total += w;
                arestas_usadas++;
            }
            
            if (arestas_usadas == M - 1) break; 
        }

        cout << custo_total << endl;
    }

    return 0;
}
