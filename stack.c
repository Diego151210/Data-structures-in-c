#include <stdio.h>
#include <stdlib.h>

#define max 10

struct stack{
	int elemento[max];
	int top;
};

typedef struct stack st;


int pintastack(st *puntero){
	int contador;
	if(puntero->top==-1){
        printf("stack vacio \n");
	}
	else{
        for(contador=0;contador<=puntero->top;contador++){
            printf("Objeto %i: %i \n",contador,puntero->elemento[contador]);
            }
	}
}

int introduce(st *puntero){
	int nelemento;
	if(puntero->top<max-1){
        printf("\n Introduce nuevo elemento: ");
        scanf("%i",&nelemento);
        puntero->top++;
        puntero->elemento[puntero->top]=nelemento;
	}
	else{
        printf("\n Stack lleno \n");
	}
}

int eliminar(st *puntero){
	if(puntero->top==-1){
		printf("Stack vacio \n");
	}
	else{

		printf("\n Eliminando elemento \n");
		puntero->elemento[puntero->top]=0;
		puntero->top--;
		printf("Elemento eliminado \n");
	}
}



int main(){
	int accion;
	st mystack;
	st *puntero=&mystack;
	puntero->top=-1;
	while(accion!=4){
	printf("Lista de opciones: \n");
	printf("Mostrar stack (1) \n");
	printf("Introducir elemento (2) \n");
	printf("Eliminar elemento (3) \n");
	printf("Terminar programa (4) \n");

	printf("Seleccione accion: ");
	scanf("%i",&accion);
	switch(accion){
		case 1:
			pintastack(puntero);
		break;
		case 2:
			introduce(puntero);
		break;
		case 3:
			eliminar(puntero);
		break;
		case 4:
			printf("Terminando programa \n");
		break;
		default:
			("\n Orden no reconocida");
		}
	}

	printf("Programa terminado \n");
}
