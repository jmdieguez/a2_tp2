#include "batallas.h"
#include "aventura.h"

/* Funciones de batalla: Dados dos pokémones, se comparan sus stats y se decide un ganador. Devuelve int = quién gana.
*/

int funcion_batalla_1(void* pkm_1, void* pkm_2)
{
    if (!pkm_1 || !pkm_2 ) return 0;
    pokemon_t* pokemon_1 = (pokemon_t*)pkm_1;
    pokemon_t* pokemon_2 = (pokemon_t*)pkm_2;

    float stats1 = ((float)pokemon_1->ataque + (float)pokemon_1->velocidad) / 2 ;
    float stats2 = (float)pokemon_2->defensa; 

    if (stats1 >= stats2) return GANO_PRIMERO;
    else return GANO_SEGUNDO;
}

int funcion_batalla_2(void* pkm_1, void* pkm_2)
{
    if (!pkm_1 || !pkm_2 ) return 0;
    pokemon_t* pokemon_1 = (pokemon_t*)pkm_1;
    pokemon_t* pokemon_2 = (pokemon_t*)pkm_2;

    if (pokemon_1->defensa >= pokemon_2->ataque) return GANO_PRIMERO;
    else return GANO_SEGUNDO;
}

int funcion_batalla_3(void* pkm_1, void* pkm_2)
{
    if (!pkm_1 || !pkm_2 ) return 0;
    pokemon_t* pokemon_1 = (pokemon_t*)pkm_1;
    pokemon_t* pokemon_2 = (pokemon_t*)pkm_2;

    if (pokemon_1->ataque >= pokemon_2->ataque) return GANO_PRIMERO;
    else return GANO_SEGUNDO;
}

int funcion_batalla_4(void* pkm_1, void* pkm_2)
{
    if (!pkm_1 || !pkm_2 ) return 0;
    pokemon_t* pokemon_1 = (pokemon_t*)pkm_1;
    pokemon_t* pokemon_2 = (pokemon_t*)pkm_2;

    int stats1 = pokemon_1->ataque + pokemon_1->velocidad + pokemon_1->defensa;
    int stats2 = pokemon_2->ataque + pokemon_2->velocidad + pokemon_2->defensa;
    if (stats1 >= stats2) return GANO_PRIMERO;
    else return GANO_SEGUNDO;
}

int funcion_batalla_5(void* pkm_1, void* pkm_2)
{
    if (!pkm_1 || !pkm_2 ) return 0;
    pokemon_t* pokemon_1 = (pokemon_t*)pkm_1;
    pokemon_t* pokemon_2 = (pokemon_t*)pkm_2;

    if (pokemon_1->velocidad >= pokemon_2->velocidad) return GANO_PRIMERO;
    else return GANO_SEGUNDO;
}

/* int aplicar_funcion_batalla(size_t id_p, nodo_t* nodo_p, nodo_t* nodo_e) : Dados dos nodos que contienen pokemones, se aplica la
   funcion de batalla que corresponde segun id_p.
*/
int aplicar_funcion_batalla(size_t id_p, nodo_t* nodo_p, nodo_t* nodo_e)
{   
    if (id_p > 5 || id_p < 1 || !nodo_p || !nodo_e ) return 0;
    int resultado;
    if      (id_p == 1) resultado = funcion_batalla_1(nodo_p, nodo_e);
    else if (id_p == 2) resultado = funcion_batalla_2(nodo_p, nodo_e);
    else if (id_p == 3) resultado = funcion_batalla_3(nodo_p, nodo_e);
    else if (id_p == 4) resultado = funcion_batalla_4(nodo_p, nodo_e);
    else if (id_p == 5) resultado = funcion_batalla_5(nodo_p, nodo_e);
    return resultado;
}
/* int batallar(lista_t* pkm_personaje, lista_t* pkm_entrenador, size_t id_p, bool sim) : Dados un personaje y un entrenador, se 
   desarrolla la batalla pokemon entre sus pokémones. 
*/
int batallar(lista_t* pkm_personaje, lista_t* pkm_entrenador, size_t id_p, bool sim)
{   
    if (!pkm_personaje || !pkm_entrenador || id_p > 5 || id_p < 1) return 0;
    nodo_t* nodo_p = pkm_personaje->nodo_inicio; /* p->personaje */ nodo_t* nodo_e = pkm_entrenador->nodo_inicio; /* e->entrenador*/
    pokemon_t* pokemon_p;
    pokemon_t* pokemon_e;
    bool bandera = true;
    int resultado;
    while(bandera)
    {
        if (!nodo_p && !nodo_e)     return 0;
        else if (nodo_p && !nodo_e) return GANO_PRIMERO;
        else if (!nodo_p && nodo_e) return GANO_SEGUNDO;
        pokemon_p = nodo_p->elemento;
        pokemon_e = nodo_e->elemento;
        if (!sim)
        {
            mostrar_pokemon(pokemon_p);
            printf("                                                            vs \n");
            mostrar_pokemon(pokemon_e);
            getchar();
        }
        resultado = aplicar_funcion_batalla(id_p, nodo_p->elemento, nodo_e->elemento);
        if      (resultado == GANO_PRIMERO)
        {   
            if (!sim) printf("                                   %s ha ganado el combate contra %s \n", pokemon_p->nombre, pokemon_e->nombre);
            nodo_e = nodo_e->siguiente;
            bonificar_pokemon(pokemon_p);
        }
        else if (resultado ==  GANO_SEGUNDO)
        {   
            if (!sim) printf("                                   %s ha perdido el combate contra %s \n", pokemon_p->nombre, pokemon_e->nombre);
            nodo_p = nodo_p->siguiente;
        }
        if (!sim) getchar();
    }
    return 0;
}