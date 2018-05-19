/**
---- hola.c ----
Programa que crea n hilos y muestra en pantalla el texto hola m donde m es el ID del hilo, esto para los n hilos creados.

Autor: Herney Quintero
*      Camilo Sanchez
* 	   Carlos Murillo
Fecha: Mayo 3, 2017

**/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define MAXHILOS 50


void* imprime(void* arg){
	 printf("hola: %ld\n",pthread_self());
	 pthread_exit(NULL);
}
int main(int argc, char** argv){
	int numeroHilos,j;
	pthread_t arrayHilos[MAXHILOS];
	if(argc != 2){
		printf("Por favor digite el numero de hilos a usar\n");
		printf("\t%s <numhilos>\n",argv[0]);
		exit(-1);
	}
	
	numeroHilos = atoi(argv[1]); //la funcion atoi convierte un string a un entero
	if (numeroHilos > MAXHILOS || numeroHilos == 0) {
		printf("Maximo numero de hilos es %d, usted solicito %d\n",MAXHILOS, numeroHilos);
		exit(-1);
	}
	//crea los hilos
	for(j=0; j < numeroHilos;j++){
		pthread_create(&arrayHilos[j],NULL,imprime,NULL);
	}
	
	for(j=0; j < numeroHilos; j++){
		pthread_join(arrayHilos[j],NULL);
	}

}

