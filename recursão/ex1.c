/*
Faça um programa iterativo e recursivo de uma lista que retorna o tamanho da lista
*/

#include <stdio.h>
#include <stdlib.h>


typedef struct Node List;

struct Node {
    int data;
    List* next; 
};

List* create(){
    return NULL;
}

List* insert(List *l, int elem){
    List *node = (List*)malloc(sizeof(List));
    node->data = elem;
    node->next = l;
    return node;
}

void print(List *l){
    List *t;
    for(t=l; t!=NULL; t=t->next){
        printf("%d",t->data);
        printf("\n");
    }
    printf("\n");
}

int size (List *l){
    /*versão iterativa:
    int i=0;
    List *t;
    for(t=l;t!=NULL;t=t->next){
        i++;
    }
    return i;
    */

    //versão recursiva:
    //caso base:
    if(l==NULL){
        return 0;
    }

    return 1 + size(l->next);
}


int main(){
    List *l = create();

    l=insert(l,1);
    l=insert(l,2);
    l=insert(l,3);

    print(l);

    printf("Tamanho: %d",size(l));

    return 0;
}