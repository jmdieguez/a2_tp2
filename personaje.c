#include "aventura.h"

/* personaje_t* crear_personaje() : Funcion que crea y guarda en memoria un personaje_t* y devuelve un puntero a él.
*/
personaje_t* crear_personaje()
{
    personaje_t* personaje = calloc(sizeof(personaje_t), 1);
    if (!personaje) return NULL;
    personaje->pokemon_para_combatir = lista_crear();
    personaje->pokemon_obtenidos = lista_crear();
    return personaje;
}
/* void bonificar_pokemon(pokemon_t* pokemon) : Procedimiento que dado un pokémon se le sube +1 a todos sus stats si es que su atributo
   bonus es menor al máximo.
*/
void bonificar_pokemon(pokemon_t* pokemon)
{
    if (!pokemon) return;
    if (pokemon->bonus < MAX_BONUS)
    {
        pokemon->ataque++;
        pokemon->velocidad++;
        pokemon->defensa++;
        pokemon->bonus++;
    }
}
/* int liberar_personaje(personaje_t* personaje) : Funcion que dado un personaje se libera su memoria. Devuelve ERROR o EXITO.
*/
int liberar_personaje(personaje_t* personaje)
{
    if (!personaje) return ERROR;
    if (personaje->c_pokemones > 0) 
    {   
        lista_iterador_t* it = lista_iterador_crear(personaje->pokemon_obtenidos);
        for(int i = 0 ; i < personaje->c_pokemones ; i++)
        {   
        free(lista_iterador_elemento_actual(it));
        if (lista_iterador_tiene_siguiente(it)) lista_iterador_avanzar(it);
        }
        lista_iterador_destruir(it);
    }
    if (personaje->pokemon_obtenidos) lista_destruir(personaje->pokemon_obtenidos);
    if (personaje->pokemon_para_combatir) lista_destruir(personaje->pokemon_para_combatir);
    free(personaje);
    return EXITO;
}
/* void mostrar_pokemon(pokemon_t* poke) : Procedimiento que imprime los stats de un pokémon dado.
*/
void mostrar_pokemon(pokemon_t* poke)
{   
    if (!poke) return;
    printf("                %30s |    %3i    |  %3i   |   %3i   |    %2i\n", poke->nombre, poke->velocidad, poke->ataque, poke->defensa, poke->bonus);
}
/* void mostrar_pokemones(personaje_t* personaje) : Procedimiento que dado un personaje, se llama mostrar_pokemon() a cada uno de sus
   pokemones.
*/
void mostrar_pokemones(personaje_t* personaje)
{
    if (!personaje) return;
    if (!personaje->pokemon_obtenidos) return;
    printf("\n");
    print_pokemon();
    printf("                                                Pokemones obtenidos por %s \n", personaje->nombre);
    printf("                                    Nombre | Velocidad | Ataque | Defensa | Bonus (max. 63)\n");
    if (personaje->c_pokemones > 0)
    {   
        nodo_t* nodo = personaje->pokemon_obtenidos->nodo_inicio;
        for (int i = 0 ; i < personaje->c_pokemones ; i++)
        {   
            if (i == 6) printf("                                 ***********************************************************\n");
            mostrar_pokemon(nodo->elemento);
            nodo = nodo->siguiente;    
            if (!nodo) return;
        }
    }
    printf("\n");
}

