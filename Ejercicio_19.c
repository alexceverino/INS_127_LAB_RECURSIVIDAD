/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad - Ejercicio 19 
* OBJETIVO : SumaC
* Fecha creacion : 04 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 07 / 05 / 2017

***************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato;
	struct nodo *sgte;
}Nodo;

typedef struct lista{
	Nodo *ini;
	Nodo *fin;
	int tam;
}Lista;

Lista *crearLista(){
	Lista *L;
	if (L = malloc(sizeof(Lista))){
	
		L->ini = NULL;
		L->fin = NULL;
		L->tam = 0;
		return L;
	}else{
		printf("ERROR !! : Espacio de memoria no asignada ");
	}
}
void insertarElemento(Lista *L,int valor){
	Nodo *nodonuevo; 
	if	(nodonuevo = malloc(sizeof(Nodo))){
		nodonuevo->dato = valor;
		nodonuevo->sgte = NULL;
		if (L->tam == 0){
			L->ini = nodonuevo;
			L->fin = nodonuevo;
		}else{
			nodonuevo->sgte = L->ini;
			L->ini = nodonuevo;
		}
		L->tam = L->tam +1;
	}else{
		printf("ERROR: MEMORIA NO ASIGNADA");
	}
}

void listarLista(Nodo *aux){
	if (aux == NULL){
		printf("\n");
	}else{
		printf(" %i , ",aux->dato);
		listarLista(aux->sgte);
	}
}

void eliminarNodo(Lista *L){
	Nodo *aux = L->ini;  
	Nodo *auxE;
	//condicinal que verifica si elvalor es el nodo incial
	L->ini = aux->sgte;
	L->tam = L->tam - 1;
	aux->sgte = NULL ; 
	free(aux); 	
}

//funcion ejercicio n° 19
int sumaC(Lista *L,int c){
	if(sumaNodos(L)<c){
		return L->tam+1;
	}else{
		//eliminamos el nodo del inicio
		eliminarNodo(L);
		//se llama a la funcion
		return sumaC(L,c);
	}
}		

int sumaNodos(Lista *L){
	int i,suma = 0;
	//nodo aux se posiciona en el inicio de la lista
	Nodo *aux;
	aux = L->ini;
	//con este ciclo se suman los elementos restantes de la lista
	for (i=0;i<L->tam;i++){
		suma=suma+aux->dato;
		aux=aux->sgte;
	}
	//se retorna un numero entero para ser evaluado en la funcion SumaC
	return suma;
}

int main(){
	Lista *L;//lista con enlaces dobles
	L = crearLista();
	int i,tam;
	printf("INGRESAR TAMANIO DE LA LISTA 1 : ");scanf("%i",&tam);
	printf("\n");
	srand(time(NULL));
	for (i = 0;i<tam;i++){
		insertarElemento(L,rand()%10);
	}
	printf("\n");
	printf("Lista ingresada : \n");
	printf("\n");
	Nodo *aux;//puntero que aputa al inicio de a lista
	aux = L->ini;
	listarLista(aux);//funcion recursiva para mostrar la lista
	int c;//variable para cantidad 
	printf("\n");
	printf("--------> Ingrese el valor de C : ");
	scanf("%i",&c);	
	printf("\n");
	int cant;
	cant = sumaC(L,c);
	if(cant == tam +1){
		printf("--------> Con C: %i = %i ",c,cant-1);
	}else{
		printf("--------> Con C: %i = %i ",c,cant);
	}
	
	return 0;
}
