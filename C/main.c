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


    // Si llegamos hasta aqui, la informacion preliminar era correcta,
    // por lo que podemos empezar con la partida.
    char turnoActual = colorInicio;

    // Inicializamos el tablero: Utilizaremos un array bidimensional
    char tableroJuego[tamTablero][tamTablero];
    inicializarTablero(tableroJuego,tamTablero);


    // Mostramos el tablero por primera vez
    mostrarTablero(tableroJuego,tamTablero);

    // Aqui almacenaremos las jugadas que iremos leyendo
    char jugadaLeida[100];

    // Leemos la primer jugada
    fgets(jugadaLeida,100,archivoJuego);
    

    // Aca iremos almacenando las dos ultimas jugadas, para ver si se salteo el turno doble
    Casilla jugadasRealizadas[2] = {crearCasilla(0,0),crearCasilla(0,0)};
    
    int cantidadFichasColocadas = 4;     

    // Iremos guardando las fichas que las jugadas correctas voltean
    Casilla* fichasVolteadas = NULL;  

    int cantidadVolteadas;

    
    while (! partidaTerminada(jugadaLeida,cantidadFichasColocadas,jugadasRealizadas) &&
             jugadaVerifica(jugadaLeida,turnoActual,tableroJuego,tamTablero,&fichasVolteadas,&cantidadVolteadas)){

        // Convertimos la jugada
        Casilla jugadaConvertida = convertirJugada(jugadaLeida,tamTablero);

        // Agregamos la jugada a nuestro registro de jugadas
       agregarJugada(jugadaConvertida,jugadasRealizadas);
        

        // Vemos si no se salteo el turno
        if (jugadaConvertida.columna != -1 && jugadaConvertida.fila != -1){

            
            voltearFichas(jugadaConvertida,fichasVolteadas,cantidadVolteadas,turnoActual,tableroJuego,tamTablero);
            
            cantidadFichasColocadas++;
        }

        mostrarTablero(tableroJuego,tamTablero);

        // Cambiamos el turno
        turnoActual = cambiarTurno(turnoActual);

        // Leemos la nueva jugada
        fgets(jugadaLeida,100,archivoJuego);
    }

    
    
    // Cerramos el archivo
    fclose(archivoJuego);


    // Mostramos el mensaje final


    // Generamos el archivo para que lo tome el programa de Python
    // En caso de que la partida haya terminado totalmente, no generamos archivo.
    // En caso de que la partida haya terminado a medias, generamos un archivo
    // en donde se muestre el Tablero Final y el Turno Actual.






    // Liberar nombres de jugadores
    free(jugador1.nombreJugador);
    free(jugador2.nombreJugador);
    

    // Liberamos las fichas volteadas si no pudo ser liberado con anterioridad
    if (fichasVolteadas != NULL)
        free(fichasVolteadas);


    // Verificar que todo funciona con Valgrind

    return 0;
}