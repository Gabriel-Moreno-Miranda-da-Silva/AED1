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
  //trocar o ponteiro nova->Contudo = F1 para um string.copy
	nova->Conteudo = F1;
	nova->seg = p1->seg;
	p1->seg = nova;
};

void Imprima (Celula *lst)
{
	Celula *p;
	for (p = lst; p != NULL; p = p->seg) {
		cout << p->Conteudo;
	}
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
		for(int i = 0 ; i < F.length(); i++) {
			if (F[i]=='(') {
				Insere("(",Cabeca->seg);
			}
			if (F[i]==')') {
				Insere(")",Cabeca->seg);
			}
		}
        Imprima (Cabeca->seg);
	}

	return 0;
}
