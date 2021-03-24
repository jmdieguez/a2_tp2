#include "aventura.h"
#ifdef _WIN32
#include <windows.h>
	
#elif __linux__
#include <unistd.h>
#endif

void pausar(int segundos)
{
    #ifdef _WIN32
    Sleep(segundos*1000);

	#elif __linux__
    sleep((unsigned int)segundos);
    #endif
}

void print_fin()
{   
    printf("\e[1;1H\e[2J");
    printf("\n");
    printf("                            .´-,.__ \n");
    printf("                                             `.     `.  , \n");
    printf("                                          .--'  .._,''-' `. \n");
    printf("                                         .    .         `' \n");
    printf("                                         `.   /          ,' \n");
    printf("                                           `  '--.   ,-'' \n");
    printf("                                            `'`   |  \\ \n");
    printf("                                               -. \\, | \n");
    printf("                                                `--Y.'      ___. \n");
    printf("                                                     \\     L._, \\ \n");
    printf("                                           _.,        `.   <  <\\                _ \n");
    printf("                                         ,' '           `, `.   | \\            ( ` \n");
    printf("                                      ../, `.            `  |    .\\`.           \\ \\_ \n");
    printf("                                     ,' ,..  .           _.,'    ||\\l            )  ''. \n");
    printf("                                    , ,'   \\           ,'.-.`-._,'  |           .  _._`. \n");
    printf("                                  ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\ \n");
    printf("                                .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`. \n");
    printf("                                |  '          ..         `-...-'  |  `-'      / /        . `. \n");
    printf("                                | /           |L__           |    |          / /          `. `. \n");
    printf("                               , /            .   .          |    |         / /             ` ` \n");
    printf("                              / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\ \n");
    printf("                             / .           \'`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`. \n");
    printf("                            .  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\ \n");
    printf("                            ' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L` \n");
    printf("                            |'      _.-''''` `.    \\ _,'  `            \\ `.___`.''`-.  , |   |    | \\ \n");
    printf("                            ||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .| \n");
    printf("                            ||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   || \n");
    printf("                            || '              V      / /           `   | `   ,'   ,' '.    !  `. || \n");
    printf("                            ||/            _,-------7 '              . |  `-'    l         /    `|| \n");
    printf("                            . |          ,' .-   ,' ||               | .-.        `.      .'     || \n");
    printf("                             `'        ,'    `''.'    |               |    `.        '. -.'       `' \n");
    printf("                                      /      ,'      |               |,'    \\-.._,.'/' \n");
    printf("                                      .     /        .               .       \\    .'' \n");
    printf("                                    .`.    |         `.             /         :_,'.' \n");
    printf("                                      \\ `...\\   _     ,'-.        .'         /_.-' \n");
    printf("                                       `-.__ `,  `'   .  _.>----''.  _  __  / \n");
    printf("                                            .'        /'''          |  '''   '_ \n");
    printf("                                           /_|.-'\\ ,''.             '.'`__'-( \\ \n");
    printf("                                             / ,'''''\\,'               `/  `-.|'' \n");
    printf("\n");
    printf("                           Ya no te quedan medallas por conseguir: Has completado la Aventura Pokémon!\n");
}

