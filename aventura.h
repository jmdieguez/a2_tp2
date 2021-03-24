#ifndef __AVENTURA_H__
#define __AVENTURA_H__

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "lista.h"
#include "heap.h"
#include <string.h>

#define FORMATO_GIM "%c;%[^;];%i;%li\n"
#define FORMATO_POK "%c;%[^;];%i;%i;%i\n"
#define FORMATO_ENT "%c;%[^\n]\n"
#define ERROR -1
#define EXITO 0
#define G_PRIMERO 1
#define G_SEGUNDO -1
#define MAX_PARTY 6
#define MAX_BONUS 63
#define MAX_NOMBRE 30
#define MAX_LINEA 100
#define MAX_ARCHIVO 30
typedef int (*funcion_batalla)(void*, void*);

//                                                ESTRUCTURAS

typedef struct pokemon{
    char nombre[MAX_NOMBRE];
    int velocidad;
    int ataque;
    int defensa;
    int bonus;
}pokemon_t;

typedef struct entrenador{
    char nombre[MAX_NOMBRE];
    lista_t* pokemones;
    bool lider;
    bool vencido;
    int c_pokemones;
}entrenador_t;

typedef struct gimnasio{
    char nombre[MAX_NOMBRE];
    int dificultad;
    size_t id_puntero;
    lista_t* entrenadores;
    size_t c_entrenadores;
}gimnasio_t;

typedef struct personaje{
    char nombre[MAX_NOMBRE];
    lista_t* pokemon_para_combatir;
    lista_t* pokemon_obtenidos;
    int c_pokemones;
}personaje_t;

//                                              FUNCIONES                                             

// GIMNASIO: 
int liberar_heap_gimnasios(heap_t* heap);
gimnasio_t* crear_gimnasio();
gimnasio_t* leer_gimnasio(char linea[]);
void leer_archivo_gimnasio(heap_t* heap, const char* nombre_archivo);
void informacion_gimnasio(gimnasio_t* gimnasio);
int liberar_gimnasio(gimnasio_t* gimnasio);
void gimnasio_completado(gimnasio_t* gimnasio);
int comparar_gimnasios(void* elemento1, void* elemento2);

entrenador_t* leer_entrenador(char linea[], gimnasio_t* gimnasio);
entrenador_t* crear_entrenador(char* nombre, bool lider);
int liberar_entrenador(entrenador_t* entrenador);
void mostrar_pokemones_entrenador(entrenador_t* entrenador);

int leer_pokemon(char linea[], entrenador_t* entrenador, personaje_t* personaje);
pokemon_t* crear_pokemon(char* nombre, int velocidad, int ataque, int defensa);
bool liberar_pokemon(void* elemento, void* contador);

// PERSONAJE:
int liberar_personaje(personaje_t* personaje);
personaje_t* crear_personaje();
void reacomodar_batalla(personaje_t* personaje);
personaje_t* leer_personaje(char linea[]);
personaje_t* leer_archivo_personaje(const char* nombre_archivo);
void mostrar_pokemones(personaje_t* personaje);
void mostrar_pokemon(pokemon_t* pokemon);
int swap_pokemones(lista_t* pokemones, char pok1[], char pok2[], int cantidad);
void cambiar_pokemones(personaje_t* personaje);
void bonificar_pokemon(pokemon_t* pokemon);
void tomar_pokemon(personaje_t* personaje, entrenador_t* entrenador);

// OTROS
void print_pokemon();
int batallar(lista_t* pkm_personaje, lista_t* pkm_entrenador, size_t id_p, bool sim);
#endif /* __AVENTURA_H__ */