#include "aventura.h"

typedef int (*funcion_batalla)(void*, void*);

/* int comparar_gimnasios(void* e1, void* e2) : Funcion que según dos gimnasios dados, se les compara su dificultad y devuelve:
   -1 si el primero es mas grande, 1 si el segundo es más grande, 0 si son iguales o hay error.
*/
int comparar_gimnasios(void* e1, void* e2)
{
    if(!e1 || !e2) return 0;
    gimnasio_t* e1_aux = (gimnasio_t*)e1;
    gimnasio_t* e2_aux = (gimnasio_t*)e2;

    if ( e1_aux->dificultad > e2_aux->dificultad ) return -1;
    if ( e1_aux->dificultad < e2_aux->dificultad ) return  1;
    return 0;
}
/* void gimnasio_completado(gimnasio_t* gimnasio) : Procedimiento que a partir de una impresión le notifica al usuario que completó el
   gimnasio.
*/
void gimnasio_completado(gimnasio_t* gimnasio)
{
    printf("                                  Has conseguido la medalla del gimnasio: %s \n", gimnasio->nombre);
    printf("\n");
    printf("                                                         |@@@@|     |####| \n");
    printf("                                                         |@@@@|     |####| \n");
    printf("                                                         |@@@@|     |####| \n");
    printf("                                                         \\@@@@|     |####/ \n");
    printf("                                                          \\@@@|     |###/ \n");
    printf("                                                           `@@|_____|##' \n");
    printf("                                                                (O) \n");
    printf("                                                             .-'''''-. \n");
    printf("                                                           .'  * * *  `. \n");
    printf("                                                          :  *       *  : \n");
    printf("                                                         : ~           ~ : \n");
    printf("                                                         : ~           ~ : \n");
    printf("                                                          :  *       *  : \n");
    printf("                                                           `.  * * *  .' \n");
    printf("                                                             `-.....-' \n");
    liberar_gimnasio(gimnasio);
}
/* int liberar_gimnasio(gimnasio_t* gimnasio) : Funcion que dado un gimnasio, libera su memoria. Devuelve EXITO o ERROR.
*/
int liberar_heap_gimnasios(heap_t* heap)
{
    if (!heap) return ERROR;
    while (heap->tope !=0)
    {
        liberar_gimnasio(heap_extraer_raiz(heap));
    }
    return EXITO;
    free(heap);
    return EXITO;
}
/* int liberar_gimnasio(gimnasio_t* gimnasio) : Funcion que dado un gimnasio, libera su memoria. Devuelve EXITO o ERROR.
*/
int liberar_gimnasio(gimnasio_t* gimnasio)
{
    if (!gimnasio) return ERROR;
    if (gimnasio->c_entrenadores > 0) 
    {   
        for(int i = 0 ; i < gimnasio->c_entrenadores ; i++)
        {   
        liberar_entrenador(lista_tope(gimnasio->entrenadores));
        lista_desapilar(gimnasio->entrenadores);
        }
    }
    if (gimnasio->entrenadores) lista_destruir(gimnasio->entrenadores);
    free(gimnasio);
    return EXITO;
}
/* int liberar_entrenador(entrenador_t* entrenador) : Funcion que dado un entrenador, libera su memoria. Devuelve EXITO o ERROR.
*/
int liberar_entrenador(entrenador_t* entrenador)
{
    if (!entrenador) return ERROR;
    if (entrenador->c_pokemones > 0) 
    {   
        lista_iterador_t* it = lista_iterador_crear(entrenador->pokemones);
        for(int i = 0 ; i < entrenador->c_pokemones ; i++)
        {   
        free(lista_iterador_elemento_actual(it));
        if (lista_iterador_tiene_siguiente(it)) lista_iterador_avanzar(it);
        }
        lista_iterador_destruir(it);
    }
    if (entrenador->pokemones) lista_destruir(entrenador->pokemones);
    free(entrenador);
    return EXITO;
}
/* void informacion_gimnasio(gimnasio_t* gimnasio) : Procedimiento que dado un gimnasio, imprime su información.
*/
void informacion_gimnasio(gimnasio_t* gimnasio)
{   
    if (!gimnasio) return;
    print_pokemon();
    printf("\n");
    printf("                                                     Informacion del gimnasio:\n");
    printf("%78s \n", gimnasio->nombre);
    printf("                                                           Dificultad: %i\n", gimnasio->dificultad);
    printf("                                                         N° entrenadores: %li\n", gimnasio->c_entrenadores);
    entrenador_t* lider = lista_primero(gimnasio->entrenadores); // Exceptúo el comportamiento de pila para conseguir el lider facilmente
    printf("                                                          Lider: %s\n", lider->nombre); 
    printf("                                                           Id batalla: %li\n", gimnasio->id_puntero); 
}
/* void mostrar_pokemones_entrenador(entrenador_t* entrenador) : Procedimiento que dado un entrenador, imprime sus pokemones.
*/
void mostrar_pokemones_entrenador(entrenador_t* entrenador)
{
    if (!entrenador || !entrenador->pokemones) return;
    printf("\n");
    print_pokemon();
    printf("                                                Pokemones obtenidos por %s \n", entrenador->nombre);
    printf("                                    Nombre | Velocidad | Ataque | Defensa | Bonus (max. 63)\n");
    if (entrenador->c_pokemones > 0)
    {   
        nodo_t* nodo = entrenador->pokemones->nodo_inicio;
        for (int i = 0 ; i < entrenador->c_pokemones ; i++)
        {   
            mostrar_pokemon(nodo->elemento);
            nodo = nodo->siguiente;    
            if (!nodo) return;
        }
    }
    printf("\n");
}
/* gimnasio_t* crear_gimnasio(char nombre[], int dificultad, size_t id_p) : Funcion que a partir de los parametros dados, se
   crea un gimnasio_t con los datos proporcionados. Devuelve un puntero al struct.
*/
gimnasio_t* crear_gimnasio(char nombre[], int dificultad, size_t id_p)
{
    gimnasio_t* gimnasio = calloc(sizeof(gimnasio_t), 1);
    if (!gimnasio) return NULL;
    strcpy(gimnasio->nombre, nombre);
    gimnasio->entrenadores = lista_crear();
    gimnasio->dificultad = dificultad;
    gimnasio->id_puntero = id_p;
    return gimnasio;
}
/* entrenador_t* crear_entrenador(char nombre[], bool lider) : Funcion que a partir de los parametros dados, se
   crea un entrenador_t con los datos proporcionados. Devuelve un puntero al struct.
*/
entrenador_t* crear_entrenador(char nombre[], bool lider)
{
    entrenador_t* entrenador = calloc(1, sizeof(entrenador_t));
    if (!entrenador) return NULL;
    strcpy(entrenador->nombre, nombre);
    entrenador->pokemones = lista_crear();
    entrenador->lider = lider;
    return entrenador;
}
/* gimnasio_t* leer_gimnasio(char linea[]) :  Funcion que recibe una linea estructurada de la cual se crea un gimnasio. Devuelve NULL
   si hay error, si hay exito, se devuelve el puntero al gimnasio.
*/
gimnasio_t* leer_gimnasio(char linea[])
{   
    char tipo, nombre[MAX_NOMBRE];
    int dificultad;
    size_t id_p;
    int leidos = sscanf(linea, FORMATO_GIM, &tipo, nombre, &dificultad, &id_p);
    if (leidos != 4) return NULL;
    gimnasio_t* gimnasio = crear_gimnasio(nombre, dificultad, id_p);
    if (!gimnasio) return NULL;
    return gimnasio;
}
/* entrenador_t* leer_entrenador(char linea[], gimnasio_t* gimnasio) :  Funcion que recibe una linea estructurada de la
   cual se crea un entrenador y gimnasio al cual se le agregará el entrenador. Devuelve NULL si se tuvo éxito, caso contrario
   el puntero al entrenador.
*/
entrenador_t* leer_entrenador(char linea[], gimnasio_t* gimnasio)
{   
    if (!gimnasio) return NULL;
    entrenador_t* entrenador;
    char tipo, nombre[MAX_NOMBRE];
    int leidos = sscanf(linea, FORMATO_ENT, &tipo, nombre);
    if (leidos != 2) return NULL;
    if (tipo == 'L') entrenador = crear_entrenador(nombre, true);
    if (tipo == 'E') entrenador = crear_entrenador(nombre, false);
    if (entrenador)
    {   
        lista_apilar(gimnasio->entrenadores, entrenador);
        gimnasio->c_entrenadores++;
    }
    else return NULL;
    return entrenador;
}
/* int leer_pokemon(char linea[], entrenador_t* entrenador, personaje_t* personaje) : Funcion que recibe una linea estructurada de la
   cual se crea un pokemon y un entrenador o personaje (nunca los 2 juntos) al cual se le agregará el pokémon. Devuelve si se tuvo éxito
   o no.
*/
int leer_pokemon(char linea[], entrenador_t* entrenador, personaje_t* personaje)
{   
    if (!entrenador || !personaje ) return ERROR;
    char tipo, nombre[MAX_NOMBRE];
    int veloc, ataq, def;
    int leidos = sscanf(linea, FORMATO_POK, &tipo, nombre, &veloc, &ataq, &def);
    if (leidos != 5) return ERROR;
    pokemon_t* pokemon = crear_pokemon(nombre, veloc, ataq, def);
    if (pokemon)
    {   
        if (entrenador)
        {
            lista_insertar(entrenador->pokemones, pokemon);
            entrenador->c_pokemones++;
        }
        else
        {
            lista_insertar(personaje->pokemon_obtenidos, pokemon);
            if (personaje->c_pokemones < MAX_PARTY) lista_insertar(personaje->pokemon_para_combatir, pokemon);
            personaje->c_pokemones++;
        }
    }
    else return ERROR;
    return EXITO;
}
/* pokemon_t* crear_pokemon(char nombre[], int velocidad, int ataque, int defensa) : Funcion que a partir de los parametros dados, se
   crea un pokemon_t con los datos proporcionados. Devuelve un puntero al struct.
*/
pokemon_t* crear_pokemon(char nombre[], int velocidad, int ataque, int defensa)
{
    pokemon_t* pokemon = malloc(sizeof(pokemon_t));
    if (!pokemon) return NULL;
    strcpy(pokemon->nombre, nombre);
    pokemon->velocidad = velocidad;
    pokemon->ataque = ataque;
    pokemon->defensa = defensa;
    pokemon->bonus = 0;
    return pokemon;
}

