#include <stdio.h>
#include <stdlib.h>


typedef struct Node List;

struct Node {
    int data;
    List* next; 
};

//Uma lista vazia é um ponteiro para NULL
List* create(){
    return NULL;
}

List* insert(List *l, int elem){
    //cria um novo nó
    List *node = (List*)malloc(sizeof(List));
    //insere o elemento no novo nó
    node->data = elem;
    //aponta pro ultimo nó
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


int main(){
    List *l = create();

    l=insert(l,1);
    l=insert(l,2);
    l=insert(l,3);

    print(l);

    return 0;
}