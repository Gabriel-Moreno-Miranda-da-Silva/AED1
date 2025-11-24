#include <iostream>

using namespace std;

// estrutura de cada no
struct No {
    int valor;
    No *esquerda;
    No *direita;
};

// cria um no novo
No *criarNo(int v) {
    No* novoNo = new No;
    novoNo->valor = v;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// insere um valor na arvore
No *inserir(No *raiz, int v) {
    if (raiz == NULL) {
        return criarNo(v);
    }
    if (v < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, v);
    } else {
        raiz->direita = inserir(raiz->direita, v);
    }
    return raiz;
}

// Pre-ordem. Raiz > Esquerda > Direita
void preOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    cout << " " << raiz->valor;
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

// Em-ordem. Esquerda > Raiz > Direita
void inOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    inOrdem(raiz->esquerda);
    cout << " " << raiz->valor;
    inOrdem(raiz->direita);
}

// Pos-ordem. Esquerda > Direita > Raiz
void posOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    cout << " " << raiz->valor;
}

// liberar a memoria da arvore
void liberarArvore(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    delete raiz;
}

int main() {
    int C; // Numero de casos
    cin >> C;
    
    for (int i = 1; i <= C; i++) {
        int N; // Numero de nós
        cin >> N;
        
        No* raiz = NULL;
        for (int j = 0; j < N; j++) {
            int valor;
            cin >> valor;
            raiz = inserir(raiz, valor);
        }

        cout << "Case " << i << ":" << endl;
        
        // Pre-ordem
        cout << "Pre.:";
        preOrdem(raiz);
        cout << endl;

        // Em-ordem
        cout << "In..:";
        inOrdem(raiz);
        cout << endl;

        // Pos-ordem
        cout << "Post:";
        posOrdem(raiz);
        cout << endl;

        // Linha em branco extra
        cout << endl;
        
        // Libera a memoria
        liberarArvore(raiz);
    }
    
    return 0;
}