/* int swap_pokemones(lista_t* pokemones, char pok1[], char pok2[], int cantidad) : Funcion que dada una lista de pokemones, busca coindidencias
   entre los strings (vector de char) dados con los nombres de los pokemones. Si se encuentran ambos pokemones, se cambia de lugar
   entre ellos.
*/
int swap_pokemones(lista_t* pokemones, char pok1[], char pok2[], int cantidad)
{
    if (!pokemones || !pok1 || !pok2) return ERROR;
    nodo_t* nodo = pokemones->nodo_inicio;
    nodo_t* nodo_pok1;
    nodo_t* nodo_pok2;
    pokemon_t* pokemon;

    for(int i = 0 ; i < cantidad ; i++)
    {   
        pokemon = nodo->elemento;
        if (strcmp(pokemon->nombre, pok1) == 0) nodo_pok1 = nodo;
        if (strcmp(pokemon->nombre, pok2) == 0) nodo_pok2 = nodo;
        if (nodo->siguiente) nodo = nodo->siguiente;
    }

    if ( (nodo_pok1 && nodo_pok2) && (nodo_pok1 != nodo_pok2) )
    {   
        pokemon = nodo_pok1->elemento;
        nodo_pok1->elemento = nodo_pok2->elemento;
        nodo_pok2->elemento = pokemon;
    }
    else return ERROR;
    return EXITO;
}
/* void reacomodar_batalla(personaje_t* personaje) : Procedimiento que dado un personaje, se reacomoda la lista de pokemon_para_combatir
   actualizando sus valores con los primeros de la lista pokemon_obtenidos.
*/
void reacomodar_batalla(personaje_t* personaje)
{
    if (!personaje || !personaje->pokemon_para_combatir || !personaje->pokemon_obtenidos) return;

    nodo_t* nodo_general = personaje->pokemon_obtenidos->nodo_inicio;
    nodo_t* nodo_batalla = personaje->pokemon_para_combatir->nodo_inicio;

    for (size_t i = 0; i < MAX_PARTY; i++)
    {
        if(nodo_general)
        {   
            nodo_batalla->elemento = nodo_general->elemento; 
            nodo_general = nodo_general->siguiente;
            nodo_batalla = nodo_batalla->siguiente;
        }
    }
    return;
}
/* void cambiar_pokemones(personaje_t* personaje) : Procedimiento que dado un personaje, se piden los nombres de dos pokemones los
   cambiarán de lugar en la lista pokemon_obtenidos.
*/
void cambiar_pokemones(personaje_t* personaje)
{
    char pokemon1[MAX_NOMBRE]; char pokemon2[MAX_NOMBRE];
    mostrar_pokemones(personaje);
    printf("\n                             Introduzca el nombre del pokemon que desea reemplazar de lugar: ");
    scanf("%s", pokemon1);
    printf("\n");
    printf("\n                             Introduzca el nombre del pokemon que reemplazará su lugar: ");
    scanf("%s", pokemon2);
    if (swap_pokemones(personaje->pokemon_obtenidos, pokemon1, pokemon2, personaje->c_pokemones) == EXITO) reacomodar_batalla(personaje);
    return;
}
/* tomar_pokemon(personaje_t* personaje, entrenador_t* entrenador) : Procedimiento que dado un entrenador y un personaje, se le pide
   qué pokémon desea el usuario de la lista del entrenador para añadir a su lista.
*/
void tomar_pokemon(personaje_t* personaje, entrenador_t* entrenador)
{
    mostrar_pokemones_entrenador(entrenador);
    char pokemon_nombre[MAX_NOMBRE];
    bool bandera = true;
    while (bandera)
    {
        printf("\n                               Introduzca el nombre del pokemon que desea tomar prestado: ");
        scanf("%s", pokemon_nombre);
        pokemon_t* pokemon = NULL; nodo_t* nodo_pokemon = NULL;
        nodo_t* nodo = entrenador->pokemones->nodo_inicio;
        for(int i = 0 ; i < entrenador->c_pokemones ; i++)
        {   
            pokemon = nodo->elemento;
            if (strcmp(pokemon->nombre, pokemon_nombre) == 0)
            {
                nodo_pokemon = nodo; 
                break;
            }
            if (nodo->siguiente) nodo = nodo->siguiente;
        }
        if ( nodo_pokemon )
        {   
            pokemon = nodo_pokemon->elemento;
            pokemon_t* pokemon_nuevo = crear_pokemon(pokemon->nombre, pokemon->velocidad, pokemon->ataque, pokemon->defensa);
            if (pokemon_nuevo)
            {   
                lista_insertar(personaje->pokemon_obtenidos, pokemon_nuevo);
                if (personaje->c_pokemones < MAX_PARTY) lista_insertar(personaje->pokemon_para_combatir, pokemon_nuevo);
                personaje->c_pokemones++;
            }
            bandera = false; 
            break;
        }
        else printf("\n                           No se encontró el pokémon deseado. Verifique el nombre ingresado.\n \n");
    }
    return;
    
}
/* personaje_t* leer_personaje(char linea[]) : Funcion que dada una linea de texto estructurada, crea un struct personaje y se devuelve
   un puntero a el.
*/
personaje_t* leer_personaje(char linea[])
{   
    char tipo, nombre[MAX_NOMBRE];
    int leidos = sscanf(linea, FORMATO_ENT, &tipo, nombre);
    if (leidos != 2) return NULL;
    personaje_t* personaje = crear_personaje();
    if (!personaje) return NULL;
    strcpy(personaje->nombre, nombre);
    return personaje;
}
/* personaje_t* leer_archivo_personaje(const char* nombre_archivo) : Funcion que dado un archivo de texto estructurado, se lee linea a linea
   almacenando su información en un struct personaje_t. Devuelve un puntero al struct, o NULL en caso de ERROR.
*/
personaje_t* leer_archivo_personaje(const char* nombre_archivo)
{   
    /*Funcion que recibe la ruta de un archivo de texto estructurado del cual lee
    linea a linea su información para introducirla a un struct arrecife_t. Devuelve 
    un puntero arrecife_t que contiene un vector de pokemones y la cantidad de pokemones 
    almacenados.  */
    personaje_t* personaje = NULL;
    bool bandera = true;
    FILE* archivo = fopen(nombre_archivo, "r");
    if (!archivo) return NULL;
    char linea[MAX_LINEA];
    while(fgets(linea, MAX_LINEA, (FILE*) archivo) && bandera)
    {    
        if (linea[0] == 'E')
        {
            if (personaje) return personaje;
            personaje = leer_personaje(linea);
            if (!personaje) bandera = false;
        }
        if (linea[0] == 'P')
        {
            if (leer_pokemon(linea, NULL, personaje) == ERROR) bandera = false;
        }
    }
    fclose(archivo);
    if (personaje->c_pokemones == 0)
    {
        liberar_personaje(personaje); 
        return NULL; 
    }
    return personaje;
}
