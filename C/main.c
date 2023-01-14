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

    
    Casilla* jugadasRealizadas[64]; // Punteros a casillas
    int cantidadJugadas = 4;

    // Posiciones posibles
    // Fichas afectadas


    while (! partidaTerminada(jugadaLeida,cantidadJugadas,jugadasRealizadas) &&
             jugadaVerifica(jugadaLeida,turnoActual,tableroJuego,tamTablero)){

        // Ver las fichas que afecta
        
        // Volteamos las fichas

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

    // No olvidar la memoria dinamica que utilizamos 
    // DEBEMOS VERIFICAR QUE TODA LA MEMORIA HA SIDO LIBERADA
    // UTILIZANDO VALGRIND.


    // Liberar nombres de jugadores
    // Liberar jugadas realizazadas, cada una array[i] es un puntero a un malloc

    return 0;
}