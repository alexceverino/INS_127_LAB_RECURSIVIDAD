/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad - Ejercicio 04
* OBJETIVO : buscarX
* Fecha creacion : 04 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 04 / 05 / 2017

***************************************************/
#include <stdio.h>
#include <stdlib.h>

int buscarX(int vectorA[] , int x, int tamanio);

int main (){
	int tamanio;
	printf("Ingrese tamanio del vector : ");
	scanf("%i",&tamanio);
	int vector[tamanio];
	int i;
	printf("\n");
	printf("Ingresar numeros para arreglo : ");
	printf("\n");
	for (i=0;i<tamanio;i++){
		printf("%i  : ",i+1);
		scanf("%i",&vector[i]);
		printf("\n");
	}
	
	int posicion,buscar;
	printf("\n");
	printf("Ingrese valor a buscar en arreglo : ");
	scanf("%i",&buscar);
	
	if ((posicion = buscarX(vector,buscar,tamanio)) > 0){
		for (i = 0;i<tamanio;i++){
			if (vector[i] == vector[posicion]){
				printf("\n");		
				printf("\n");
				printf("Encontrado en posicion %i valor : %i",i+1,vector[posicion]);
				printf("\n");
			}
		}
	}else{
		printf("\n");
		printf("ERROR !!! No se encontro !!");
	}
	return 0;
}

int buscarX(int vectorA[] , int x, int tamanio){
	if (vectorA[tamanio-1] == x){		
		return tamanio-1;
	}else{
		return buscarX(vectorA,x,tamanio-1);
	}
}
