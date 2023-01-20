#include "main.h"

int main(int argv, char* argc[]){

    int tamTablero = 8;

    // Chequeamos la cantidad de argumentos
    if (! verificarCantidadArgumentos(argv))
        return 1;

    // Abrimos el archivo con el nombre pasado como argumentos
    FILE* archivoJuego = fopen(argc[1],"r");
    
    // Verificamos que dicho nombre corresponda a un archivo valido
    if (archivoJuego == NULL){
        printf("ERROR: El nombre pasado no corresponde a ningun archivo. Finalizando el programa...\n");
        return 1;
    }





    Jugador jugador1;
    Jugador jugador2;
    char colorInicio;

    // Leemos la informacion, verificamos que sea correcta, y la almacenamos
    if (! leerInformacionPreliminar(&jugador1,&jugador2,&colorInicio,archivoJuego))
        return 1; 


    // Si llegamos hasta aqui, la informacion preliminar era correcta.
    char turnoActual = colorInicio;

    // Inicializamos el tablero
    char tableroJuego[tamTablero][tamTablero];
    inicializarTablero(tableroJuego,tamTablero);

    // Aqui almacenaremos las jugadas que iremos leyendo
    char jugadaLeida[100];

    // Leemos la primer jugada
    char* verificadorLectura = fgets(jugadaLeida,100,archivoJuego);
    

    // Aca iremos almacenando las dos ultimas jugadas, para ver si se salteo el turno doble
    Casilla jugadasRealizadas[2] = {crearCasilla(0,0),crearCasilla(0,0)};
    
    int cantidadFichasColocadas = 4;     

    // Iremos guardando las fichas que las jugadas correctas voltearon
    Casilla* fichasVolteadas = NULL;  

    int cantidadVolteadas;


    while (! partidaTerminada(verificadorLectura,cantidadFichasColocadas,jugadasRealizadas) && 
             jugadaVerifica(jugadaLeida,turnoActual,tableroJuego,tamTablero,&fichasVolteadas,&cantidadVolteadas)){

        
        // Convertimos la jugada
        Casilla jugadaConvertida = convertirJugada(jugadaLeida,tamTablero);

        printf("JUGADA CONVERTIDA: (%d,%d)\n",jugadaConvertida.columna,jugadaConvertida.fila);

        // Agregamos la jugada a nuestro registro de jugadas
       agregarJugada(jugadaConvertida,jugadasRealizadas);
        

        // Vemos si no se salteo el turno
        if (jugadaConvertida.columna != -1 && jugadaConvertida.fila != -1){

            voltearFichas(jugadaConvertida,fichasVolteadas,cantidadVolteadas,turnoActual,tableroJuego,tamTablero);
            
            cantidadFichasColocadas++;
        }

        // Cambiamos el turno
        turnoActual = cambiarTurno(turnoActual);

        // Leemos la nueva jugada
        verificadorLectura = fgets(jugadaLeida,100,archivoJuego);

        mostrarTablero(tableroJuego,tamTablero);

    }
    printf("fin ciclo\n");
    
    // Cerramos el archivo
    fclose(archivoJuego);

    // Mostramos el mensaje final
    mensajeFinalJuego(jugadaLeida,tableroJuego,tamTablero,verificadorLectura,jugadasRealizadas);

    mostrarTablero(tableroJuego,tamTablero);



    if (cantidadFichasColocadas != 64 && verificadorLectura == NULL) {
        printf("Generando archivo de juego...\n");
        // Generamos el archivo

    }
    // En caso de que la partida haya terminado totalmente, no generamos archivo.
    // En caso de que haya error, no generamos archivo.
    // En caso de que la partida haya terminado a medias, generamos un archivo.






    // Liberamos la memoria pedida dinamicamente
    free(jugador1.nombreJugador);
    free(jugador2.nombreJugador);
    
    if (fichasVolteadas != NULL)
        free(fichasVolteadas);


    return 0;
}