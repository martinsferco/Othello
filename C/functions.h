#ifndef FUNCTIONS_H

    #define FUNCTIONS_H

    // Librerias requeridas
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    // ESTRUCTURAS UTILIZADAS

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

    Casilla crearCasilla(int columna, int fila);



    VectorDireccion crearVector(int x, int y);





    // Prototipos de funciones de functions.c

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
    partidaTerminada se 
    */
    int partidaTerminada(char* verificadorLectura, int cantidadFichas, Casilla* jugadasRealizadas);




    void agregarJugada(Casilla jugadaAgregada, Casilla* jugadasRealizadas);


    void voltearFichas(Casilla jugada, Casilla* fichasVolteadas, int cantidadVolteadas ,char turnoActual, char tableroJuego[][8], int tamTablero);


    /*
    dobleSaltoTurno toma las jugadas realizadas y determina si las dos ultimas
    jugadas fueron un salto de turno. En el caso de que eso ocurra devuelve 1,
    en caso contrario devuelve 0.
    */

    int dobleSaltoTurno(Casilla* jugadasRealizadas);


    /*
    jugadaVerifica toma la jugada que se leyo, el turno actual y el tablero y nos
    determina si la jugada leida es una jugada correcta. En caso de serlo retorna 1
    y en caso contrario devuelve 0.
    */
    int jugadaVerifica(char* jugada, char turnoActual, char tableroJuego[][8], int tamTablero, Casilla** registroVolteadas, int* cantidadVolteadas);


    void almacenarInformacionVolteadas(Casilla** registroVolteadas, int cantidadVolteadas, Casilla* fichasVolteadas);



    /*
    existenJugadasPosibles
    */
    int existenJugadasPosibles(char turnoActual, char tableroJuego[][8], int tamTablero);

    void mensajeGanador(int cantidadBlancas, int cantidadNegras);


    /*
    verificarFormato    
    */
    int verificarFormato(char* jugada);


    int verificarLargo(char* jugada);


    /*
    verificarRango
    */
    int verificarRango(char* jugada,int tamTablero);

    /*
    buscarArray
    */
    int buscarArray(char objetivo, char* arrayValores, int tamTablero);


    Casilla convertirJugada(char* jugada,int tamTablero);

    int ocupada(Casilla jugada, char tableroJuego[][8]);

    int fichasVolteadasJugada(Casilla jugada, char turnoActual, char tableroJuego[][8], int tamTablero, Casilla** registroVolteadas);


    int enRango(int x, int y, int sentido, VectorDireccion direccion, int tamTablero);


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


   void mensajeFinalJuego(char* jugadaFinal,char tableroJuego[][8],int tamTablero,char* verificadorLectura, Casilla* jugadasRealizadas );

   void contarFichas(int* cantidadFichasNegras, int* cantidadFichasBlancas, char tableroJuego[][8],int tamTablero);



#endif