void print_pokemon()
{   
    printf("\e[1;1H\e[2J");
    printf("                                                    ────────▄███████████▄────────\n");
    printf("                                                    ─────▄███▓▓▓▓▓▓▓▓▓▓▓███▄─────\n");
    printf("                                                    ────███▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓███────\n");
    printf("                                                    ──██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██──\n");
    printf("                                                    ─██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██─\n");
    printf("                                                    ██▓▓▓▓▓▓▓▓▓███████▓▓▓▓▓▓▓▓▓██\n");
    printf("                                                    ██▓▓▓▓▓▓▓▓██░░░░░██▓▓▓▓▓▓▓▓██\n");
    printf("                                                    ██▓▓▓▓▓▓▓██░░███░░██▓▓▓▓▓▓▓██\n");
    printf("                                                    ███████████░░███░░███████████\n");
    printf("                                                    ██░░░░░░░██░░███░░██░░░░░░░██\n");
    printf("                                                    ██░░░░░░░░██░░░░░██░░░░░░░░██\n");
    printf("                                                    ██░░░░░░░░░███████░░░░░░░░░██\n");
    printf("                                                    ─██░░░░░░░░░░░░░░░░░░░░░░░██─\n");
    printf("                                                    ──██░░░░░░░░░░░░░░░░░░░░░██──\n");
    printf("                                                    ───██░░░░░░░░░░░░░░░░░░░██───\n");
    printf("                                                    ────███░░░░░░░░░░░░░░░███────\n");
    printf("                                                    ─────▀███░░░░░░░░░░░███▀─────\n");
    printf("                                                    ────────▀███████████▀────────\n");
    printf("\n");
    printf(" __________    _______________   _____________  ________________       _____________________ ________________  ______________   __\n");
    printf(" ___    |_ |  / /__  ____/__  | / /__  __/_  / / /__  __ \\__    |      ___  __ \\_  __ \\__  //_/__  ____/__   |/  /_  __ \\__  | / /\n");
    printf(" __  /| |_ | / /__  __/  __   |/ /__  /  _  / / /__  /_/ /_  /| |      __  /_/ /  / / /_  ,<  __  __/  __  /|_/ /_  / / /_   |/ / \n");
    printf(" _  ___ |_ |/ / _  /___  _  /|  / _  /   / /_/ / _  _, _/_  ___ |      _  ____// /_/ /_  /| | _  /___  _  /  / / / /_/ /_  /|  /  \n");
    printf(" /_/  |_|____/  /_____/  /_/ |_/  /_/    \\____/  /_/ |_| /_/  |_|      /_/     \\____/ /_/ |_| /_____/  /_/  /_/  \\____/ /_/ |_/   \n");
    printf("\n");

}

void print_batalla(char jugador[], char entrenador[])
{
    printf("                                                    Batalla Pokémon!\n");
    printf("\n");
    printf("%70s \n", entrenador);
    printf("\n");
    printf("                                                 (N) Proxima Batalla\n");
    printf("\n");
    printf("                                           Elija una opcion para continuar\n");
    printf("\n                                                            ");
    return;
}

void print_menu_gimnasio(char nombre[])
{
    printf("                                                Actualmente está en el gimnasio:\n");
    printf("%78s \n", nombre);
    printf("\n");
    printf("   (E) Mostrar entrenador y pokemones  (G) Informacion gimnasio actual  (C) Cambiar Pokémones de batalla.  (B) Sig. Batalla\n");
    printf("\n");
    printf("                                                Elija una opcion para continuar\n");
    printf("\n");
    printf("                                                            ");
}

void print_menu_inicio()
{
    printf("    (E) Ingresar archivo de personaje principal (A) Agregar gimnasio (I) Comenzar partida (S) Simular partida (T) Salir\n");
    printf("\n");
    printf("                                               Elija una opcion para continuar\n");
    printf("\n                                                            ");
    return;
}

void print_victoria(bool tomado)
{   
    printf("                                     __      ___      _             _         _           ___ \n");
    printf("                                     \\ \\    / (_)    | |           (_)       | |      _  |_  |\n");
    printf("                                      \\ \\  / / _  ___| |_ ___  _ __ _  __ _  | |     (_)   | |\n");
    printf("                                       \\ \\/ / | |/ __| __/ _ \\| '__| |/ _` | | |           | |\n");
    printf("                                        \\  /  | | (__| || (_) | |  | | (_| | |_|      _    | |\n");
    printf("                                         \\/   |_|\\___|\\__\\___/|_|  |_|\\__,_| (_)     (_)  _| |]\n");
    printf("                                                                                         |___|]\n");
    printf("\n");
    if (tomado == false)
    printf("                       (T) Tomar un pokémon del rival     (C) Cambiar pokémones    (N) Próximo gimnasio\n");
    else
    printf("                                        (C) Cambiar pokémones    (N) Próximo gimnasio\n");
    printf("\n");
    printf("                                               Elija una opcion para continuar\n");
    printf("\n                                                            ");
    return;
}

