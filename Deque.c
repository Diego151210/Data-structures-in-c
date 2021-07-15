#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct deque{

    int queue[MAX];
    int front,rear;

}; typedef struct deque dq;


void drawqueue(dq *p){
    int i;

    if(p->front==-1){
        printf("Queue is empty. \n");
        return;
    }

    for(i=p->front;;i++){

        printf("Element %i: %i \n",i,p->queue[i]);

        if(i==p->rear){
            break;
        }

        if(i==MAX-1 && i!=p->rear){
            i=-1;
        }


    }

}

void addfront(dq *p){

    //printf("front %i \n",p->front);

    int element;

    //printf("front %i \n",p->front);

    if((p->front==0 && p->rear==MAX-1) || (p->front==p->rear+1)){
        printf("Impossible, queue is full \n");
        return;
    }

    printf("Insert new element: ");
    scanf("%i",&element);

    //printf("front %i \n",p->front);

    if(p->front==-1){
        p->front=p->rear=0;
        p->queue[p->front]=element;
        return;
    }

    if(p->front==0){
        p->front=MAX-1;
        p->queue[p->front]=element;
        return;
    }

    printf("echo \n");
    p->front--;
    p->queue[p->front]=element;

}

void removefront(dq *p){

    if(p->front==-1){
        printf("Impossible, queue is empty \n");
        return;
    }

    if(p->front==p->rear){

        p->front=p->rear=-1;
        printf("Queue is now empty \n");
        return;
    }

    if(p->front==MAX-1){
        p->front=0;
        return;
    }

    p->front++;

}

void addrear(dq *p){

    int element;

    if((p->front==0 && p->rear==MAX-1) || (p->front==p->rear+1)){
        printf("Impossible, queue is full \n");
        return;
    }

    printf("Insert new element: ");
    scanf("%i",&element);

    if(p->front==-1){
        p->front=p->rear=0;
        p->queue[p->rear]=element;
        return;
    }

    if(p->rear==MAX-1){
        p->rear=0;
        p->queue[p->rear]=element;
        return;
    }

    p->rear++;
    p->queue[p->rear]=element;

}

void removerear(dq *p){

    if(p->front==-1){
        printf("Impossible, queue is empty \n");
        return;
    }

    if(p->front==p->rear){

        p->front=p->rear=-1;
        printf("Queue is now empty \n");
        return;
    }

    if(p->rear==0){
        p->rear=MAX-1;
        return;
    }

    p->rear--;

}

int main()
{
    int action=0;
    dq *p=(int*)malloc(sizeof(int));
    p->front=-1;
    p->rear=-1;

    while(action!=6){

        printf("Option list: \n");
        printf("Show queue (1) \n");
        printf("Add element at front (2) \n");
        printf("Delete element from front (3) \n");
        printf("Add element at rear (4) \n");
        printf("Delete element from rear (5) \n");
        printf("Terminate program (6) \n");

        printf("Choose an option: ");
        scanf("%i",&action);

        switch(action){

            case 1:
                drawqueue(p);
            break;

            case 2:
                addfront(p);
            break;

            case 3:
                removefront(p);
            break;

            case 4:
                addrear(p);
            break;

            case 5:
                removerear(p);
            break;

            case 6:
                printf("Terminating program \n");
            break;

            default:
                printf("No valid action \n");
        }
    }

    printf("Program terminated \n");

    return 0;
}


//casos de vaciar el queue y poner front and rear a 0 al emepzar el queue
