
/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad - Ejercicio 02
* OBJETIVO : Multiplicacion con suma
* Fecha creacion : 04 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 04 / 05 / 2017

***************************************************/
#include <stdio.h>
#include <stdlib.h>

int multiplicarConSuma(int x, int y){

	if (y <= 1){
		return x;
	}else{
		printf("\n%i",x);
		return (x+multiplicarConSuma(x,y-1));
	}
}

int main(){
	int x,y;
	int mult;
	printf("\n");
	printf("MULTIPLICACION DE DOS NUMEROS ");
	printf("\n");
	printf("\nIngresar primer numero ");
	scanf("%i",&x);
	printf("\nIngresar segundo numero ");
	scanf("%i",&y);
	mult = multiplicarConSuma(x,y);
	printf("RESULTADO : %i",mult);
	return (0);
}
