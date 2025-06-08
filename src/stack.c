#include"stack.h"

// Inicializar stack con un máximo de 100 elementos
void stack_init(STACK *stack){
    stack->top = -1;
}

// Agregar un entero al stack
// 0: éxito, -1: stack lleno
int stack_push(STACK *stack, unsigned int data){
    //Revisar si el stack esta lleno
    if(stack_is_full(stack)){
        return -1;
    }
    //Cambiar el tope actual y darle valor
    stack->top += 1;
    stack->arr[stack->top] = data;

    return 0;
}

// Saca un elemento del stack
// Regresa el entero: éxito, -1: stack está vacío
int stack_pop(STACK *stack){
    //Revisar si el stack esta vacio
    if(stack_is_empty(stack)){
        return -1;
    }
    //Se obtiene el tope actual 
    int popped = stack->arr[stack->top];
    //Se disminuye el tope actual
    (stack->top)--;

    return popped;
}

// Regresa el tamaño
unsigned int stack_size(STACK *stack){
    return stack->top + 1;
}

// 1: lleno, 0: no lleno
int stack_is_full(STACK *stack){
    return (stack->top == MAX_SIZE-1);
}

// 1: vacío, 0: no vacío
int stack_is_empty(STACK *stack){
    return (stack->top == -1);
}