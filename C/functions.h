#ifndef FUNCTIONS_H

    #define FUNCTIONS_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    // Estructuras utilizadas

    typedef struct {

        int columna; 
        int fila;

    } Casilla;


    typedef struct {

        int x;
        int y;

    } VectorDireccion;


    typedef struct {

        char* nombreJugador;
        char colorJugador;

    } Jugador;

    // Prototipos de funciones en functions.c

    /*
    crearCasilla toma dos enteros y nos devuelve una estructura
    de tipo casilla con sus dos campos inicializados con los valores
    pasados.
    */    
    Casilla crearCasilla(int columna, int fila);

    /*
    crearVector toma dos enteros y nos devuelve una estructura
    de tipo VectorDireccion con sus dos campos inicializados con los valores
    pasados.
    VectorDireccion crearVector(int x, int y);

    /*
    vertificarCantidadArgumentos toma la cantidad de argumentos
    pasados al programa y verifica que sean la cantidad correcta.
    */
    int verificarCantidadArgumentos(int cantidadArgumentos);

    /*
    leerInformacionPreliminar se encarga de tomar la informacion del
    archivo y verificarla. En caso de que la informacion sea correcta,
    almacena dicha informacion en las variables que referencian los
    punteros pasados.
    Si consigue pasar la informacion a las variables, devuelve 1.
    Si no consigue hacerlo, devuelve 0.
    */
    int leerInformacionPreliminar(Jugador* jugador1, Jugador* jugador2, char* colorInicio, FILE* archivoJuego);

    /*
    verificarInformacionPreliminar toma el color de los jugadores y el 
    color de inicio leido del archivo y nos determina si todos estos
    valores se encuentren dentro de las opciones correctas.
    */
   int verificarInformacionPreliminar(char* color1, char* color2, char* colorI);

    /*
    verificarColor toma un color y verifica que se encuentre dentro de
    las opciones correctas. En caso de verificar devuelve 1, y en caso
    contrario devuelve 0.
    */
    int verificarColor(char* colorJugador);
    
    /*
    coloresJugadoresDistintos toma los dos colores de los jugadores y 
    determina si estos son distintos. En caso de serlo devuelve 1, si no
    devuelve 0.
    */
    int coloresDistintos(char* color1, char* color2);


    /*
    partidaTerminada toma el verificadorLectura del archivo, la cantidad
    de fichas colocaas y las jugadas realizadas, y nos determina si la partida
    ya termino, o si se puede seguir jugando. Va a verificar que:
    - No hayamos llegado al final del archivo.
    - No hayamos colocado todas las fichas.
    - No se haya salteado dos veces el turno de manera consecutiva.

    Si la partida no termino devuelve 1, si no 0.
    */
    int partidaTerminada(char* verificadorLectura, int cantidadFichas, Casilla* jugadasRealizadas);

    /*
    agregarJugada toma la jugada agregada y las jugadas realizadas, y 
    la agrega como la ultima jugada hecha.
    */
    void agregarJugada(Casilla jugadaAgregada, Casilla* jugadasRealizadas);

    /*
    voltearFichas toma la jugada que se realizo, las fichas volteadas por dicha
    jugada y cuantas son, el turno actual, el tablero y su tamanio, y se encarga
    de modificar el tablero en base a la jugada y sus fichas volteadas para dicho
    turno.
    */
    void voltearFichas(Casilla jugada, Casilla* fichasVolteadas, int cantidadVolteadas ,char turnoActual, char tableroJuego[][8], int tamTablero);

    /*
    dobleSaltoTurno toma las jugadas y determina si se hizo un doble salto de turno.
    En el caso de que eso ocurra devuelve 1, en caso contrario devuelve 0.
    */
    int dobleSaltoTurno(Casilla* jugadasRealizadas);

    /*
    jugadaVerifica toma la jugada que se leyo, el turno actual y el tablero y nos
    determina si la jugada leida es una jugada correcta. En caso de serlo retorna 1
    y en caso contrario devuelve 0.
    */
    int jugadaVerifica(char* jugada, char turnoActual, char tableroJuego[][8], int tamTablero, Casilla** registroVolteadas, int* cantidadVolteadas);

    /*
    almacenarInformacionVolteadas toma el registroVolteadas, y tambien toma las fichas
    que fueron volteadas por la jugada y su cantidad. Luego, dependiendo de si ya se
    le habia asignado una direccion de memoria al registro o no, libera o no la memoria
    y le asigna un nuevo espacio para guardad las nuevas fichasVolteadas.
    */
    void almacenarInformacionVolteadas(Casilla** registroVolteadas, int cantidadVolteadas, Casilla* fichasVolteadas);

    /*
    existenJugadasPosibles toma el turno actual, el tablero de juego y su tamanio, y 
    se encarga de recorrer dicho tablero para determinar si existen jugadas posibles.
    */
    int existenJugadasPosibles(char turnoActual, char tableroJuego[][8], int tamTablero);

    /*
    mensajeGanador toma la cantidad de fichas de ambos colores, y muestra un mensaje
    por consola en donde quien gano, o si hubo un empate.
    */
    void mensajeGanador(int cantidadBlancas, int cantidadNegras);

    /*
    verificarFormato toma la jugada realizada y nos determina si cumple con el formato
    estipulado. En caso de serlo devuelve 1 en caso contrario devuelve 0.
    */
    int verificarFormato(char* jugada);

    /*
    verificarLargo se encarga de tomar la jugada y determinar si cumple con el largo
    que debe tener. En caso de serlo devuelve 1, en caso contrario devuelve 0.
    */
    int verificarLargo(char* jugada);

    /*
    verificarRango toma la jugada realizada, y el tamanio del tablero, nos determina
    si la jugada se encuentra dentro del rango del tablero.
    */
    int verificarRango(char* jugada,int tamTablero);

    /*
    buscarArray toma un objetivo a encontrar, un array y el tamanio de dicho array,
    nos determina si dicho obetivo es un elemento del array. En caso de serlo devuelve 1,
    si no 0.
    */
    int buscarArray(char objetivo, char* arrayValores, int tamTablero);

    /*
    convertirJugada toma la jugada realizada y el tamanio del tablero, y nos devuelve
    la conversion de la jugada con la que trabajaremos en el programa, que es de tipo
    Casilla.
    */
    Casilla convertirJugada(char* jugada,int tamTablero);

    /*
    ocupada toma la jugada realizada y el tablero de juego, y nos determina si dicha
    casilla se encuentra ocupada. En caso de estarlo devuelve 1, si no 0. 
    */
    int ocupada(Casilla jugada, char tableroJuego[][8]);

    /*
    fichasVolteadaJugada toma la jugada realizada, el turno actual, el tablero de
    juego y su tamanio. Si luego de analizar todas las direcciones y sentidos, 
    se encontro que la jugada realiza volteos, pide memoria dinamicamente para 
    almacenar todas las coordenadas de las fichas que fueron volteadas, y almacena
    dicha direccion en el registroVolteadas.
    */
    int fichasVolteadasJugada(Casilla jugada, char turnoActual, char tableroJuego[][8], int tamTablero, Casilla** registroVolteadas);

    /*
    enRango toma las coordenadas de la casilla, el sentido y la direccion en donde
    nos estamos moviendo, y el tamanio del tablero, y nos determina si la casilla
    que estamos analizando se encuentra dentro del rango para que podamos encontrar
    una ficha que encierre a todas las demas. En caso de que se encuentre en rango, 
    devuelve 1, si no 0.
    */
    int enRango(int x, int y, int sentido, VectorDireccion direccion, int tamTablero);

    /*
    copiarCasillas toma el destino de guardado, a partir de donde vamos a guardar,
    el origen de copiado y la cantidad elementos a copiar, y se encarga de realizar
    la copia de datos. 
    */
    void copiarCasillas(Casilla* destino, int inicio, Casilla* origen, int cantidad);

    /*
    cambiarTurno toma el color del turno actual y se encarga de devolvernos
    el color del turno opuesto. Es decir:
    - Si recibe 'B' devuelve 'N'
    - Si recibe 'N' devuelve 'B'
    */
    char cambiarTurno(char turnoActual);

    /*
    inicializarTablero toma un tablero de juego y su tamanio y se encarga
    de inicializarlo para poder comenzar a jugar.
    */
    void inicializarTablero(char tableroJuego[][8],int tamTablero);

    /*
    mostrarTablero toma el tablero de juego actual y su tamanio y se encarga
    de mostrarlo por consola.
    */
    void mostrarTablero(char tableroJuego[][8], int tamTablero);

    /*
    mensajeFinalJuego toma la jugada final, el tablero de juego y su tamanio,
    el verificador de lectura del archivo y las jugadas realizada. En base a eso,
    nos muestra por consola un mensaje adecuado de como termino la partida y quien
    es el ganador.
    */
    void mensajeFinalJuego(char* jugadaFinal,char tableroJuego[][8],int tamTablero,char* verificadorLectura, Casilla* jugadasRealizadas );  

    /*
    contarFichas toma el tablero de juego y su tamanio, y luego de contar la 
    cantidad de fichas blancas y negras que hay en el tablero, guarda en las
    variables referenciadas por los punteros pasados, dichos valores. 
    */
    void contarFichas(int* cantidadFichasNegras, int* cantidadFichasBlancas, char tableroJuego[][8],int tamTablero);


#endif
