/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad - Ejercicio 01 
* OBJETIVO : CaminosPosibles
* Fecha creacion : 06 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 07 / 05 / 2017

***************************************************/

#include <stdio.h>
#include <stdlib.h>

//funcion que resuelve la cantidad de caminos posibles
int CaminosPosibles(int n){
	if (n == 1 || n == 0){
		return n;
	}else{
		return CaminosPosibles(n-1) + CaminosPosibles(n-2);
	}

} 

int main(){
	int  n;//variable que almacena el n ingresado
	printf("\n");
	printf("Caminos posibles ingrese 'n' : ");
	scanf("%i",&n);
	while (n < 1){//validacion del numero mayor a 0
		printf("\n");
		printf("ERROR !! Numero menor a cero\n");
		printf("\n");
		printf("Caminos posibles ingrese 'n' :");
		scanf("%i",&n);
		printf("\n");
	}
	//caminos : variable donde se guardara el maximo de caminos posibles
	int caminos,i;
	for (i=0 ; i<n+2; i++){
		caminos = CaminosPosibles(i);
	}
	printf("\n");
	printf("Los caminos posibles son : %i ",caminos);
	printf("\n");
	return 0;
}
