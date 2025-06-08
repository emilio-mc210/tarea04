#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
*NODO
*Nodo para una lista enlazada
*info: Informacion del nodo
*NODO *next: Puntero al siguiente elemento
*/
typedef struct NODO{
    int info;
    struct NODO *next;
} NODO;

/*
*LISTA
*Guarda el primer nodo de la lista enlazada
*/
typedef struct{
    NODO *head;
} LISTA;

// Inicializar la lista
void linked_list_init(LISTA *lista);

// Agregar un elemento al final de la lista
// 0: éxito, -1: error
int linked_list_append(LISTA *lista, int data);

// Agregar un elemento al inicio de la lista
// 0: éxito, -1: error
int linked_list_prepend(LISTA *lista, int data);

// Elimina el primer elemento que coincide con el dato proporcionado
// 0: éxito, -1: error (elemento no encontrado)
int linked_list_remove(LISTA *lista, int data);

// Encontrar un elemento en la lista
// 1: éxito, 0: error (elemento no encontrado)
int linked_list_contains(LISTA *lista, int data);

// Regresa el tamaño de la lista
unsigned int linked_list_size(LISTA *lista);

// Imprimir todos los elementos de la lista enlazada
void linked_list_print(LISTA *lista);

//Liberar memoria del heap
void linked_list_free(LISTA *lista);

#endif // LINKED_LIST_H