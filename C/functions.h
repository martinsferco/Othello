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
    leer informacionPreliminar se encarga de tomar el archivo de juego
    y almacenar en todas las variables a las cuales referencian los punteros
    los valores que son tomados del archivo.
    */
    void leerInformacionPreliminar(FILE* archivoJuego,char* nombre1, char* nombre2, char* color1, char* color2, char* colorInicio);

    int verificarInformacionPreliminar(char* nombre1);

    


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