/**************************************************
* PROGRAMA : Listado Ejercicios de recursividad  
* OBJETIVO : Ejercicios Varios
* Fecha creacion : 04 / 05 / 2017
* ALUMNO: 
			Alex Ceverino Chuquiano
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 04 / 05 / 2017

***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

//ejercicio 07: funcion recursiva
int sumaLista(Nodo *aux, int tam){
	if (tam <= 1){
		return aux->dato;
	}else{
		return (aux->dato + sumaLista(aux->sgte,tam-1));
	}
}
//ejercicio 08 : mostrar elementos de la lista
void listarLista(Nodo *aux){
	if (aux == NULL){
		printf("\n");
	}else{
		printf("%i , ",aux->dato);
		listarLista(aux->sgte);
	}
}

int opc(){
	int opcion = 0;
	printf("\n");
	printf("[ 1 ] Ejercicio 6 : calcularOcurrencia\n");
	printf("\n");
	printf("[ 2 ] Ejercicio 7 : SumaLista\n");
	printf("\n");
	printf("[ 3 ] Ejercicio 8 : listarLista\n");
	printf("\n");
	printf("[ 4 ] Ejercicio 9 : sonIguales\n");
	printf("\n");
	printf("[ 5 ] Ejercicio 10 : existeElemento\n");
	printf("\n");
	printf("[ 6 ] Ejercicio 11 : eliminarX\n");
	printf("\n");
	printf("[ 7 ] Ejercicio 12 : calcularMaximo\n");
	printf("\n");
	printf("[ 8 ] Ejercicio 13 : insertarOrdenado\n");
	printf("\n");
	printf("[ 9 ] Ejercicio 14 : ordenarLista \n");
	printf("\n");
	printf("[ 10 ] Ejercicio 15 : Merge(incompleto)\n");
	printf("\n");
	printf(" Elegir  : ");
	scanf("%i",&opcion);
	if(opcion == 1){
		return opcion;
	}else if(opcion == 2){
		return opcion;
	}else if(opcion == 3){
		return opcion;
	}else if(opcion == 4){
		return opcion;
	}else if(opcion == 5){
		return opcion;
	}else if(opcion == 6){
		return opcion;
	}else if(opcion == 7){
		return opcion;
	}else if(opcion == 8){
		return opcion;
	}else if(opcion == 9){
		return opcion;
	}else if(opcion == 10){
		return opcion;
	}else{
		printf("\n");
		printf("ERROR : Elegir una opcion Valida !!! ");
		printf("\n");
		return opc();
	}		
}

//funcion para pedir al usuario elementos para la lista
void llenarLista(Lista *L){
	int numero;
	printf("\n");
	printf("Ingresar numero : ");
	scanf("%i",&numero);
	printf("\n");
	insertarElemento(L,numero);
}
//funcion que verifica si lista esta vacia
bool esVacia(Lista *L){
	if(L->fin == NULL)return true;
	else return false;
}

//ejercicio 06
int calcularOcurrencia(Nodo *aux, int x){
	if(aux != NULL){
		if(aux->dato == x){
			return ( 1 + calcularOcurrencia(aux->sgte,x));
		}
		return calcularOcurrencia(aux->sgte,x);
	}else{
		return 0; 
	}
	
}
//Ejercicio 10 
bool existeElemento(Nodo *aux,int buscar){
	if (aux->dato == buscar){
		return true;
	}else if(aux->sgte == NULL){
		return false;
	}else{
		return existeElemento(aux->sgte,buscar);
		return false;
	}
}
//ejercicio 11
void eliminarX(Lista *L,Nodo *aux,int valor){
	if (aux->dato == valor){
		printf("\n");
		printf("ELEMENTO ELIMINADO !!!");
		printf("\n");
		eliminarNodo(L,valor);	
	}else if (aux->sgte == NULL){
		printf("\n");
		printf("ERROR : No se encontro !!!");
		printf("\n");
	}else{		
		eliminarX(L,aux->sgte,valor);
	}
}
//ejercicio 12
int calcularMaximo(Nodo *aux, int mayor){
	if (aux->sgte == NULL){
		return mayor;
	}else{
		if(mayor < aux->dato){
			return calcularMaximo(aux->sgte,aux->dato);
		}else{
			return calcularMaximo(aux->sgte,mayor);
		}
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

void ingresarElementoDespues(Lista *L,int valor,int valor_busqueda){
	//valor_busqueda = valor de un numero en la lista para poder insertar un elemento
	//  			   despues de este valor 
	Nodo *aux = L->ini;
	Nodo *nodonuevo; 
	nodonuevo = malloc(sizeof(Nodo));

	nodonuevo->dato = valor;
	nodonuevo->sgte = NULL;
	
	if ( valor_busqueda == aux->dato){
		nodonuevo->sgte = L->ini->sgte;
		L->ini->sgte = nodonuevo;
		L->tam = L->tam +1 ;

	}else{
		//ciclo para iterar en la lista hasta el nodo final
		int control = 0; // variable de control para romper el ciclo en un punto
		while(aux->sgte != NULL && control == 0){
			 	
			if (aux->dato == valor_busqueda){
				nodonuevo->sgte = aux->sgte;
				aux->sgte = nodonuevo;
				L->tam = L->tam +1 ;
				control = 1;
			}else{
				//este if sirve es cuando alguien quiere usar esta funcion para insertar
				//un elemento despues del final
				if (valor_busqueda == aux->dato && aux->sgte == L->fin){
						//llama a la funcion insertar al final 
						insertarFinal(L,valor);
						L->tam = L->tam +1 ;
						control = 1;
				}
			}
			aux = aux->sgte;
		}
	}
}

void ordenarLista(Lista *L,Nodo *aux,Nodo *aux2){
	if(aux->sgte != NULL && aux2->sgte != NULL){
		if (aux2->dato > aux2->sgte->dato){
			int num;
			num = aux2->dato;
			aux2->dato = aux2->sgte->dato;
			aux2->sgte->dato = num;
			ordenarLista(L,aux,aux2->sgte);	
		}
		ordenarLista(L,aux,aux2->sgte);
	}else if(aux->sgte == NULL){
		printf("");
	}else{
		aux2 = L->ini;
		ordenarLista(L,aux->sgte,aux2);	
	}
}
//ejercicio 13
void insertarOrdenado(Lista *L,Nodo *aux, int x){
	if(x >= aux->dato && x <= aux->sgte->dato){
		//condicional para agregar elemento de forma correcta
		ingresarElementoDespues(L,x,aux->dato);
		printf("\n");
		printf("Dato ingresado de forma exitosa !!! ");
		printf("\n");
	}else if(x < L->ini->dato){
		//condicional para agregar elemento antes del inicio de la lista
		insertarElemento(L,x);
		printf("\n");
		printf("Dato ingresado de forma exitosa !!! ");
		printf("\n");
	}else if(x > L->fin->dato){
		//condicional para verificar si el dato a agregar sera al final de la lista
		insertarFinal(L,x);
		printf("\n");
		printf("Dato ingresado de forma exitosa !!! ");	
		printf("\n");
	}else if(aux->sgte == NULL){
		printf("");
	}else{
		insertarOrdenado(L,aux->sgte,x);
	}
}

//Ejercicio 09 : verificar si son iguales los elementos de la lista
bool sonIguales(Nodo *aux1,Nodo *aux2,int tam1, int tam2){
	if (tam1 != tam2){
		return false;
	}else{
		if(aux1 == NULL){
			return true;
		}else{
			if (aux1->dato != aux2->dato){
				return false;
			}else{
				sonIguales(aux1->sgte,aux2->sgte,tam1,tam2);
			}
		}
	}
}

int main(){
	Lista *L;
	L = crearLista();
	int cont = 1;
	printf("INGRESAR ELEMENTOS A LA LISTA 1 ");
	printf("\n");
	while (cont == 1){
		llenarLista(L);
		printf("Desea ingresar otro numero ? Si (1) / NO (0) indicar numero : ");
		scanf("%i",&cont);
	}
	system("cls");
	Lista *L2; //lista 2 vacia para ejercicio 09
	L2 = crearLista();	
	int otro = 1;//variable de control de ciclo para el menu
	while (otro == 1 ){
		int menu;//menu de opciones para veer los ejercicios propuestos
		printf("\n");
		printf("ELEGIR UNA OPCION : ");
		printf("\n");
		menu = opc();
		Nodo *aux;
		aux = L->ini;//auxiliar que apunta al inicio  de la lista
		if (menu == 1){
			//Ejercicio N° 06	
			int n,x;//n : cantidad de ocurrencias ; x : numero para calcular ocurrencias
			printf("\n");
			printf("Ingrese numero para Calcular Ocurrencia en Lista 1 : ");
			scanf("%i",&x);
			printf("\n");
			n = calcularOcurrencia(aux,x);
			printf("------> Ocurrencia de numero %i es : %i",x,n);
			printf("\n");
		}else if (menu == 2){
			//EJERCICIO Nº 07
			int suma;//variable que almacena los elementos de la lista
			suma = sumaLista(aux,L->tam);
			printf("\n");
			printf("La suma de los elementos de a Lista es : %i",suma);
			printf("\n");
		}else if(menu == 3){
			//EJERCICIO Nª 08
			printf("\n");
			printf("Los valores de la lista son : \n");
			printf("\n");
			listarLista(aux);
		}else if(menu == 4){
			//Ejercicio n° 09 
			printf("\n");
			printf("INGRESAR ELEMENTOS A LA LISTA 2 ");
			printf("\n");
			int cont2 = 1 ;
			while (cont2 == 1){
				llenarLista(L2);
				printf("Desea ingresar otro numero ? Si (1) / NO (0) indicar numero : ");
				scanf("%i",&cont2);
			}
			Nodo *aux2;	
			aux2 = L2->ini;
			
			if (sonIguales(aux,aux2,L->tam,L2->tam)){
				printf("\n");
				printf("LISTA 1 Y LISTA 2 SON IGUALES !!!");
				printf("\n");
			}else{
				printf("\n");
				printf("LISTA 1 Y LISTA 2 NO SON IGUALES !!!");
				printf("\n");
			}
			L2 = crearLista();
			
		}else if(menu == 5){
			//ejercicio nº 10
			int buscar;
			printf("\n");
			printf("Buscar elemento en la lista 1 \n");
			printf("\n");
			printf("Ingresar elemento a buscar : ");
			scanf("%i",&buscar);
			if (existeElemento(aux,buscar)){
				printf("\n");
				printf("El elemento ingresado SI existe en la lista 1.");
				printf("\n");
			}else{
				printf("\n");
				printf("El elemento ingresado NO existe en la lista 1.");
				printf("\n");
			}
		}else if(menu == 6){
			//ejercicio nº 11
			int numero_eliminar;
			printf("\n");
			printf("Ingresar elemento a eliminar en lista 1 : ");
			scanf("%i",&numero_eliminar);
			printf("\n");
			eliminarX(L,aux,numero_eliminar);	
		}else if(menu == 7){
			// ejercicio n° 12
			int mayor = 0;
			mayor = calcularMaximo(aux,mayor);
			printf("\n");
			printf("El mayor elemento de la Lista 1 es : %i",mayor);
			printf("\n");
		}else if(menu == 8){
			//ejercicio n° 13
			int x;
			Nodo *aux2;
			aux2 = L->ini->sgte;
			ordenarLista(L,aux,aux2);
			printf("\n");
			printf("Valores actuales de la lista : \n");
			printf("\n");
			listarLista(aux);
			printf("\n");
			printf("Indicar elemento X para ser insertado de forma ordenada : ");
			scanf("%i",&x); 
			printf("\n");
			insertarOrdenado(L,aux,x);
			printf("\n");
			printf("Con valor ingresado : \n");
			printf("\n");
			Nodo *aux1 = L->ini;
			listarLista(aux1);
			
		}else if(menu == 9){
			//ejercicio n° 14
			Nodo *aux2;
			aux2 = L->ini->sgte;
			printf("\n");
			printf("Lista 1 ordenada :\n");
			printf("\n");
			ordenarLista(L,aux,aux2);
			aux=L->ini;
			listarLista(aux);
		}else if(menu == 10){
			//ejercicio nº 15(incompleto)
		}	
		printf("\n");
		printf("Regresar al MENU (1) / SALIR (0) , ingresar opcion : ");
		scanf("%i",&otro);
		system("cls");
	}
	return 0;
}

