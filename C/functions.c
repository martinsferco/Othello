#include "functions.h"


Casilla crearCasilla(int columna, int fila){

    Casilla casilla;

    casilla.columna = columna;
    casilla.fila = fila;

    return casilla;
}



VectorDireccion crearVector(int x, int y){

    VectorDireccion vector;

    vector.x = x;
    vector.y = y;

    return vector;
}



int verificarCantidadArgumentos(int cantidadArgumentos){

    if (cantidadArgumentos == 1){
        printf("ERROR: No ha pasado argumentos suficientes. Finalizando el programa...\n");
        return 0;
    }


    if (cantidadArgumentos > 2){
        printf("ERROR: Ha pasado demasiados argumentos. Finalizando el programa...\n");
        return 0;
    }

    // Se ha pasado la cantidad correcta de argumentos
    return 1;
}



int leerInformacionPreliminar(Jugador* jugador1, Jugador* jugador2, char* colorInicio, FILE* archivoJuego){

    char bufferJugador1[100];
    char bufferJugador2[100];
    char bufferColor[100];

    fgets(bufferJugador1,100,archivoJuego);

    char* nombre1 = strtok(bufferJugador1,",");
    char* color1 = strtok(NULL,",");

    fgets(bufferJugador2,100,archivoJuego);

    char* nombre2 = strtok(bufferJugador2,",");
    char* color2 = strtok(NULL,",");

    fgets(bufferColor,100,archivoJuego);

    // Verificamos que todos los colores esten bien
    if (! verificarInformacionPreliminar(color1, color2, bufferColor)){
        return 0;
    }
    
    // Copiamos la informacion obtenida
    jugador1->nombreJugador = malloc(sizeof(char) * (strlen(nombre1) + 1));
    strcpy(jugador1->nombreJugador,nombre1);

    jugador1->colorJugador = toupper(color1[0]);


    jugador2->nombreJugador = malloc(sizeof(char) * (strlen(nombre2) + 1));
    strcpy(jugador2->nombreJugador,nombre2);

    jugador2->colorJugador = toupper(color2[0]);

    *colorInicio = toupper(bufferColor[0]);

    return 1;
}



int verificarInformacionPreliminar(char* color1, char* color2, char* colorI){

    if (! verificarColor(color1)){
        printf("ERROR: El color del primer jugador no es valido. Finalizando programa...\n");
        return 0;
    }

    if (! verificarColor(color2)){
        printf("ERROR: El color del segundo jugador no es valido. Finalizando programa...\n");
        return 0;
    }

    if (! coloresDistintos(color1,color2)){
        printf("ERROR: Los colores de los jugadores coinciden. Finalizando programa...\n");
        return 0;
    }

    if (! verificarColor(colorI)){
        printf("ERROR: El color de inicio no es correcto. Finalizando el programa...\n");
        return 0;
    }

    // Si llegamos hasta aca, es que la informacion preliminar es correcta
    return 1;
}



int verificarColor(char* color){

    return ! (strcmp(color,"B\n") && strcmp(color,"N\n") &&
            strcmp(color,"b\n") && strcmp(color,"n\n"));
}



int coloresDistintos(char* color1, char* color2){

    return (toupper(color1[0]) != toupper(color2[0]));
}



int partidaTerminada(int* cantidadFichasColor, Casilla* jugadasRealizadas){

    // Verificamos si se hicieron dos saltos de turno consecutivos
    if (dobleSaltoTurno(jugadasRealizadas)){
        printf("Se han realizado dos saltos de turno de manera consectuvia. La partida ha terminado.\n");
        mensajeGanador(cantidadFichasColor);
        return 1;
    }

    // Vemos si alguno de los jugadores se quedo sin fichas
    if (cantidadFichasColor[0] == 0){
        printf("El jugador de las fichas blancas se quedo sin fichas. ");
        mensajeGanador(cantidadFichasColor);
        return 1;
    }

    if (cantidadFichasColor[1] == 0){
        printf("El jugador de las fichas negras se ha quedado sin fichas. ");
        mensajeGanador(cantidadFichasColor);
        return 1;
    }

     // Verificamos si colocamos todas las fichas
    if (cantidadFichasColor[0] + cantidadFichasColor[1] >= 64){
        printf("Se han colocado todas las fichas sobre el tablero. ");
        mensajeGanador(cantidadFichasColor);
        return 1;
    }

    // Si llegamos hasta aca la partida no termino
    return 0;
}



int finLectura(char* verificadorLectura){

     // Vemos si llegamos al final del archivo
    if (verificadorLectura == NULL){
        printf("Se ha llegado al final del archivo de jugadas. No se puede determinar un ganador...\n");
        return 1;
    }
    return 0;
}



