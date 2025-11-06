// no beecrowd ele da time limite, possivelmente por usar a funcao "new" muitas vezes, e o tempo limite ser 4 segundos
// fazendo o teste manual o codigo funciona perfeitamente

#include <iostream>
#include <cstdlib>

using namespace std;

struct branch {
	int conteudo;
	branch *esq;
	branch *dir;
};

void Erd (branch *r) {
	if (r != NULL) {
		Erd (r->esq);
		cout << r->conteudo << " ";
		Erd (r->dir);
	}
}

void EraseBranch (branch *r) {
	if (r != NULL) {
		EraseBranch (r->esq);
		EraseBranch (r->dir);
	}
	delete r;
}

void PrintBranch (branch *r) {
	Erd (r);
	cout << endl;
}

branch *Insere (branch *r, int h) {
    branch *novo = new(branch);
    novo->esq = NULL; 
    novo->dir = NULL;
    novo->conteudo = h;
	branch *f, *p;
	if (r == NULL) return novo;
	f = r;
	while (f != NULL) {
		p = f;
		if (f->conteudo > novo->conteudo) f = f->esq;
		else f = f->dir;
	}
	if (p->conteudo > novo->conteudo) p->esq = novo;
	else p->dir = novo;
	return r;
}

int main()
{
	int NC, N, h;

	cin >> NC;
	while(NC > 0) {
		cin >> N;
		branch *Arvore = NULL;
		
		while(N > 0) {
			cin >> h;
            Arvore = Insere(Arvore, h);
			N--;
		}
        PrintBranch(Arvore);
        EraseBranch(Arvore);
		NC--;
	}


	return 0;
}