void print_derrota(bool simulacion)
{   
    printf("                                      _____                      _          _           ___ \n");
    printf("                                     |  __ \\                    | |        | |      _  |  _|\n");
    printf("                                     | |  | | ___ _ __ _ __ ___ | |_ __ _  | |     (_) | |  \n");
    printf("                                     | |  | |/ _ \\ '__| '__/ _ \\| __/ _` | | |         | |  \n");
    printf("                                     | |__| |  __/ |  | | | (_) | || (_| | |_|      _  | |  \n");
    printf("                                     |_____/ \\___|_|  |_|  \\___/ \\__\\__,_| (_)     (_) | |_ \n");
    printf("                                                                                       |___|\n");
    printf("\n");
    if (!simulacion)
    {
        printf("                          (R) Reintentar gimnasio     (C) Cambiar pokémones    (F) Finalizar partida\n");
        printf("\n");
        printf("                                               Elija una opcion para continuar\n");
        printf("\n                                                            ");
    }
    return;
}

void menu_victoria(personaje_t* personaje, entrenador_t* entrenador)
{   
    char opcion;
    bool bandera = true;
    bool tomado = false;
    while (bandera == true)
    {   
        print_pokemon();
        print_victoria(tomado);

        scanf("%c", &opcion);
        if ( (opcion == 'T' || opcion == 't') && tomado == false)
        {
            tomar_pokemon(personaje, entrenador);
            tomado = true;
        }
        if (opcion == 'C' || opcion == 'c') cambiar_pokemones(personaje);
        if (opcion == 'N' || opcion == 'n') bandera = false;
    }
    return;
}

bool menu_derrota(personaje_t* personaje, entrenador_t* entrenador)
{   
    char opcion;
    bool bandera = true;
    bool seguir = true;
    while (bandera == true)
    {   
        print_pokemon();
        print_derrota(false);
        scanf("%c", &opcion);
        if (opcion == 'R' || opcion == 'r') 
        {
            printf("                                   Reintentando gimnasio a partir del último entrenador \n");
            bandera = false;
        }
        if (opcion == 'C' || opcion == 'c') cambiar_pokemones(personaje);
        if (opcion == 'F' || opcion == 'f')
        {   
            seguir = false;
            bandera = false;
        }
    }
    return seguir;
}

int menu_batalla(personaje_t* personaje, entrenador_t* entrenador, gimnasio_t* gimnasio, size_t id_p)
{   
    char opcion;
    bool bandera = true;
    int resultado;
    while (bandera == true)
    {   
        print_pokemon();
        print_batalla(personaje->nombre, entrenador->nombre);
        scanf("%c", &opcion);

        if (opcion == 'N' || opcion == 'n')
        {
            resultado = batallar(personaje->pokemon_para_combatir, entrenador->pokemones, id_p, false);
            if (resultado ==  G_PRIMERO)
            {   
                if (entrenador->lider == false)
                {
                    liberar_entrenador(entrenador); lista_desapilar(gimnasio->entrenadores); gimnasio->c_entrenadores--;
                    entrenador = lista_tope(gimnasio->entrenadores);
                }
                else
                {
                    menu_victoria(personaje, entrenador);
                    gimnasio_completado(gimnasio);
                    pausar(5);
                    bandera = false;
                }
            }
            else if (resultado ==  G_SEGUNDO) bandera = menu_derrota(personaje, entrenador);
            if (bandera == false) return resultado;
        }
    }
    return resultado;
}

// Simulacion de partida. Devuelve si perdio o no.
bool simular(personaje_t* personaje, gimnasio_t* gimnasio)
{
    bool bandera = true;
    int resultado;
    entrenador_t* entrenador = lista_tope(gimnasio->entrenadores);
    while (bandera == true)
    {   
        resultado = batallar(personaje->pokemon_para_combatir, entrenador->pokemones, gimnasio->id_puntero, true);
        if (resultado ==  G_PRIMERO)
        {   
            if (entrenador->lider == false)
            {
                liberar_entrenador(entrenador); lista_desapilar(gimnasio->entrenadores); gimnasio->c_entrenadores--;
                entrenador = lista_tope(gimnasio->entrenadores);
            }
            else
            {
                gimnasio_completado(gimnasio);
                pausar(2);
                bandera = false;
            }
        }
        else if (resultado ==  G_SEGUNDO)
        {
            print_pokemon();
            print_derrota(true);
            pausar(2);
            bandera = false;
        }
    }
    return (resultado ==  G_PRIMERO);
}