int jugadaVerifica(char* jugada, char turnoActual, char tableroJuego[][8],int tamTablero, Casilla** registroVolteadas, int* cantidadVolteadas){

    // Primero vemos si es salto de turno
    if (strcmp(jugada,"\n") == 0){

        if (existenJugadasPosibles(turnoActual, tableroJuego, tamTablero)){
            printf("ERROR: Se salto de turno cuando existen jugadas posibles.\n");
            mensajeErrorJugador(jugada,turnoActual);
            return 0;
        }

        return 1;
    }

    if (! verificarFormato(jugada)){
        mensajeErrorJugador(jugada,turnoActual);
        return 0;
    }

    if (! verificarRango(jugada, tamTablero)){
        printf("ERROR: La jugada se sale de rango.\n");
        mensajeErrorJugador(jugada,turnoActual);
        return 0;
    }

    Casilla jugadaConvertida = convertirJugada(jugada,tamTablero);

    if (ocupada(jugadaConvertida,tableroJuego)){
        printf("ERROR: La casilla se encuentra ocupada por otra ficha.\n");
        mensajeErrorJugador(jugada,turnoActual);
        return 0;
    }
    
    int cantidadFichasVolteadas = fichasVolteadasJugada(jugadaConvertida, turnoActual, tableroJuego, tamTablero, registroVolteadas);

    if (! cantidadFichasVolteadas){
        printf("ERROR: La jugada no genera cambios en el tablero.\n");
        mensajeErrorJugador(jugada,turnoActual);
        return 0;
    }

    // Si llegamos hasta aca, la jugada no era un salto de turno y genera cambios
    *cantidadVolteadas = cantidadFichasVolteadas;

    return 1;
}



int partidaIncompleta(char* verificadorLectura, int* cantidadFichasColor, Casilla* jugadasRealizadas){
   
    if (dobleSaltoTurno(jugadasRealizadas))
        return 0;
    
    if (cantidadFichasColor[0] == 0)
        return 0;

    if (cantidadFichasColor[1] == 0)
        return 0;

    if (cantidadFichasColor[0] + cantidadFichasColor[1] >= 64)
        return 0;

    if (verificadorLectura != NULL)
        return 0;

    // La partida no termino, y llegamos al final del archivo
    return 1;
}



int dobleSaltoTurno(Casilla* jugadasRealizadas){

    return (((jugadasRealizadas[0].columna == -1) && (jugadasRealizadas[0].fila == -1)) && 
            ((jugadasRealizadas[1].columna == -1) && (jugadasRealizadas[1].fila == -1)));
}



int existenJugadasPosibles(char turnoActual, char tableroJuego[][8],int tamTablero){

    int cantidadJugasPosibles = 0;

    Casilla* bufferRegistroVolteadas = NULL;

    for (int i = 0 ; i < tamTablero && cantidadJugasPosibles == 0 ; i++){

        for (int j = 0 ; j < tamTablero && cantidadJugasPosibles == 0 ; j++){

            if (! ocupada(crearCasilla(i,j),tableroJuego) &&
                  fichasVolteadasJugada(crearCasilla(i,j),turnoActual,tableroJuego,tamTablero,&bufferRegistroVolteadas))
            
                cantidadJugasPosibles++;
        }
    }

    // Si encontramos una, liberamos la memoria del buffer de jugadas
    if (cantidadJugasPosibles){
        free(bufferRegistroVolteadas);
        return 1;
    }

    // En caso contrario, no encontramos ninguna posible
    return 0;
}



int verificarFormato(char* jugada){

    // Verificamos que tenga el largo adecuado (incluyendo el '\n')
    if (! verificarLargo(jugada)){
        printf("ERROR: La jugada no tiene el largo estipulado.\n");
        return 0;
    }  
    

    if (! isalpha(jugada[0])){
        printf("ERROR: La primer componente debe ser una letra.\n");
        return 0;
    }

    if (! isdigit(jugada[1])){
        printf("ERROR: La segunda componente debe ser un numero.\n");
        return 0;
    }

    // Si llegamos hasta aca, es que verifica el formato
    return 1;
}



int verificarLargo(char* jugada){

    int largo = strlen(jugada);

    return ((jugada[largo - 1] == '\n' && largo == 3) || (jugada[largo - 1] != '\n' && largo == 2));
}



int verificarRango(char* jugada, int tamTablero){

    char rangoLetras[8] = {'A','B','C','D','E','F','G','H'};
    char rangoNumeros[8] = {'1','2','3','4','5','6','7','8'};

    return (buscarArray(jugada[0],rangoLetras,tamTablero) &&
            buscarArray(jugada[1],rangoNumeros,tamTablero));
}



int ocupada(Casilla jugada, char tableroJuego[][8]){

    return (! (tableroJuego[jugada.columna][jugada.fila] == 'X'));
}



