#include <iostream>
using namespace std;

struct Lista {
	int n;
	Lista *seg;
	Lista *ant;
};

void push(Lista *L, int x) {
	Lista *nova = new Lista;
	nova->n = x;
	nova->seg = L;
	nova->ant = L->ant;
	L->ant->seg = nova;
	L->ant = nova;
}

void pop(Lista *L) {
	Lista *primeiro = L->seg;
	L->seg = primeiro->seg;
	primeiro->seg->ant = L;
	delete primeiro;
}

int front(Lista *L) {
	return L->seg->n;
}

int size(Lista *L) {
	int cont = 0;
	Lista *atual = L->seg;
	while (atual != L) {
		cont++;
		atual = atual->seg;
	}
	return cont;
}

int main()
{
	int n;
	while (cin >> n && n != 0) {
		Lista *L = new Lista;
		L->seg = L;
		L->ant = L;

		for (int i = 1; i <= n; i++) {
			push(L, i);
		}

		cout << "Discarded cards:";
		bool primeiro = true;

		while (size(L) >= 2) {
			int discarded = front(L);
			pop(L);

			if (primeiro) {
				cout << " " << discarded;
				primeiro = false;
			} else {
				cout << ", " << discarded;
			}

			if (size(L) > 0) {
				int to_move = front(L);
				pop(L);
				push(L, to_move);
			}
		}
		cout << endl;

		cout << "Remaining card: " << front(L) << endl;

		pop(L);
		delete L;
	}
	return 0;
}
