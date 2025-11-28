#include <iostream>

using namespace std;

struct No {
    int valor;
    No *esq;
    No *dir;
};

No *criarNo(int v) {
    No *novo = new No;
    novo->valor = v;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir(No *raiz, int v) {
    if (raiz == NULL) {
        return criarNo(v);
    }
    if (v < raiz->valor) {
        raiz->esq = inserir(raiz->esq, v);
    } else {
        raiz->dir = inserir(raiz->dir, v);
    }
    return raiz;
}

No *fila[500];
int inicio_fila = 0;
int fim_fila = 0;

void bfs(No* raiz) {
    inicio_fila = 0;
    fim_fila = 0;

    if (raiz != NULL) {
        fila[fim_fila] = raiz;
        fim_fila++;
    }

    bool primeiro = true;

    while (inicio_fila < fim_fila) {
        No* atual = fila[inicio_fila];
        inicio_fila++;

        if (primeiro) {
            cout << atual->valor;
            primeiro = false;
        } else {
            cout << " " << atual->valor;
        }

        if (atual->esq != NULL) {
            fila[fim_fila] = atual->esq;
            fim_fila++;
        }
        if (atual->dir != NULL) {
            fila[fim_fila] = atual->dir;
            fim_fila++;
        }
    }
}

void liberarArvore(No* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    delete raiz;
}

int main() {
    int C;
    cin >> C;

    for (int i = 1; i <= C; i++) {
        int N;
        cin >> N;

        No* raiz = NULL;
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            raiz = inserir(raiz, val);
        }

        cout << "Case " << i << ":" << endl;
        bfs(raiz);
        cout << endl << endl;

        liberarArvore(raiz);
    }

    return 0;
}
