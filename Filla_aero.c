//exercicio fila aeroporto
/*
Elaborado por Vicente de Souza Lima Neto e Bruno Soares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 10

struct Fila {
    int capacidade;
    
	char nome[10];
	int *id_voo;
	int num_model;
	
	int primeiro;
	int ultimo;
	int nItens;
};

typedef struct Fila fila;

void criarFila(fila *f) { 

	f->capacidade = CAP;
	f->id_voo = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 

}

void inserir(fila *f, int id, char name[10], int num) {

	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;

	f->ultimo++;
	f->id_voo[f->ultimo] = id; // incrementa ultimo e insere
	strcpy(f->nome, name);
	f->num_model = num;
	f->nItens++; // mais um item inserido

}

int remover( fila *f ) { // pega o item do comeÃ§o da fila

	int temp = f->id_voo[f->primeiro++]; // pega o valor e incrementa o primeiro

	if(f->primeiro == f->capacidade)
		f->primeiro = 0;

	f->nItens--;  // um item retirado
	return temp;

}

int estaVazia( fila *f ) { // retorna verdadeiro se a fila estÃ¡ vazia

	return (f->nItens==0);

}

int estaCheia( fila *f ) { // retorna verdadeiro se a fila estÃ¡ cheia

	return (f->nItens == f->capacidade);
}

void mostrarFila(fila *f){

	int cont, i;

	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

		printf("%d - ",f->id_voo[i++]);
		printf("%s", f->nome);
		printf("%d", f->num_model);
		printf("\t=>\t");

		if (i == f->capacidade)
			i=0;

	}
	printf("\n\n");

}

void carac_prim_aviao(fila *f){
  
  printf("%d - ",f->id_voo[0]);
	printf("%s", f->nome);
	printf("%d", f->num_model);
	printf("\t=>\t");
  printf("\n\n");
}

int main () {

	int opcao;
	int id;
	int num;
	char name[10];
	struct Fila umaFila;

	// cria a fila
	/*printf("\nCapacidade da fila? ");
	scanf("%d",&capa);*/
	criarFila(&umaFila);

	// apresenta menu
	while( 1 ){

		printf("\n1 - Inserir aviao na fila de espera\n2 - Autorizar a decolagem do aviao na fila\n3 - Listar os avioes na Fila\n4 - Caracteristicas do primeiro aviao\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);

		switch(opcao){

			case 0: exit(0);

			case 1: // insere elemento
				if (estaCheia(&umaFila)){

					printf("\nFila Cheia!!!\n\n");

				}
				else {

					printf("\nNumero do voo: ");
					scanf("%d", &id);
					printf("\nNome do modelo do aviao: ");
					scanf("%s", name);
					printf("\nNumero do modelo: ");
					scanf("%d", &num);
					inserir(&umaFila, id, name, num);

				}

				break;

			case 2: // remove elemento
				if (estaVazia(&umaFila)){

					printf("\nFila vazia!!!\n\n");

				}
				else {

					id = remover(&umaFila);
					printf("\n%d Autorizado a decolagem com sucesso\n\n", id); 

				}
				break;

				case 3: // mostrar fila
					if (estaVazia(&umaFila)){

						printf("\nFila vazia!!!\n\n");

					}
					else {

						printf("\nConteudo da fila \n=> ");
						mostrarFila(&umaFila);

					}
					break;
					
				case 4: //mostrar caracteristicas do primeiro aviao
				  printf("Caracteristicas do primeiro avi�o da fila \n=>");
				  carac_prim_aviao(&umaFila);
				  break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}
	return 0;
}



