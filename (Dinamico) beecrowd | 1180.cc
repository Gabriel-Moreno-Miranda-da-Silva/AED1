
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct {
    int N;
    int M;
    int P;
} Valores;

int main() {
    Valores *p;
    int *X;
    p = (Valores *) malloc(sizeof(Valores));
    X = (int *) malloc(sizeof(X));
    cin >> p->N;
    p->M=1000; 
    p->P=1000;
    for(int i = 0; i<p->N; i++){
        cin >> X[i];
        if(X[i]<p->M){
            p->M = X[i];
            p->P = i;
        }
    }
    cout << "Menor valor: "<< p->M << '\n';
    cout << "Posicao: "<< p->P << '\n';
    free(p);
    return 0;
}
