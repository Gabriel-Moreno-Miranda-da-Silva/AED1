#include <iostream>

using namespace std;

// estrutura de cada no
struct No {
    char valor; 
    No *esquerda;
    No *direita;
};

// cria um no novo
No *criarNo(char v) { 
    No *novoNo = new No;
    novoNo->valor = v;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// insere um valor na arvore
No *inserir(No *raiz, char v) { 
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

// Pesquisa um valor na arvore
bool pesquisar(No *raiz, char v) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->valor == v) {
        return true;
    }
    if (v < raiz->valor) {
        return pesquisar(raiz->esquerda, v);
    } else {
        return pesquisar(raiz->direita, v);
    }
}

// Pre-ordem. Raiz > Esquerda > Direita
void preOrdem(No *raiz, bool &primeiro) {
    if (raiz == NULL) {
        return;
    }
    if (primeiro) {
        cout << raiz->valor;
        primeiro = false;
    } else {
        cout << " " << raiz->valor;
    }
    preOrdem(raiz->esquerda, primeiro);
    preOrdem(raiz->direita, primeiro);
}

// Em-ordem. Esquerda > Raiz > Direita
void inOrdem(No *raiz, bool &primeiro) {
    if (raiz == NULL) {
        return;
    }
    inOrdem(raiz->esquerda, primeiro);
    if (primeiro) {
        cout << raiz->valor;
        primeiro = false;
    } else {
        cout << " " << raiz->valor;
    }
    inOrdem(raiz->direita, primeiro);
}

// Pos-ordem. Esquerda > Direita > Raiz
void posOrdem(No *raiz, bool &primeiro) {
    if (raiz == NULL) {
        return;
    }
    posOrdem(raiz->esquerda, primeiro);
    posOrdem(raiz->direita, primeiro);
    if (primeiro) {
        cout << raiz->valor;
        primeiro = false;
    } else {
        cout << " " << raiz->valor;
    }
}

// liberar a memoria da arvore
void liberarArvore(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    delete raiz;
}

int main() {
    char comando[20]; 
    No* raiz = NULL;
    
    // Lê comandos
    while(cin >> comando) {
        
        // Compara o primeiro caractere
        if (comando[0] == 'I') {
            // Checa se e 'I' ou 'INFIXA'
            if (comando[1] == '\0') { // '\0' é o caractere nulo de fim de string
                char valor;
                cin >> valor;
                raiz = inserir(raiz, valor);
            } else {
                bool primeiro = true;
                inOrdem(raiz, primeiro);
                cout << endl;
            }
        }
        else if (comando[0] == 'P') {
            // Checa se e 'P', 'PREFIXA' ou 'POSFIXA'
            if (comando[1] == '\0') {
                char valor;
                cin >> valor;
                if (pesquisar(raiz, valor)) {
                    cout << valor << " existe" << endl;
                } else {
                    cout << valor << " nao existe" << endl;
                }
            } 
            // 'E' de prEfixa
            else if (comando[2] == 'E') { 
                bool primeiro = true;
                preOrdem(raiz, primeiro);
                cout << endl;
            } 
            // 'O' de pOsfixa
            else { 
                bool primeiro = true;
                posOrdem(raiz, primeiro);
                cout << endl;
            }
        }
    }
    
    // Libera a memoria no final
    liberarArvore(raiz);
    return 0;
}
