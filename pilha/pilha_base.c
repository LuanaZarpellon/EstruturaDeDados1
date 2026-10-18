#include <stdio.h>
#include <stdlib.h>

//estrutura da pilha
typedef struct{
    int peek;
    int size;
    int *array;
}Stack;

//função que cria a pilha
Stack* create(int size){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->peek=0;
    s->size=size;
    s->array=(int *)malloc(size * sizeof(int));

    return s;
}

//função que verifica se a pilha está vazia
int empty(Stack *s){
    return(s->peek==0);
}

//função que verifica se a pilha está cheia
int full(Stack *s){
    return(s->peek==s->size);
}

//vai remover o elemento que tá no topo da pilha
int pop(Stack *s){
    //se já está vazia, encerra a função
    if(empty(s)){
        printf("Stack underflow");
        exit(1);
    }

    s->peek--;
    return(s->array[s->peek]);
}

//insere um elemento no topo da pilha
void push(Stack *s,int elem){
    if(full(s)){
        printf("Stack overflow");
        exit(1);
    }

    s->array[s->peek]=elem;
    s->peek++;

}

//imprime a pilha
void print(Stack *s){
    int i;
    for(i = s->peek-1; i>=0; i--){
        printf("%d",s->array[i]);
        printf("\n");
    }
    printf("\n");
}

//retorna o valor que tá no topo da pilha
int get_peek(Stack *s){
    if(empty(s)){
        printf("Empty stack");
        exit(1);
    }
    return(s->array[(s->peek)-1]);
}

//retorna o tamanho da pilha
int get_size(Stack *s){
    return (s->size);
}

void destroy(Stack *s){
    free(s->array);
    free(s);
}


int main(){
    //teste
    int size=5;
    Stack *s = create(size);

    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);

    print(s);

    return 0;
}