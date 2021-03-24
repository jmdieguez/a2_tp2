                TP-2 / ALGORITMOS 2 / CÁTEDRA MÉNDEZ / 2020 2C

                              /  Introducción  /

El programa presentado se trata de un juego basado en la Aventura Pokémon, donde un entrenador debe recorrer los distintos gimnasios
de una región, venciéndo a todos los entrenadores que se le crucen. 
Se inicia desde un menu de inicio en el main, en el que al usuario se le permite cargar un archivo de texto estructurado (con formado
pre-designado) con los datos de el personaje principal, o de un nuevo gimnasio para incorporar. Adicionalmente, una opción para arrancar
a jugar (una vez cargados los datos anteriores), otra opción para simular la partida, y finalmente terminar el programa.

* Si se elige arrancar a jugar, el programa cargará el personaje y el o los gimnasios que haya cargado el usuario en el heap, y mientras 
  el jugador no pierda (y quiera dejar de jugar) y queden gimnasios disponibles, se abrirá un menú del gimnasio actual en el cual podrá:
  - Consultar los pokémones obtenidos por el personaje.
  - Consultar la información del gimnasio actual. 
  - Cambiar de orden los pokémones obtenidos.
  - Arrancar su próxima batalla.

  Una vez que se entra a batallar, el personaje tiene un duelo con el entrenador tope entre la pila de entrenadores. Si éste gana la batalla
  pokémon, es decir, vence a todos sus pokémones, el entrenador se desapila y se continúa con el siguiente entrenador, si es que hay. En ese
  caso, se considera que el gimnasio es completado (ya que el primer entrenador es el Lider) y se permite tomar un pokémon a elección del rival.
  Acto seguido, se elimina completamente el gimnasio y se gana su medalla. Caso contrario, es decir, el personaje pierde, se abre un menú
  para consultarle si quiere seguir jugando, entre otras opciones.

* Si se elige simular la partida, se tomará el mismo procedimiento que se detalló anteriormente, con la diferencia que el usuario no puede
  tomar acciones, simplemente según sus datos cargados, tratar de ganar todas las batallas posibles.

Una vez terminada la partida, se vacía la memoria correspondiente al personaje y a los gimnasios, asi no hay pérdidas de memoria en caso
de que el usuario quiera jugar otra partida y cargar nuevos datos. 

------------------------------------------------------------------------------------------------------------------------------------------------
El programa se dividirá en distintas librerías para facilitar el
ordenado y clasificación de las funciones que requiere.

Heap: En "heap.c" se encuentra una implementación de un TDA Heap que nos ayudará a almacenar y ordenar minimalmente los 
distintos gimnasios según su dificultad.

Lista: En "lista.c" se tratan una implementación de un TDA Lista Enlazada + TDA Pila + TDA Cola que se usará para almacenar 
linealmente los pokémones de los distintos entrenadores, además de los entrenadores en sí. Para los pokémones se usará Lista (ya que
es necesario acceder a todos los pokémones fácilmente), mientras que para los entrenadores se usará Pila (ya que nos interesa trabajar
con el último entrenador de la pila, es decir, el tope).

Batallas: "En batallas.c" se ven las funciones destinadas a la interacción entre los pokémones de los entrenadores.
Principalmente se destina a la comparación de stats entre pokémones para descubrir cuál merece ser vencedor.

Gimnasio: "En gimnasio.c" se encuentran las funciones que corresponden al tratado de gimnasios, entrenadores, y pokemones.

Personaje: "En personaje.c" se hallan las funciones que tratan con el personaje principal. Se reciclan funciones de la librería Gimnasio.

Main: Programa principal.

Adicionalmente se proporcionan 4 archivos de textos que contienen gimnasios y 1 archivo de texto que contiene un personaje.
------------------------------------------------------------------------------------------------------------------------------------------------
                            / Compilacion  /

Para compilar el programa se deberá acceder a la carpeta del programa dentro de la terminal con ayuda del comando cd, el cual nos
permite desplazarnos en los ficheros del equipo.

Una vez en la carpeta, hay que correr la siguiente línea en la terminal:

gcc *.c -o juego

Esto nos permitirá compilar el programa y crearnos un ejecutable llamado “juego”

Para ejecutar el programa hay que correr la siguiente línea (puede variar según el sistema operativo):

./juego
------------------------------------------------------------------------------------------------------------------------------------------------
                           / Aclaraciones del autor /

Los bloques de código se identarán de la siguiente manera:        Mientras que los bloques de código de una línea: 

funcion()                                                                   funcion() accion;
{
  accion1;         
  accion2;
}

* Salvo las declaraciones de las funciones en sí.
------------------------------------------------------------------------------------------ 
                     
                          Manuel Dieguez –  106146
