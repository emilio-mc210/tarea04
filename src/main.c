#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"

void test_stack() {
    STACK stack;
    printf("Probando la implementación de 'stack'\n");
    stack_init(&stack);

    printf("Agregando 100 elementos...\n");
    for (int i = 1; i <= 100; i++) {
        if (stack_push(&stack, i) == -1) {
            printf("Error en push %d\n", i);
        }
    }

    printf("Tamaño: %u (esperado: 100)\n", stack_size(&stack));
    printf("Stack lleno? %d (esperado: 1)\n", stack_is_full(&stack));

    printf("Intentando un push más...\n");
    printf("Resultado del push: %d (esperado: -1)\n", stack_push(&stack, 101));

    printf("Sacando 5 elementos...\n");
    for (int i = 0; i < 5; i++) {
        printf("Popped %d (esperado: %d)\n", stack_pop(&stack), 100 - i);
    }

    printf("Tamaño: %u (esperado: 95)\n", stack_size(&stack));
    printf("Stack vacío? %d (esperado: 0)\n", stack_is_empty(&stack));

    printf("Vaciando el stack...\n");
    while (!stack_is_empty(&stack)) {
        stack_pop(&stack);
    }

    printf("Tamaño: %u (esperado: 0)\n", stack_size(&stack));
    printf("Stack vacío? %d (esperado: 1)\n", stack_is_empty(&stack));

    printf("Pop de un stack vacío...\n");
    printf("Popped: %d (esperado: -1)\n", stack_pop(&stack));
}

void test_linked_list() {
    LISTA lista;
    printf("\nTesting Linked List implementation...\n");
    linked_list_init(&lista);
    
    printf("Agregando 10, 20, 30...\n");
    linked_list_append(&lista, 10);
    linked_list_append(&lista, 20);
    linked_list_append(&lista, 30);
    
    printf("Agregando 5 al inicio...\n");
    linked_list_prepend(&lista, 5);

    printf("Lista (debería ser 5, 10, 20, 30): ");
    linked_list_print(&lista);

    printf("Tamaño: %u (esperado: 4)\n", linked_list_size(&lista));
    printf("¿Contiene a 20? %d (esperado: 1)\n", linked_list_contains(&lista, 20));
    printf("¿Contiene a 99? %d (esperado: 0)\n", linked_list_contains(&lista, 99));

    printf("Quitando 20...\n");
    linked_list_remove(&lista, 20);

    printf("Lista (debería ser 5, 10, 30): ");
    linked_list_print(&lista);
    printf("Quitando 99...\n");
    printf("Resultado: %d (esperado: -1)\n", linked_list_remove(&lista, 99));
    printf("Tamaño: %u (esperado: 3)\n", linked_list_size(&lista));

    linked_list_free(&lista);
}

int main() {
    test_stack();
    test_linked_list();
    return 0;
}