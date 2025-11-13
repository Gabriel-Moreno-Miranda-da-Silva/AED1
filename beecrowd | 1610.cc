#include <iostream>

using namespace std;

const int MAX_N = 10005; // documentos
const int MAX_M = 30005; // dependências

// Estrutura da Lista de Adjacência
int cabeca[MAX_N];        
int destino[MAX_M];       
int proxima[MAX_M];       
int contador_arestas;     

// 0 = Branco, 1 = Cinza, 2 = Preto
int cor[MAX_N]; 

void adicionar_aresta(int u, int v) {
    destino[contador_arestas] = v;
    proxima[contador_arestas] = cabeca[u]; 
    cabeca[u] = contador_arestas;          
    contador_arestas++;
}

bool dfs(int atual) {
    cor[atual] = 1;

    for (int i = cabeca[atual]; i != -1; i = proxima[i]) {
        int vizinho = destino[i];
        
        if (cor[vizinho] == 1) return true;
        
        if (cor[vizinho] == 0) {
            if (dfs(vizinho)) return true;
        }
    }

    cor[atual] = 2;
    return false;
}

int main() {
    int T, N, M, A, B;
    cin >> T;

    while (T--) {
        cin >> N >> M;

        contador_arestas = 0;
        for (int i = 0; i <= N; i++) {
            cabeca[i] = -1; 
            cor[i] = 0;     
        }

        while (M--) {
            cin >> A >> B;
            adicionar_aresta(A, B);
        }

        bool loop = false;
        for (int i = 1; i <= N; i++) {
            if (cor[i] == 0) {
                if (dfs(i)) {
                    loop = true;
                    break;
                }
            }
        }

        if (loop) cout << "SIM" << endl;
        else cout << "NAO" << endl;
    }

    return 0;
}
