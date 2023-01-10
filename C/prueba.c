#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {

    char* nombreJugador;
    char* colorJugador;

} Jugador;

void inicializarJugador(Jugador* jugador,FILE* archivo);

int main(int argv, char** argc){


    FILE* archivo = fopen(argc[1],"r");

    Jugador jugador1;
    Jugador jugador2;
    char colorInicio;

    inicializarJugador(&jugador1, archivo);

    printf("Nombre: %s\nColor: %s\n",jugador1.nombreJugador,jugador1.colorJugador);


    char buffer[1000];
    fgets(buffer,1000,archivo);
    printf("%s\n",buffer);

    fclose(archivo);
    return 0;
}



void inicializarJugador(Jugador* jugador,FILE* archivo){

    char buffer[1000];

    fgets(buffer,1000,archivo);
    printf("%s",buffer);
    char* token = strtok(buffer,",");
    printf("%s",token);
    
    char* token2 = strtok(NULL,",");
    printf("%s",token2);

    jugador->nombreJugador = malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(jugador->nombreJugador,token);

    jugador->colorJugador= malloc(sizeof(char) * (strlen(token2) + 1));
    strcpy(jugador->colorJugadortoken);
}