#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct queue{
    int position[MAX];
    int first, last;

}; typedef struct queue qu;

void drawqueue(qu *pointer){
        int i;
        if(pointer->first==-1){
            printf("Empty queue \n");
        }
        else{
                //mirar que pinte el ultimo elemento y el caso en el que last sea uno menos que first
            printf("First %i last %i \n",pointer->first,pointer->last);
            for(i=pointer->first;;i++){

                printf("Position %i Element %i \n",i,pointer->position[i]);
                if(i==MAX-1 && pointer->first!=0 && pointer->last!=MAX-1){
                    i=-1;
                }
                if(i==pointer->last){
                    break;
                }

            }
        }
}

void addqueue (qu *pointer){
        int element;
        if((pointer->last==MAX-1 && pointer->first==0) || (pointer->first==pointer->last+1)){
            printf("Impossible, queue is full \n");
        }
        else{
        printf("Insert new element: \n");
        scanf("%i",&element);
        if(pointer->first==-1){
                pointer->first++;
        }
        if(pointer->last==MAX-1 && pointer->first!=0){
            //printf("Last %i \n",pointer->last);
            pointer->last=-1;
            //printf("Last %i \n",pointer->last);
        }
        pointer->last++;
        //printf("Last %i \n",pointer->last);
        pointer->position[pointer->last]=element;
        }

}

void freequeue(qu *pointer){
        if(pointer->first==-1){
            printf("Impossible, queue empty \n");
        }
        else if(pointer->first==pointer->last){
                //empty queue
            pointer->first=-1;
            pointer->last=-1;
            printf("Queue is empty \n");

        }
        else if(pointer->first==MAX-1){
            pointer->first=0;
        }
        else{
        pointer->first++;
        }

}

int main()
{
    int action;

   qu *pointer=(int*)malloc(sizeof(int));
   pointer->first=-1;
   pointer->last=-1;

   while(action!=4){
    printf("Option list: \n");
	printf("Show queue (1) \n");
	printf("Add element (2) \n");
	printf("Delete element (3) \n");
	printf("Terminate program (4) \n");

	printf("Select action: ");
	scanf("%i",&action);
   switch(action){
        case 1:
            drawqueue(pointer);
        break;

        case 2:
            addqueue(pointer);
        break;

        case 3:
            freequeue(pointer);
        break;

        case 4:
            printf("Finishing program");
        break;

        default:
            printf("No valid action \n");
        }
   }
}
