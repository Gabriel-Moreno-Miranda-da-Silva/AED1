#include <iostream>

using namespace std;

int dist[8][8];

int dr[] = {-2, -2, -1, -1,  1,  1,  2,  2};
int dc[] = {-1,  1, -2,  2, -2,  2, -1,  1};

struct Ponto {
    int r, c;
};

Ponto fila[1000]; 
int inicio_fila = 0;
int fim_fila = 0;

void zerar_fila() {
    inicio_fila = 0;
    fim_fila = 0;
}

void push(int r, int c) {
    fila[fim_fila].r = r;
    fila[fim_fila].c = c;
    fim_fila++;
}

Ponto pop() {
    Ponto p = fila[inicio_fila];
    inicio_fila++;
    return p;
}

bool fila_vazia() {
    return inicio_fila == fim_fila;
}

int bfs(int r_origem, int c_origem, int r_destino, int c_destino) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            dist[i][j] = -1;
        }
    }
    zerar_fila();

    dist[r_origem][c_origem] = 0;
    push(r_origem, c_origem);

    while (!fila_vazia()) {
        Ponto atual = pop();
        int r = atual.r;
        int c = atual.c;

        if (r == r_destino && c == c_destino) {
            return dist[r][c];
        }

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8) {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    push(nr, nc);
                }
            }
        }
    }
    return -1;
}

int main() {
    char col1_char, col2_char;
    int row1_in, row2_in;

    while (cin >> col1_char >> row1_in >> col2_char >> row2_in) {
        
        int c1 = col1_char - 'a';
        int c2 = col2_char - 'a';
        
        int r1 = row1_in - 1;
        int r2 = row2_in - 1;

        int movimentos = bfs(r1, c1, r2, c2);

        cout << "To get from " << col1_char << row1_in << " to " << col2_char << row2_in << " takes " << movimentos << " knight moves." << endl;
    }

    return 0;
}
