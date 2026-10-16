#include <stdio.h>
#include <stdlib.h>

//estrutura da fila
typedef struct{
    int front;
    int back;
    int size;
    int *array;
}Queue;

//cria a fila, front e back inicializam na posição 0, size recebe o tamanho da fila inserida
//array e q alocam memória
Queue* create(int size){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->back = 0;
    q->size = size;
    q->array = (int*)malloc(size*sizeof(int));

    return q;
}

//vai estar vazia quando o front estiver na mesma posição do back, ou seja, tá na posição de quando inicializou a fila
int empty(Queue *q){
    return(q->front==q->back);
}

/*
COMO DEIXAR A FILA CIRCULAR:
Deixa a fila circular usando: i=(i+1)%size
o que faz: sempre que chegar no final reseta pra primeira posição
*/

//Vai estar cheia quando a próxima posição do back for a do front
int full(Queue *q){
    return (q->front == ((q->back + 1) % q->size));	
}


void enqueue(Queue *q, int elem){
    //verifica se está cheia, se estiver não permite inserir mais elementos
    if(full(q)){
        printf("Queue overflow");
        exit(1);
    }

    //array na posição back vai receber o elemento, e após isso back vai ir pra proxima posição em formato circular
    q->array[q->back]=elem;
    q->back=(q->back+1)%q->size;
}

int dequeue(Queue *q){
    //verifica se estiver vazia, e não permite caso esteja
    if(empty(q)){
        printf("Queue underflow");
        exit(1);
    }

    int elem = q->array[q->front];
    q->front=(q->front+1)%q->size;

    return elem;
}

void print(Queue *q){
    int i;
    for(i=q->front;i!=q->back;i=(i+1)%q->size){
        printf("%d",q->array[i]);
        printf("\n");
    }
    printf("\n");

}

void destroy(Queue *q){
    free(q->array);
    free(q);
}

int getsize(Queue *q){
    return(q->size);
}

int search(Queue *q, int elem){
    int i;
    for(i=q->front;i!=q->back;i=(i+1)%q->size){
        if(q->array[i]==elem){
            return 1;
        }
    }
    return 0;
}

int main(){

    //teste
    int size = 5;
    Queue *q = create(size);

    enqueue(q,1);
    enqueue(q,1);
    enqueue(q,1);
    enqueue(q,1);
    enqueue(q,1);


    print(q);

    return 0;
}