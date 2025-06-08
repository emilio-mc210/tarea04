# Tarea04
Tarea 4 de plataformas abiertas (IE-0117)

Este repositorio contiene una implementación básica de dos estructuras de datos: **pila (stack)** y **lista enlazada (linked list)**. Se incluyen funciones para manipular ambas estructuras y un archivo `main.c` que realiza pruebas sobre su funcionamiento.

## Requisitos

- `gcc`
- `make`

## Compilacion
Posicionandose en el directorio raíz del proyecto se deben ingresar el siguiente comando:  

        make

Esto generará un directorio de salida (`build/`) con un archivo llamado `main`, que puede ser ejecutado directamente.

### Detalles:

1. Se utilizan múltiples archivos de código fuente, donde el archivo `main` se encarga únicamente de ejecutar pruebas sobre las funciones implementadas en `stack.c` y `linked_list.c`.
2. El uso de un `Makefile` permite compilar todo el proyecto con un solo comando, simplificando el uso para el usuario.
3. Las estructuras `Stack` y `LinkedList` están diseñadas para permitir la creación y manipulación de múltiples instancias independientes, evitando el uso de variables globales.
4. Se agregó una función para liberar memoria de la lista enlazada.

## Resultados:

### Problema 1 (Stack):
    Probando la implementación de 'stack'
    Agregando 100 elementos...
    Tamaño: 100 (esperado: 100)
    Stack lleno? 1 (esperado: 1)
    Intentando un push más...
    Resultado del push: -1 (esperado: -1)
    Sacando 5 elementos...
    Popped 100 (esperado: 100)
    Popped 99 (esperado: 99)
    Popped 98 (esperado: 98)
    Popped 97 (esperado: 97)
    Popped 96 (esperado: 96)
    Tamaño: 95 (esperado: 95)
    Stack vacío? 0 (esperado: 0)
    Vaciando el stack...
    Tamaño: 0 (esperado: 0)
    Stack vacío? 1 (esperado: 1)
    Pop de un stack vacío...
    Popped: -1 (esperado: -1)

### Problema 2 (Lista enlazada):
    Testing Linked List implementation...
    Agregando 10, 20, 30...
    Agregando 5 al inicio...
    Lista (debería ser 5, 10, 20, 30): 5 10 20 30 
    Tamaño: 4 (esperado: 4)
    ¿Contiene a 20? 1 (esperado: 1)
    ¿Contiene a 99? 0 (esperado: 0)
    Quitando 20...
    Lista (debería ser 5, 10, 30): 5 10 30 
    Quitando 99...
    Resultado: -1 (esperado: -1)
    Tamaño: 3 (esperado: 3)