Casilla convertirJugada(char* jugada, int tamTablero){
    
    char rangoLetras[8] = {'A','B','C','D','E','F','G','H'};
    char rangoNumeros[8] = {'1','2','3','4','5','6','7','8'};

    int columna,fila;

    if (! strcmp(jugada,"\n")){
        return crearCasilla(-1,-1);
    }

   // Convertimos la letra
   for (int i = 0 ; i < tamTablero ; i++){

        if (toupper(jugada[0]) == rangoLetras[i])
            columna = i;

        if (toupper(jugada[1]) == rangoNumeros[i])
            fila = i;
   }

    return crearCasilla(columna,fila);
}



char cambiarTurno(char turnoActual){

    if (turnoActual == 'B')
        
        return 'N';

    return 'B';
}



void agregarJugada(Casilla jugadaAgregada, Casilla* jugadasRealizadas){

    jugadasRealizadas[0] = jugadasRealizadas[1];
    jugadasRealizadas[1] = jugadaAgregada;
}



int buscarArray(char objetivo, char* arrayValores,int tamArray){

    int verificadorBusqueda = 0;

    for(int i = 0 ; i < tamArray && verificadorBusqueda == 0 ; i++){

        if (arrayValores[i] == toupper(objetivo))
            verificadorBusqueda++;
    }

    return verificadorBusqueda;
}



int fichasVolteadasJugada(Casilla jugada, char turnoActual, char tableroJuego[][8], int tamTablero,Casilla** registroVolteadas){

    // Definimos las direcciones de busqueda
    VectorDireccion direccion[4] = {crearVector(1,0),crearVector(0,1),crearVector(1,-1),crearVector(1,1)};

    // Definimos los sentidos para cada una de las direcciones
    int sentido[] = {1,-1};

    char colorOpuesto = cambiarTurno(turnoActual);

    // Indices de movimiento
    int iX;
    int iY;

    // Para llevar el registro de las fichas encontradas del otro color
    // en cada una de las direcciones
    Casilla fichasColorOpuesto[8];
    int cantidadFichasColorOpuesto;

    // Para almacenar todas las fichas volteadas
    Casilla fichasVolteadas[32];
    int cantidadVolteadas = 0;

    // Recorremos cada una de las direcciones
    for (int d = 0 ; d < 4 ; d++){

        // Recorremos cada uno de los sentidos
        for (int s = 0 ; s < 2 ; s++) {

            iX = jugada.columna + sentido[s] * direccion[d].x;
            iY = jugada.fila + sentido[s] * direccion[d].y;

            cantidadFichasColorOpuesto = 0;

            while (enRango(crearCasilla(iX,iY),sentido[s],direccion[d],tamTablero) && 
                   tableroJuego[iX][iY] == colorOpuesto){

                fichasColorOpuesto[cantidadFichasColorOpuesto] = crearCasilla(iX,iY); 
                cantidadFichasColorOpuesto++;

                // Vemos si la siguiente casilla encierra a todas las que hemos encontrado
                if (tableroJuego[iX + sentido[s] * direccion[d].x][iY + sentido[s] * direccion[d].y] == turnoActual){

                    copiarCasillas(fichasVolteadas,cantidadVolteadas,fichasColorOpuesto,cantidadFichasColorOpuesto);
                    cantidadVolteadas += cantidadFichasColorOpuesto;
                }

                // Nos seguimos moviendo en esa direccion
                iX += sentido[s] * direccion[d].x;
                iY += sentido[s] * direccion[d].y;
            }
        }
    }

    // Si la jugada genera cambios, guardamos la informacion
    if (cantidadVolteadas)
        almacenarInformacionVolteadas(registroVolteadas, cantidadVolteadas, fichasVolteadas);

    return cantidadVolteadas;
}



int enRango(Casilla casilla, int sentido, VectorDireccion direccion, int tamTablero){

    int x = casilla.columna;
    int y = casilla.fila;

    int minimo = 1;
    int maximo = (tamTablero - 1) - minimo;

    int desplazamientoX = sentido * direccion.x;
    int desplazamientoY = sentido * direccion.y;

    // Definimos unos verificadores para cada una de las direcciones
    int enRangoX;
    int enRangoY;

    if (desplazamientoX != 0){

        if (desplazamientoX == 1)
            enRangoX = x <= maximo;
        
        else
            enRangoX = x >= minimo;
    }
    
    else 
        enRangoX = 1;

    if (desplazamientoY != 0){

        if (desplazamientoY == 1)
            enRangoY = y <= maximo;
        
        else
            enRangoY = y >= minimo;
    }

    else
        enRangoY = 1;

    return (enRangoX && enRangoY);
}



