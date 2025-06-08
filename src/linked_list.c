#include<stdlib.h>
#include<stdio.h>
#include"linked_list.h"

// Inicializar la lista
void linked_list_init(LISTA *lista){
    lista->head = NULL;
}

// Agregar un elemento al headal de la lista
// 0: éxito, -1: error
int linked_list_append(LISTA *lista, int data){
    NODO *nuevo = (NODO *)malloc(sizeof(NODO));

    //Revisar que se logro crear el nodo
    if(!nuevo) return -1;
    
    //Agregar datos al nodo nuevo
    nuevo->info = data;
    nuevo->next = NULL;

    //Cambiar el inicio de la lista si esta vacia
    if(lista->head == NULL){
        lista->head = nuevo;
    }else{
        //Iterar hasta llegar hasta el ultimo nodo
        NODO *actual = lista->head;
        while(actual->next){
            actual = actual->next;
        }
        actual->next = nuevo;
    }

    return 0;
}

// Agregar un elemento al inicio de la lista
// 0: éxito, -1: error
int linked_list_prepend(LISTA *lista, int data){
    NODO *nuevo = (NODO *)malloc(sizeof(NODO));
    //Revisar que se logro crear el nodo
    if(!nuevo) return -1;

    //Agregar datos al nodo nuevo
    nuevo->info = data;
    nuevo->next = lista->head;

    //Modificar el inicio
    lista->head = nuevo;

    return 0;
}

// Elimina el primer elemento que coincide con el dato proporcionado
// 0: éxito, -1: error (elemento no encontrado)
int linked_list_remove(LISTA *lista, int data){
    NODO *actual = lista->head;
    NODO *anterior = NULL; //No hay un nodo anterior a 'head'

    //Iterar hasta llegar al nodo que tiene el dato que se quiere eliminar
    while(actual){
        if(actual->info == data){ 
            //Si el primer nodo es el que se tiene que eliminar
            if(anterior == NULL){
                lista->head = actual->next;
            }else{
                //Se evita discontinuidad de la lista
                anterior->next = actual->next;
            }
            free(actual);
            return 0;
        }
        anterior = actual;
        actual = actual->next;
    }
    //Si no se logra encontrar un elemento con el dato
    return -1;
}

// Encontrar un elemento en la lista
// 1: éxito, 0: error (elemento no encontrado)
int linked_list_contains(LISTA *lista, int data){
    NODO *actual = lista->head;
    //Llegar al nodo con el dato
    while(actual){
        if(actual->info == data){
            return 1;
        }
        actual = actual->next;
    }

    return 0;
}

// Regresa el tamaño de la lista
unsigned int linked_list_size(LISTA *lista){
    unsigned int size = 0;
    NODO *actual = lista->head;

    //Legar hasta el ultimo elemento
    while(actual){
        size++;
        actual = actual->next;
    }

    return size;
}

// Imprimir todos los elementos de la lista enlazada
void linked_list_print(LISTA *lista){
    NODO *actual = lista->head;

    while(actual){
        printf("%i ",actual->info);
        actual = actual->next;
    }
    printf("\n");
}

//Liberar memoria del heap
void linked_list_free(LISTA *lista){
    while(lista->head){
        NODO *actual = lista->head;
        lista->head = actual->next;
        free(actual);
    }
}