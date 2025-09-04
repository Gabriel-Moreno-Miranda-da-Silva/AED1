#include <stdio.h>
 
int main() {
    int N;
    scanf("%d", &N);
    int X[N];
    int M=1000, P=1000;
    for(int i = 0; i<N; i++){
        scanf("%d ",&X[i]);
        if(X[i]<M){
            M = X[i];
            P = i;
        }
    }
    printf("Menor valor: %d\n", M);
    printf("Posicao: %d\n", P);
    return 0;
}
