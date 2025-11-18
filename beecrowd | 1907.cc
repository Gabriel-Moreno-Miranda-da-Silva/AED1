#include <iostream>
#include <sys/resource.h>
using namespace std;

int N, M;

bool Verifica(int x, int y, int **matriz) {
    if (x < 0 || x >= N || y < 0 || y >= M) return false;

    if(matriz[x][y] == 1){
        matriz[x][y] = 0;
        
        Verifica(x+1, y, matriz);
        Verifica(x-1, y, matriz);
        Verifica(x, y+1, matriz);
        Verifica(x, y-1, matriz);
        
        return true;
    }
    
    return false;
}

int main() {
    // --- TRUQUE PARA AUMENTAR A PILHA (Stack) ---
    // Isso permite que a recursão vá muito fundo sem crashar.
    // Funciona em juízes online baseados em Linux (Beecrowd, Codeforces, etc).
    const rlim_t kStackSize = 64 * 1024 * 1024;   // Define o alvo para 64MB
    struct rlimit rl;
    int result;
    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0) {
        if (rl.rlim_cur < kStackSize) {
            rl.rlim_cur = kStackSize;
            setrlimit(RLIMIT_STACK, &rl);
        }
    }
    // --------------------------------------------
    
    cin >> N >> M;
    
    int **matriz = new int*[N]; 
    for(int i = 0; i < N; i++) {
        matriz[i] = new int[M];
    }
    
    char C;
    int cliques = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> C;
            if(C == '.') {
                matriz[i][j] = 1;
            }
            else {
                matriz[i][j] = 0;
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(Verifica( i, j, matriz)) {
                cliques++;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    cout << cliques << endl;

    return 0;
}