void copiarCasillas(Casilla* destino, int inicio, Casilla* origen, int cantidad){

    for (int i = 0 ; i < cantidad ; i++)

        destino[inicio + i] = origen[i];
}



void almacenarInformacionVolteadas(Casilla** registroVolteadas, int cantidadVolteadas, Casilla* fichasVolteadas){

    // Primero debemos liberar la memoria del anterior registro de volteadas
    if (*registroVolteadas != NULL)
            free(*registroVolteadas);

    // Ahora debemos pedir espacio para almacenar las volteadas
    *registroVolteadas = malloc(sizeof(Casilla) * cantidadVolteadas);

    // Copiamos las fichas registradas
    copiarCasillas(*registroVolteadas,0,fichasVolteadas,cantidadVolteadas);
}



void inicializarTablero(char tableroJuego[][8], int tamTablero){

    for (int x = 0 ; x < tamTablero ; x++){
        
        for (int y = 0 ; y < tamTablero ; y++){

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
    
    for (int y = 0 ; y < tamTablero ; y++){

        printf("\n   -------------------------\n");

        printf(" %d ",y + 1);

        for (int x = 0 ; x < tamTablero ; x++){

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



void actualizarCantidadFichasColor(int* cantidadFichasColor, int cantidadFichasVolteadas, char turno){

    // Nos sirven para ver cual es el color al cual le tenemos que sacar y a cual le tenemos
    // que agregar
    int agregarVolteadas;
    int quitarVolteadas;

    if (turno == 'B'){
        agregarVolteadas = 0;
        quitarVolteadas = 1;
    }

    else{
        agregarVolteadas = 1;
        quitarVolteadas = 0;
    }

    cantidadFichasColor[agregarVolteadas] += cantidadFichasVolteadas + 1;
    cantidadFichasColor[quitarVolteadas] -= cantidadFichasVolteadas;
}



void voltearFichas(Casilla jugada, Casilla* fichasVolteadas, int cantidadVolteadas, char turnoActual, char tableroJuego[][8], int tamTablero){

    for (int i = 0 ; i < cantidadVolteadas ; i++)

        tableroJuego[fichasVolteadas[i].columna][fichasVolteadas[i].fila] = turnoActual;

    tableroJuego[jugada.columna][jugada.fila] = turnoActual;
}



void mensajeInicio(Jugador jugador1, Jugador jugador2, char colorInicio){

    printf("____________________________\n");
    printf("Jugador 1: %s\nColor: %c\n\n",jugador1.nombreJugador,jugador1.colorJugador);
    printf("Jugador 2: %s\nColor: %c\n\n",jugador2.nombreJugador,jugador2.colorJugador);
    printf("Color inicio: %c\n",colorInicio);
    printf("____________________________\n");
}



void mensajeGanador(int* cantidadFichasColor){

    if (cantidadFichasColor[0] == cantidadFichasColor[1])
        printf("Los jugadores han empatado.\n");

    if (cantidadFichasColor[0] > cantidadFichasColor[1])
        printf("Ha ganado el jugador de las fichas blancas.\n");

    if (cantidadFichasColor[0] < cantidadFichasColor[1])
        printf("Ha ganado el jugador de las fichas negras.\n");
}



void mensajeErrorJugador(char* jugada, char turno){

    char color[10];

    char jugadaCopiada[5];
    strcpy(jugadaCopiada,jugada); 
    jugadaCopiada[0] = toupper(jugadaCopiada[0]);

    if (turno == 'B')
        strcpy(color,"blancas");
    
    else    
        strcpy(color,"negras");

    if (strcmp(jugada,"\n") == 0)
        printf("El error fue cometido por el jugador de las fichas %s\n",color);

    else
        printf("El error fue cometido por el jugador de las fichas %s en la jugada %s\n",color,jugadaCopiada);
}



void generarArchivo(char tableroFinal[][8], int tamTablero, char turnoFinal){

    // Abrimos el archivo
    FILE* archivoGenerado = fopen("../generados/partidaGenerada.txt","w");

    // Guardamos tablero
    for (int y = 0 ; y < tamTablero ; y++){

        if (y != 0)
            fputc('\n',archivoGenerado);

        for (int x = 0 ; x < tamTablero ; x++)
            fputc(tableroFinal[x][y],archivoGenerado);
    }

    // Guardamos color siguiente
    fputc('\n',archivoGenerado);
    fputc(turnoFinal,archivoGenerado);

    fclose(archivoGenerado);
}



void liberarMemoria(Jugador* jugador1, Jugador* jugador2, Casilla* fichasVolteadasJugada){

    free(jugador1->nombreJugador);
    free(jugador2->nombreJugador);
        
    if (fichasVolteadasJugada != NULL)
        free(fichasVolteadasJugada);
}