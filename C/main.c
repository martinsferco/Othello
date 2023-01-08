#include "main.h"

int main(int argv, char* argc[]){

    // Chequeamos la cantidad de argumentos
    if (verificarCantidadArgumentos(argv)){
        return 0;
    }



    // Abrimos el archivo con el nombre pasado como argumentos
    FILE *archivoJuego = fopen(argc[1],"r");
    
    // Verificamos que dicho nombre corresponda a un archivo valido
    if (archivoJuego == NULL){

        printf("ERROR: El nombre pasado no corresponde a ningun archivo. Finalizando partida...\n");
        return 0;
    }

    // Chequeamos que la informacion preliminar al juego sea correcta:
        // Colores Jugadores: Que sean validos y distintos entre si
        // Color inicio: Que sea valido


    // Inicializamos el tablero: Utilizaremos un array bidimensional

    // Recorremos por todas las jugadas mientras se cumplan
    // determinadas condiciones

        // Vemos la fichas dadas vueltas
        
        // Volteamos las fichas

        // Cambiamos el turno

    


    // Mostramos el mensaje final




    // Generamos el archivo para que lo tome el programa de Python
    // En caso de que la partida haya terminado totalmente, no generamos archivo.
    // En caso de que la partida haya terminado a medias, generamos un archivo
    // en donde se muestre el Tablero Final y el Turno Actual.


    return 0;
}