/* void leer_archivo_gimnasio(heap_t* heap, const char* nombre_archivo) : Procedimiento que recibe la ruta de un archivo de texto 
   estructurado del cual lee linea a linea su información para introducirla a un struct heap_t. dado */

void leer_archivo_gimnasio(heap_t* heap, const char* nombre_archivo)
{   
    bool bandera = true;
    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) return;
    char linea[MAX_LINEA];
    gimnasio_t* gimnasio = NULL;
    entrenador_t* entrenador;
    while(fgets(linea, MAX_LINEA, (FILE*) archivo) && bandera)
    {   
        if (linea[0] == 'G')
        {   
            if (gimnasio) heap_insertar(heap, gimnasio);
            gimnasio = leer_gimnasio(linea);
            if (!gimnasio) bandera = false;
        }
        if ((linea[0] == 'L') || (linea[0] == 'E')) 
        {
            entrenador = leer_entrenador(linea, gimnasio);
            if (!entrenador) bandera = false;
        }
        if (linea[0] == 'P')
        {
            if (leer_pokemon(linea, entrenador, NULL) == ERROR) bandera = false;
        }
    }
    if (gimnasio)
    {   
        if (gimnasio->c_entrenadores == 0) liberar_gimnasio(gimnasio);
        else heap_insertar(heap, gimnasio);
    }
    fclose(archivo); 
    return;
}