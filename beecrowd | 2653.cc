#include <iostream>

using namespace std;

const int MAX_NOS = 1000000;

// trie[no][0] -> caminho para '('
// trie[no][1] -> caminho para ')'
int trie[MAX_NOS][2];

bool fim_da_joia[MAX_NOS];

int contador_nos = 1; 

int main() {
    char buffer[100000];
    
    int joias_distintas = 0;

    while (cin >> buffer) {
        int atual = 0;
        
        for (int i = 0; buffer[i] != '\0'; i++) {
            
            int direcao = (buffer[i] == ')'); 

            if (trie[atual][direcao] == 0) {
                trie[atual][direcao] = contador_nos;
                contador_nos++;
            }
            
            atual = trie[atual][direcao];
        }

        if (fim_da_joia[atual] == false) {
            joias_distintas++;
            fim_da_joia[atual] = true;
        }
    }

    cout << joias_distintas << endl;

    return 0;
}
