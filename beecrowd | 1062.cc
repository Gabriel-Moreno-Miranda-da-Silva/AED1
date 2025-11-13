#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        int ordem_saida[1000];
        int primeiro_vagao;
        
        while (cin >> primeiro_vagao && primeiro_vagao != 0) {
            ordem_saida[0] = primeiro_vagao;
            for (int i = 1; i < N; i++) {
                cin >> ordem_saida[i];
            }

            int pilha_estacao[1000];
            int topo_pilha = -1;
            int vagao_A = 1;
            bool possivel = true;

            for (int i = 0; i < N; i++) {
                int vagao_necessario = ordem_saida[i];

                if (vagao_necessario >= vagao_A) {
                    while (vagao_A < vagao_necessario) {
                        pilha_estacao[++topo_pilha] = vagao_A;
                        vagao_A++;
                    }
                    vagao_A++;
                } else {
                    if (topo_pilha == -1 || pilha_estacao[topo_pilha] != vagao_necessario) {
                        possivel = false;
                        break;
                    } else {
                        topo_pilha--;
                    }
                }
            }

            if (possivel) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
