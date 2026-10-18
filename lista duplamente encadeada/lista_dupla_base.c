#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct node *next;
    struct node *prev;
}List;

List* create(){
    return NULL;
}

List* insert_front(List* l, int elem){
    List* node = malloc(sizeof(List));
    node->data = elem;
    node->next = l;
    node->prev = NULL;

    if(l!=NULL){
        l->prev = node;
    }
    return node;
}


List* search (List *l, int elem) {
  if (l != NULL) {
    List *t = l;	   
    while (t != NULL) {
      if (t->data == elem) 
        return t;
      t = t->next;
    }  
  }
  return NULL;  
}

void print (List *l) {
  List *t, *last;
  printf ("List (front-to-back): {");
  for (t = l; t != NULL; t = t->next) {
    if (t->next != NULL)	  
       printf ("%d, ", t->data);
    else
       printf ("%d", t->data);
    last = t;
  }  
  printf("}\n");
  printf ("List (back-to-front): {");
  for (t = last; t != NULL; t = t->prev) {
    if (t->prev != NULL)	  
       printf ("%d, ", t->data);
    else
       printf ("%d", t->data);
  }  
  printf("}\n");
}


int main(){
    List* l = create();

    l=insert_front(l,2);
    l=insert_front(l,3);
    l=insert_front(l,4);
    l=insert_front(l,5);

    print(l);


    return 0;
}