/*Exercicio de PILHA em C*/

/*Codigo escrito por:
 Vicente Lima
 Bruno Soares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*Preferi trabalhar com String*/

#define MAX 1000

char *pilha;
int topo = -1;

void push(char x) {
    topo++;
    pilha[topo] = x;
}

char pop() {
    if (topo <= -1) {
        printf("Pilha em Underflow\n");
    } else {
        char x = pilha[topo];
        topo--;
        return x;
    }
}

void inverterDado(char dado[]){ 
    int n = strlen(dado);
    pilha = (char *) malloc(n * sizeof(char));
    int i;
    for (i = 0; i < n; i++) {
        push(dado[i]);
    }
    for (i = 0; i < n; i++) {
        dado[i] = pop();
    }
}

int testePalindrome(char dado[]) {
    int n = strlen(dado);
    int i;
    for (i = 0; i < n; i++) {
        push(dado[i]);
    }
    for (i = 0; i < n; i++) {
        if (dado[i] != pop()) {
            return 0;
        }
    }
    return 1;
}

int main() {
  
    char *dado;
    dado = (char *) malloc(MAX * sizeof(char));
    printf("Entre com o dado: ");
    scanf("%s", dado);
    
    inverterDado(dado);
    
    printf("Dado invertido: %s\n", dado);
    
    if (testePalindrome(dado) == 1) {
        printf("%s eh um palindrome\n", dado);
    } else {
        printf("%s nao eh um palindrome\n", dado);
    }
    
    free(pilha);
    free(dado);
}

