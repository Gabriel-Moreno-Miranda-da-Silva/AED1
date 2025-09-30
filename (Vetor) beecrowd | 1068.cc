#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string F;

    //o loop dura enquanto tiver linhas para ler
	while (getline(cin, F))
	{
	    // n é o contador que verifica se há parenteses abertos ou fechados, "(": +1 , ")": -1
		int n = 0;
		int R = 0;
		for(int i = 0 ; i < F.length(); i++) {
			if (n<0) {
				R = 1;
				break;
			}
			if (F[i]=='(') {
				n++;
			}
			if (F[i]==')') {
				n--;
			}
		}
		if (n != 0 || R == 1) {
			cout << "incorrect" << '\n';
		}
		else {
			cout << "correct" << '\n';
		}
	}

	return 0;
}
