/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad - Ejercicio 05 
* OBJETIVO : Imprimir arreglo
* Fecha creacion : 04 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 04 / 05 / 2017

***************************************************/
#include <stdio.h>
#include <stdlib.h>

void imprimirArreglo(int vectorA[],int tamanio){
	if(tamanio == 0){
		printf("\n");
	}else{
		printf("\n");
		printf("Posicion : %i  ->   VALOR : %i",tamanio,vectorA[tamanio-1]);
		printf("\n");
		imprimirArreglo(vectorA, tamanio-1);
	}	
}

int main(){
	int tamanio;
	printf("Ingrese tamanio para el arreglo A : ");
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
	printf("\n");
	printf("Elementos del arreglo A : ");
	printf("\n");
	imprimirArreglo(vector,tamanio);
	return 0;
}


