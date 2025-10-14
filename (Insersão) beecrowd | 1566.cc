#include <iostream>
using namespace std;

void Insercao (int n, int v[]) {
	int i, j, x;
	for (j = 1; /*A*/ j < n; j++) {
		x = v[j];
		for (i = j-1; i >= 0 && v[i] > x; i--)
			v[i+1] = v[i];
		v[i+1] = x;
	}
}

int main()
{
	// NC = numero de cidades, h = altura em cm, N = numero de pessoas na cidade
	int NC;
	int N;

	for(cin >> NC; NC > 0; NC--) {
	    cin >> N;
	    int* V = new int[N];
		for(int i = 0; i < N; i++) {
            cin >> V[i];
		}
		
		Insercao(N,V);
		
		for(int i = 0; i < N; i++) {
            cout << V[i] << " ";
		}
		cout << '\n';
		delete[] V;
	}

    return 0;
}
