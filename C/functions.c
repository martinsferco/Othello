#include "functions.h"



// FUNCIONES QUE VERIFICAN ARGUMENTOS DEL PROGRAMA


int verificarCantidadArgumentos(int cantidadArgumentos){

    if (cantidadArgumentos == 1){
        printf("No ha pasado argumentos suficientes. Fin del programa.\n");
        return 0;
    }


    if (cantidadArgumentos > 2){
        printf("Ha pasado demasiados argumentos. Fin del programa.\n");
        return 0;
    }

    // Se ha pasado la cantidad correcta de argumentos
    return 1;
}







// FUNCIONES QUE VERIFICAN INFORMACION PRELIMINAR DEL JUEGO
int leerInformacionPreliminar(Jugador* jugador1, Jugador* jugador2, char* colorInicio, FILE* archivoJuego){

    char bufferLecturaArchivo[100];
    char colorI[100];

    
    // Leemos la primer linea
    fgets(bufferLecturaArchivo,100,archivoJuego);

    // Recuperamos nombre y color
    char* nombre1 = strtok(bufferLecturaArchivo,",");
    char* color1 = strtok(NULL,",");
    color1[0] = toupper(color1[0]);
    

    // Leemos la segunda linea
    fgets(bufferLecturaArchivo,100,archivoJuego);

    // Recuperamos nombre y color
    char* nombre2 = strtok(bufferLecturaArchivo,",");
    char* color2 = strtok(NULL,",");
    color2[0] = toupper(color2[0]);

    

    // Leemos la tercer linea
    fgets(colorI,100,archivoJuego);



    // Verificamos que todos los colores esten bien
    if (! verificarInformacionPreliminar(color1, color2, colorI)){
        return 0;
    }
    
    printf("Copiando informacion a las variables...\n");
   
    // Guardamos la informacion en las variables    
    jugador1->nombreJugador = malloc(sizeof(char) * (strlen(nombre1) + 1));
    strcpy(jugador1->nombreJugador,nombre1);

    jugador1->colorJugador = copiarColor(color1);


    jugador2->nombreJugador = malloc(sizeof(char) * (strlen(nombre2) + 1));
    strcpy(jugador2->nombreJugador,nombre2);

    jugador2->colorJugador = copiarColor(color2);
    
    *colorInicio = copiarColor(colorI);

    return 1;
}


char copiarColor(char* color){

    if (! strcmp(color,"B\n"))
        return 'B';
    
    return 'N';


}



int verificarInformacionPreliminar(char* color1, char* color2, char* colorI){


    // Vemos que cumpla el color del jugador 1
    if (! verificarColor(color1)){
        printf("ERROR: El color del primer jugador no es valido. Finalizando programa...\n");
        return 0;
    }

    // Vemos que cumpla el color del jugador 2
    if (! verificarColor(color1)){
        printf("ERROR: El color del segundo jugador no es valido. Finalizando programa...\n");
        return 0;
    }


    // Vemos que los colores de los jugadores no coincidan
    if (! strcmp(color1,color2)){
        printf("ERROR: Los colores de los jugadores coinciden. Finalizando programa...\n");
        return 0;
    }

    // Vemos que verifique el color de inicio
    if (! verificarColor(colorI)){
        printf("ERROR: El color de inicio no es correcto. Finalizando el programa...\n");
        return 0;
    }

    // Si llegamos hasta aca, es que la informacion preliminar es correcta
    return 1;
}



int verificarColor(char* color){

    return (! (strcmp(color,"B\n") && strcmp(color,"N\n")));

}



void inicializarTablero(char tableroJuego[][8], int tamTablero){

    for (int x = 0; x < tamTablero; x++){
        
        for (int y = 0; y < tamTablero; y++){

            tableroJuego[x][y] = 'X';

            // Colocamos ficha blanca
            if ((x == 3 && y == 3) || (x == 4 && y == 4))
                tableroJuego[x][y] = 'B';
            
            // Colocamos ficha negra
            if ((x == 4 && y == 3) || (x == 3 && y == 4))
                tableroJuego[x][y] = 'N';
        
        }
    }
}



void mostrarTablero(char tableroJuego[][8], int tamTablero){
    
    printf("\n\n    A  B  C  D  E  F  G  H");
    
    for (int y = 0; y < tamTablero; y++){

        printf("\n   -------------------------\n");

        printf(" %d ",y + 1);

        for (int x = 0; x < tamTablero; x++){

            if (tableroJuego[x][y] == 'B')
                printf("| B");

            if (tableroJuego[x][y] == 'N')
                printf("| N");

            if (tableroJuego[x][y] == 'X')
                printf("|  ");
        }

        printf("|");
    }

    printf("\n   -------------------------\n\n");
}