
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct {
    int N;
    int X[1000];
    int M;
    int P;
} Valores;

int main() {
    Valores *p;
    p = (Valores *) malloc(sizeof(Valores));
    cin >> p->N;
    p->M=1000; 
    p->P=1000;
    for(int i = 0; i<p->N; i++){
        cin >> p->X[i];
        if(p->X[i]<p->M){
            p->M = p->X[i];
            p->P = i;
        }
    }
    cout << "Menor valor: "<< p->M << '\n';
    cout << "Posicao: "<< p->P << '\n';
    free(p);
    return 0;
}