// Jugar partida. Devuelve si sigue jugando o no.
bool jugar(personaje_t* personaje, gimnasio_t* gimnasio)
{   
    char opcion;
    bool bandera = true;
    bool seguir = true;
    while (bandera && gimnasio)
    {   
        print_pokemon();
        print_menu_gimnasio(gimnasio->nombre);
        scanf("%c", &opcion);
        if (opcion == 'E' || opcion == 'e')
        {   printf("\n");
            mostrar_pokemones(personaje);
            pausar(10);
        }
        if (opcion == 'G' || opcion == 'g')
        {   informacion_gimnasio(gimnasio);
            pausar(5);
        }
        if (opcion == 'C' || opcion == 'c') cambiar_pokemones(personaje);
        if (opcion == 'B' || opcion == 'b')
        {
            int resultado = menu_batalla(personaje, lista_tope(gimnasio->entrenadores), gimnasio, gimnasio->id_puntero);
            if (resultado == G_SEGUNDO) seguir = false;
            bandera = false;
        }
    }
    return seguir;
}

bool menu_gimnasio(personaje_t* personaje, heap_t* gimnasios, bool simulacion)
{   
    bool seguir;
    gimnasio_t* gimnasio = heap_extraer_raiz(gimnasios);
    if (!simulacion) seguir = jugar(personaje, gimnasio);
    if ( simulacion) seguir = simular(personaje, gimnasio);
    return seguir;
}

// Ciclo de juego
void juego(personaje_t* personaje, heap_t* gimnasios, bool simulacion)
{   
    bool seguir = true;
    if (!personaje || !gimnasios || gimnasios->tope == 0)
    {   
        printf("\n");
        printf("                                  Informacion insuficiente para arrancar a jugar. \n");
        pausar(5);
    }
    else
    {   
        while (seguir)
        {
            if (gimnasios->tope == 0)
            {   print_fin();
                pausar(10);
                return;
            }
            seguir = menu_gimnasio(personaje, gimnasios, simulacion);
        }
    }
    return;
}

int main()
{   
    char opcion;
    char* archivo = malloc(MAX_ARCHIVO + 1);
    bool bandera = true;
    heap_t* gimnasios = NULL;
    personaje_t* personaje = NULL;
    while (bandera)
    {   
        print_pokemon();
        print_menu_inicio();
        scanf("%c", &opcion);

        if (opcion == 'E' || opcion == 'e')
        {   
            printf( "\n                       Introduzca el nombre del archivo del personaje (incluya extensión): ");
            scanf("%s", archivo);
            personaje = leer_archivo_personaje(archivo);
        }
        if (opcion == 'A' || opcion == 'a')
        {   
            if (!gimnasios) gimnasios = crear_heap(comparar_gimnasios);
            printf( "\n                       Introduzca el nombre del archivo del gimnasio (incluya extensión): ");
            scanf("%s", archivo);
            leer_archivo_gimnasio(gimnasios, archivo);
        }
        if (opcion == 'I' || opcion == 'i' || opcion == 'S' || opcion == 's')
        {   
            if (opcion == 'I' || opcion == 'i') juego(personaje, gimnasios, false);
            if (opcion == 'S' || opcion == 's') juego(personaje, gimnasios, true);
            if (personaje) liberar_personaje(personaje);
            personaje = NULL;
            if (gimnasios) liberar_heap_gimnasios(gimnasios);
            gimnasios = NULL;
        }
        if (opcion == 'T' || opcion == 't') bandera = false;
        printf("\n");
    }
    liberar_heap_gimnasios(gimnasios);
    free(archivo);
    return EXITO;
}