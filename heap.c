#include "aventura.h"

int comparar_numeros(void* elemento1, void* elemento2){
    if(!elemento1 || !elemento2)
        return 0;

    if ( *(int*)elemento1 > *(int*)elemento2 ) return -1;
    if ( *(int*)elemento1 < *(int*)elemento2 ) return  1;
    return 0;
}

heap_t* crear_heap(heap_comparador comparador)
{
    heap_t* heap = calloc(1, sizeof(heap_t));
    heap->comparador = comparador;
    return heap;
}

/* size_t padre(size_t i): Funcion que devuelve el indice que corresponde al padre de cierto elemento del heap. */
size_t padre(size_t i)
{   
    return (i-1)/2;
}

/* size_t izq(size_t i): Funcion que devuelve el indice que corresponde al hijo izquierdo de cierto elemento del heap. */
size_t izq(size_t i)
{   
    return (2*i)+1;
}

/* size_t der(size_t i): Funcion que devuelve el indice que corresponde al hijo derecho de cierto elemento del heap. */
size_t der(size_t i)
{   
    return (2*i)+2;
}

void swap(void** i, void** j) {
	void** aux = *i;
	*i = *j;
	*j = aux;
}

void sift_up(heap_t* heap, size_t indice)
{
    if (indice == 0)
		return;

	size_t i_padre = padre(indice);
	if (heap->comparador(heap->vector[indice], heap->vector[i_padre]) > 0)
    {
		swap(heap->vector + indice, heap->vector + i_padre);
		sift_up(heap, i_padre);
	}
}

int heap_insertar(heap_t* heap, void* elemento)
{
    void** vector_aux = realloc(heap->vector, sizeof(void*)*(heap->tope+1) );
    if (!vector_aux) return -1;
    heap->vector = vector_aux;
    heap->vector[heap->tope] = elemento;
    sift_up(heap, heap->tope);
    heap->tope++;
    return 0;
}

void sift_down(heap_t* heap, size_t indice)
{   
    size_t i_der = der(indice);
    size_t i_izq = izq(indice);
    
    if (!heap || i_izq >= heap->tope) return;
    if (i_der >= heap->tope || heap->comparador(heap->vector[i_izq], heap->vector[i_der]) > 0)
    {
		if (heap->comparador(heap->vector[i_izq], heap->vector[indice]) > 0)
        {
			swap(heap->vector + indice, heap->vector + i_izq);
			sift_down(heap, i_izq);
		}
	} 
    else if (heap->comparador(heap->vector[i_der], heap->vector[indice]) > 0)
    {
		swap(heap->vector + indice, heap->vector + i_der);
		sift_down(heap, i_der);
	}
    return;
}

void* heap_extraer_raiz(heap_t* heap)
{
    if (!heap || heap->tope == 0) return NULL;

    void* elemento = heap->vector[0];
    heap->tope--;
    heap->vector[0] = heap->vector[heap->tope];
    
    heap->vector = realloc(heap->vector, sizeof(void*)*heap->tope);
    if (heap->tope != 0) sift_down(heap, 0);
    return elemento;
}

void heap_destruir(heap_t* heap)
{
    if (!heap || heap->tope == 0) return;
    while (heap->tope !=0)
    {
        heap_extraer_raiz(heap);
    }
    free(heap);
    return;

}
