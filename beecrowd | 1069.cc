#include <iostream>
#include <string>
using namespace std;

struct Celula
{
	string Conteudo;
	struct Celula *seg;
};

void Insere (string F1, Celula *p1)
{
	Celula *nova;
	nova = new (Celula);
	nova->Conteudo = F1;
	nova->seg = p1->seg;
	p1->seg = nova;
}

int DesempilhaEVerifica (Celula *p)
{
	if(p->seg == NULL) {
		return 1;
	}
	int i = 1;
	if (p->seg->Conteudo == "<") {
		Celula *q;
		q = p->seg;
		p->seg = q->seg;
		delete q;
		return 0; //retorna 0 se poder formar um diamante
	}
	return 1;
}

void LimpaPilha(Celula* Cabeca) {
	while(Cabeca->seg != NULL) {
		Celula* temp = Cabeca->seg;
		Cabeca->seg = temp->seg;
		delete temp;
	}
}

int main()
{
	//variavel que recebe as strings
	string F;
	//numero de casos
	string NT;
	int N;
	//criando a cabeca da Pilha
	Celula *Cabeca = new(Celula);
	Cabeca->seg = NULL;

	getline(cin, NT);
	N = stoi(NT);
	//repete a analise dos elementos ate acabar todos os elementos da lista
	while (N>0)
	{
	    LimpaPilha(Cabeca);
		int D = 0; //numero de diamantes
		getline(cin, F);
		for(int i = 0 ; i < F.length(); i++) {
			if (F[i]=='<') {
				Insere("<",Cabeca);
			}
			if (F[i]=='>') {
				if(DesempilhaEVerifica(Cabeca)==0) {
					D++;
				}
			}
		}
		cout << D << "\n";
		N--;
	}

	return 0;
}
