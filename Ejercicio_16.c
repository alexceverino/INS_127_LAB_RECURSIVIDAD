/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad - Ejercicio 16 
* OBJETIVO : InvertirLista
* Fecha creacion : 04 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 04 / 05 / 2017

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

void eliminarNodo(Lista *L, int valor){
	int eliminado = 0;
	Nodo *aux = L->ini;  
	Nodo *auxE;
	//condicinal que verifica si elvalor es el nodo incial
	if  (valor==aux->dato){
		auxE = aux;
		L->ini = aux->sgte;
		L->tam = L->tam - 1;
		auxE->sgte = NULL ; 
		eliminado = 1 ; 
		free(auxE); 
	}else{
		//condicional que iterna por todos los elementos de Lista
		while (eliminado != 1 && aux->sgte != L->fin){
			if(aux->sgte->dato != valor){
				aux = aux->sgte;
				
			}else{
				auxE = aux->sgte;
				aux->sgte= aux->sgte->sgte;
				auxE->sgte = NULL;
				L->tam = L->tam-1;
				free(auxE);
			}
		}
		//condicional para verificar si el elemento a eliminar 
		//sera el ultimo
		if (valor == aux->sgte->dato){
			auxE = aux->sgte;
			L->fin = aux;
			aux->sgte = aux->sgte;
			aux->sgte = NULL;
			L->tam = L->tam - 1;
			free(auxE);			
		} 
	}
}

void listarLista(Nodo *aux){
	if (aux == NULL){
		printf("\n");
	}else{
		printf("%i , ",aux->dato);
		listarLista(aux->sgte);
	}
}

void insertarFinal(Lista *L, int valor){
	Nodo *nodonuevo; //variable para insertar un nuevo nodo
	//reserva de memoria para el nodo
	nodonuevo = malloc(sizeof(Nodo));
	//reserva de memoria
	
	nodonuevo->dato = valor;
	nodonuevo->sgte = NULL;
	//nodo auxiliar para reservar el nodo final
	Nodo *aux;
	aux = L->fin;
	L->fin = nodonuevo;
	aux->sgte = nodonuevo;
	L->tam = L->tam + 1;

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

//Ejercicio N° 16
void invertirlista(Lista *L){
	int dato;//variable para almacenar dato
	if (L->ini->sgte != NULL){
		dato = L->ini->dato;
		eliminarNodo(L,L->ini->dato);
		invertirlista(L);
		insertarFinal(L,dato);
	}
}


int main(){
	Lista *L;
	L = crearLista();
	int tam,i;
	printf("Ingresar tamanio de lista : ");
	scanf("%i",&tam);
	printf("\n");
	srand(time(NULL));
	for (i = 0;i<tam;i++){
		insertarElemento(L,rand()%10);
	}
	listarLista(L->ini);
	printf("\n");
	printf("------> Inicio de la lista : %i\n",L->ini->dato);
	printf("\n");
	printf("Lista INVERTIDA :\n");
	printf("\n");
	invertirlista(L);
	listarLista(L->ini);
	printf("\n");
	printf("------> Inicio de la lista : %i\n",L->ini->dato);
	return 0;
}

