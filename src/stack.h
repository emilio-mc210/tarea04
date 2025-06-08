#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

/*
*STACK
*Coleccion de enteros que sigue el principio LIFO con un arreglo
*Tiene tamano MAX_SIZE
*arr[]: es el arreglo que almacena los elementos
*top: tope actual del stack
*/
typedef struct {
    int arr[MAX_SIZE];
    int top; //Indice del elemento superior de la pila
} STACK;

/*
*Funcion que inicializa el stack
*Regresa el tamano del stack
*/
void stack_init(STACK *stack);

/*
*Funcion que agrega un elemento al stack
*0: exito
*-1: stack lleno
*/
int stack_push(STACK *stack, unsigned int data);

/*
*Funcion que saca un elemento al stack
*Regresa el elemento: exito
*-1: stack vacio
*/
int stack_pop(STACK *stack);

/*
*Funcion que obtiene el tamano del stack
*Regresa el tamano del stack
*/
unsigned int stack_size(STACK *stack);

/*
*Funcion que obtiene si el stack esta lleno
*1: lleno
*0: no lleno
*/
int stack_is_full(STACK *stack);

/*
*Funcion que obtiene si el stack esta vacio
*1: vacio
*0: no vacoi
*/
int stack_is_empty(STACK *stack);

#endif // STACK_H