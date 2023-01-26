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
    if (! leerInformacionPreliminar(&jugador1,&jugador2,&colorInicio,archivoJuego)){
        fclose(archivoJuego);
        return 1; 
    }

    mensajeInicio(jugador1,jugador2,colorInicio);

    char turnoActual = colorInicio;

    // Creamos e inicializamos el tablero
    char tableroJuego[tamTablero][tamTablero];
    inicializarTablero(tableroJuego,tamTablero);

    // Aqui almacenamos las jugadas que vamos leyendo del archivo
    char jugadaLeida[100];
    Casilla jugadaConvertida;

    // Leemos la primer jugada
    char* verificadorLectura = fgets(jugadaLeida,100,archivoJuego);
    
    // Iremos almacenando las dos ultimas jugadas
    Casilla jugadasRealizadas[2] = {crearCasilla(0,0),crearCasilla(0,0)};
    
    int cantidadFichasColor[] = {2,2};

    // Iremos guardando las fichas que fueron volteadas
    Casilla* fichasVolteadas = NULL;  
    int cantidadVolteadas;


    while (! partidaTerminada(cantidadFichasColor,jugadasRealizadas) && ! finLectura(verificadorLectura) && 
             jugadaVerifica(jugadaLeida,turnoActual,tableroJuego,tamTablero,&fichasVolteadas,&cantidadVolteadas)){

        // Convertimos la jugada
        jugadaConvertida = convertirJugada(jugadaLeida,tamTablero);

        // printf("JUGADA CONVERTIDA: (%d,%d)\n",jugadaConvertida.columna,jugadaConvertida.fila);

        // Agregamos la jugada a nuestro registro de jugadas
       agregarJugada(jugadaConvertida,jugadasRealizadas);
        
        // Vemos si no se salteo el turno
        if (jugadaConvertida.columna != -1 && jugadaConvertida.fila != -1){

            voltearFichas(jugadaConvertida,fichasVolteadas,cantidadVolteadas,turnoActual,tableroJuego,tamTablero);
        
            actualizarCantidadFichasColor(cantidadFichasColor,cantidadVolteadas,turnoActual);

        }

        // Cambiamos el turno
        turnoActual = cambiarTurno(turnoActual);

        // Leemos la nueva jugada
        verificadorLectura = fgets(jugadaLeida,100,archivoJuego);

    }
    
    fclose(archivoJuego);

    // Mostramos el tablero final
    mostrarTablero(tableroJuego,tamTablero);

    // Generamos el archivo si la partida no termino y se leyo todo el archivo 
    if (partidaIncompleta(verificadorLectura,cantidadFichasColor,jugadasRealizadas)){
        printf("\nAVISO: Generando archivo para continuacion de partida...\n");
        generarArchivo(tableroJuego,tamTablero,turnoActual);
    }

    // Liberamos la memoria pedida dinamicamente
    liberarMemoria(&jugador1,&jugador2,fichasVolteadas);

    return 0;
}