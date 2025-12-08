#include <iostream>

using namespace std;

char prefixa[60];
char infixa[60];
int indicePre; 

int buscar(int inicio, int fim, char valor) {
    for (int i = inicio; i <= fim; i++) {
        if (infixa[i] == valor) {
            return i;
        }
    }
    return -1;
}

void posfixa(int inicioIn, int fimIn) {
    if (inicioIn > fimIn) {
        return;
    }

    char raiz = prefixa[indicePre];
    indicePre++;

    int indiceRaiz = buscar(inicioIn, fimIn, raiz);

    posfixa(inicioIn, indiceRaiz - 1);

    posfixa(indiceRaiz + 1, fimIn);

    cout << raiz;
}

int main() {
    int C;
    cin >> C;

    while (C--) {
        int N;
        cin >> N >> prefixa >> infixa;

        indicePre = 0;

        posfixa(0, N - 1);
        
        cout << endl;
    }

    return 0;
}
