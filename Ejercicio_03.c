/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad - Ejercicio 03
* OBJETIVO : Suma de arreglo
* Fecha creacion : 04 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 04 / 05 / 2017

***************************************************/
#include <stdio.h>
#include <stdlib.h>

int sumarArreglo(int vector[],int tamanio){
	
	if (tamanio<=1){
		return vector[tamanio-1];
	}else{
		return (vector[tamanio-1]+sumarArreglo(vector,tamanio-1));
	}
}


int main(){
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
	
	int suma;
	suma = sumarArreglo(vector,tamanio);
	printf("La suma es : %i",suma);
	return (0);
}
