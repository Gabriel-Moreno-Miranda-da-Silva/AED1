#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    while (n--) {
        string linha;
        getline(cin, linha);

        string palavras[55];
        int qtd = 0;
        string temp = "";

        for (int i = 0; i < linha.length(); i++) {
            if (linha[i] == ' ') {
                if (temp.length() > 0) {
                    palavras[qtd++] = temp;
                    temp = "";
                }
            } else {
                temp += linha[i];
            }
        }
        if (temp.length() > 0) {
            palavras[qtd++] = temp;
        }

        for (int i = 0; i < qtd - 1; i++) {
            for (int j = 0; j < qtd - 1 - i; j++) {
                if (palavras[j].length() < palavras[j+1].length()) {
                    string aux = palavras[j];
                    palavras[j] = palavras[j+1];
                    palavras[j+1] = aux;
                }
            }
        }

        for (int i = 0; i < qtd; i++) {
            cout << palavras[i];
            if (i < qtd - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
