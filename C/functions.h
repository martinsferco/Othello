#ifndef FUNCTIONS_H

    #define FUNCTIONS_H

    // Librerias requeridas
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    // ESTRUCTURAS UTILIZADAS

    typedef struct {

        int columna; 
        int fila;

    } Casilla;

    typedef struct {

        char* nombreJugador;
        char colorJugador;

    } Jugador;



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
    verificarInformacionPreliminard
    */
    




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

#endif