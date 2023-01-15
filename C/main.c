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

    // Tomamos la primer jugada
    char jugadaLeida[100]; // Aqui almacenaremos las jugadas que iremos leyendo

    fgets(jugadaLeida,100,archivoJuego);
    

    Casilla* jugadasRealizadas[60] = {NULL};
    
    int cantidadFichas = 4;     

    Casilla* fichasVolteadas = NULL; // Lo iremos modificando 

    
    while (! partidaTerminada(jugadaLeida,cantidadFichas,jugadasRealizadas) &&
             jugadaVerifica(jugadaLeida,turnoActual,tableroJuego,tamTablero,fichasVolteadas)){

            
        
        

        // Cambiamos el turno
        turnoActual = cambiarTurno(turnoActual);

        // Agregamos la jugada a la lista de Jugadas


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
    
    // Liberar jugadas realizadas, cada casilla del array es un puntero a un malloc(Casilla)
    for (int i = 0 ; i < (cantidadFichas - 4) ; i++)
        free(jugadasRealizadas[i]);

    // Liberamos las fichas volteadas si no pudo ser liberado con anterioridad
    if (fichasVolteadas != NULL)
        free(fichasVolteadas);


    // Verificar que todo funciona con Valgrind

    return 0;
}