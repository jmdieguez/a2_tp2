#ifndef HEAP_H
#define HEAP_H

typedef int (*heap_comparador)(void* a, void* b);

typedef struct heap{
    void** vector;
    size_t tope;
    heap_comparador comparador;
}heap_t;

// FUNCIONES HEAP: 
heap_t* crear_heap(heap_comparador comparador);
size_t padre(size_t i);
size_t izq(size_t i);
size_t der(size_t i);
void swap(void** i, void** j);
void sift_up(heap_t* heap, size_t indice);
int heap_insertar(heap_t* heap, void* elemento);
void sift_down(heap_t* heap, size_t indice);
void* heap_extraer_raiz(heap_t* heap);
void heap_destruir(heap_t* heap);

//EXTRA
int comparar_numeros(void* elemento1, void* elemento2);
#endif  // HEAP_H