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
        printf("ERROR: La informacion preliminar era incorrecta. Finalizando el programa...\n");
        return 1;
    } 


    // Si llegamos hasta aqui, la informacion preliminar era correcta,
    // por lo que podemos empezar con la partida.


    // Inicializamos el tablero: Utilizaremos un array bidimensional
    char tableroJuego[tamTablero][tamTablero];
    inicializarTablero(tableroJuego,tamTablero);
    
    // Mostramos el tablero por primera vez
    mostrarTablero(tableroJuego,tamTablero);

    // Tomamos la primer jugada

    // Posiciones posibles
    // Fichas afectadas

    // WHILE PARTIDANOTERMINADA

        // Ver las fichas que afecta

        // Vemos la fichas dadas vueltas
        
        // Volteamos las fichas

        // Cambiamos el turno

        // Leemos la nueva jugada

    

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

    return 0;
}