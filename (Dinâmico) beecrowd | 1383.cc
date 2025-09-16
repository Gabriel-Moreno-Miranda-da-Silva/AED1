#include <iostream>
using namespace std;

// Função para verificar numeros duplicados
int Verificar(int vet[]) {
    for (int i1 = 0; i1 < 9; i1++) {
        for (int i2 = i1 + 1; i2 < 9; i2++) {
            if (vet[i1] == vet[i2]) {
                return 1; 
            }
        }
    }
    return 0;
}

// Função principal de verificação do Sudoku
// Retorna R, sendo 1 um sudoku correto e 0 um sudoku incorreto
int VerificarMatrix(int* vet1, int** vet2, int* R) {
    int i, j;

    // Verificar Todas as linhas
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            vet1[j] = vet2[i][j];
        }
        if (Verificar(vet1)) {
            *R = 0; 
        }
    }

    // Verificar Todas as Colunas
    for (j = 0; j < 9; j++) {
        for (i = 0; i < 9; i++) {
            vet1[i] = vet2[i][j];
        }
        if (Verificar(vet1)) {
            *R = 0; 
        }
    }

    // Verificar Todas as Matrizes 3x3
    for (int lin = 0; lin < 9; lin += 3) {
        for (int col = 0; col < 9; col += 3) {
            int k = 0;
            for (i = lin; i < lin + 3; i++) {
                for (j = col; j < col + 3; j++) {
                    vet1[k++] = vet2[i][j];
                }
            }
            if (Verificar(vet1)) {
                *R = 0; 
            }
        }
    }
    return 0; 
}

int main() {
    int n;
    cin >> n;
    int* m = new int[9];
    int** M = new int*[9];
    for (int i = 0; i < 9; ++i) {
        M[i] = new int[9];
    }

    for (int N = 0; N < n; N++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> M[i][j];
            }
        }

        int valido = 1; 
        VerificarMatrix(m, M, &valido);

        cout << "Instancia " << N + 1 << "\n";
        if (valido == 0) {
            cout << "NAO\n\n";
        } else {
            cout << "SIM\n\n";
        }
    }

    delete[] m;
    for (int i = 0; i < 9; ++i) {
        delete[] M[i];
    }
    delete[] M; 

    return 0;
}
