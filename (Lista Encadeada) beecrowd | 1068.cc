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

int Desempilha (Celula *p)
{
	if (p->seg == NULL) {
		return 0; // Retorna 0 se for vazio
	}
	Celula *q;
	q = p->seg;
	p->seg = q->seg;
	delete q;
	return 1;
}

int main()
{
	//variavel que recebe as strings
	string F;
	//criando a cabeca da Pilha
	Celula *Cabeca = new(Celula);
	Cabeca->seg = NULL;

	//repete a analise dos elementos ate acabar todos os elementos da lista
	while (getline(cin, F))
	{
	    bool Correto = 1;
		for(int i = 0 ; i < F.length(); i++) {
			if (F[i]=='(') {
				Insere("(",Cabeca);
			}
			if (F[i]==')') {
				if(Desempilha(Cabeca)==0){
				    Correto = 0;
				    break;
				}
			}
		}
		if(Desempilha(Cabeca)!=0){
		    Correto = 0;
		}
		if(Correto==1){
		    cout << "correct\n";
		} else cout << "incorrect\n";
        
	}

	return 0;
}
