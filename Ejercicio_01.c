/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad - Ejercicio 01 
* OBJETIVO : Calculo de factorial
* Fecha creacion : 04 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 04 / 05 / 2017

***************************************************/
#include <stdio.h>
#include <stdlib.h>

int calcularFactorial(int x){
	if (x <= 1){
		return 1;
	}else{
		return (x*calcularFactorial(x-1));
	}
}

int main (){
	int numero;
	printf("\n");
	printf("CALCULAR FACTORIAL \n");
	printf("\nIngrese numero : ");
	scanf("%i",&numero);
	int fact;
	fact = calcularFactorial(numero);
	printf("\n");
	printf("El factorial del numero ingresado es : %i",fact);
	return (0);
}
