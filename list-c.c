/*Exercicio de lista estrutura de dados*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct Node{
    
    char nome[40];
    int tel;
    int cel;
    char email[40];
    int dia_niver;
    int mes_niver;
    
    struct Node *prox;
};typedef struct Node node;

//declarando as funcoes
void menu();
void opcao(node *le, int choice);
void remover(node *le, char nome[40]);

node* criar_lista(){
    node *le = malloc(sizeof(node));
    le->prox = NULL;
    return le;
}

void insere(node *le,char nome[40], int tel, int cel, char email[40], int dia_niver, int mes_niver){
    
    node *novo_node;
    novo_node = malloc(sizeof(node));
    printf("Digite o nome do contato: \n");
    scanf("%s", nome);
    printf("Digite o telefone: \n");
    scanf("%d", &tel);
    printf("Digite o celular: \n");
    scanf("%d", &cel);
    printf("Digite email: \n");
    scanf("%s", email);
    printf("Digite dia e mês do aniversaio (01/01): \n");
    scanf("%d / %d", &dia_niver, &mes_niver);
    
    strcpy(novo_node->nome, nome);
    novo_node->tel = tel;
    novo_node->cel = cel;
    strcpy(novo_node->email, email);
    novo_node->dia_niver = dia_niver;
    novo_node->mes_niver = mes_niver;
    
    novo_node->prox = le->prox;
    le->prox = novo_node;
}

void imprime(node *le){
    node *p = le->prox;
    
    while (p != NULL){
        printf("\n--%s--\n", p->nome);
        printf("Telefone: %d\n", p->tel);
        printf("Celular: %d\n", p->cel);
        printf("Email: %s\n", p->email);
        printf("Dia/Mês de aniversario: %d / %d\n", p->dia_niver, p->mes_niver);
        p = p->prox;
    }
}

void menu(){
    
    printf("\n0 - para sair\n");
    printf("1 - Inserir novo contato\n");
    printf("2 - Para exibir todos os contatos\n");
    printf("3 - Para remover um contato\n");
    
}

void opcao(node *n, int choice){

    char nome[40]; int tel; int cel; char email[40]; int dia_niver; int mes_niver;
    
    switch(choice){
            case 0: 
                exit(0);
            
            case 1:
                insere(n, nome, tel, cel, email, dia_niver, mes_niver);
                printf("Inserido!\n");
                break;
            
            case 2:
                imprime(n);
                break;
                
            case 3:
                remover(n, nome);
                break;
                
            default:
                printf("Opcao invalida!");
        }
}
void remover(node *le, char nome[40]){
    node *p = le;
    while(p->prox != NULL && strcmp(p->prox->nome, nome) != 0){
        p = p->prox;
    }
    if (p->prox != NULL){
        node *le = p->prox;
        p->prox = le->prox;
        free(le);
    }
}

int main(){
    
    node *le = criar_lista();
    int choice;
    
    do{
        menu();
        printf("\nEscolha uma opção: ");
        scanf("%d", &choice);
        opcao(le, choice);

    }while(choice);
    
    
    return 0;
    
}
