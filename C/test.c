#include "test.h"


int main(){

    test_verificarCantidadArgumentos();
    test_verificarInformacionPreliminar();
    test_verificarColor();
    test_coloresDistintos();
    test_partidaTerminada();
    test_jugadaVerifica();
    test_dobleSaltoTurno();
    test_existenJugadasPosibles();
    test_verificarFormato();
    test_verificarLargo();
    test_ocupada();    
    test_cambiarTurno();
    test_buscarARray();
    test_fichasVolteadasJugada();
    test_enRango();

    return 0;
}



void test_verificarCantidadArgumentos(){

    assert(verificarCantidadArgumentos(2));
    assert(! verificarCantidadArgumentos(1));
    assert(! verificarCantidadArgumentos(3));
}


void test_verificarInformacionPreliminar(){
    
    assert(verificarInformacionPreliminar("N\n","B\n","B\n"));
    assert(verificarInformacionPreliminar("N\n","B\n","n\n"));
    assert(verificarInformacionPreliminar("b\n","n\n","b\n"));
    assert(! verificarInformacionPreliminar("R\n","B\n","B\n"));
    assert(! verificarInformacionPreliminar("n\n","t\n","B\n"));
    assert(! verificarInformacionPreliminar("R\n","t\n","B\n"));
    assert(! verificarInformacionPreliminar("b\n","n\n","r\n"));
}


void test_verificarColor(){
    
    assert(verificarColor("B\n"));
    assert(verificarColor("b\n"));
    assert(verificarColor("N\n"));
    assert(verificarColor("n\n"));
    assert(! verificarColor("R\n"));
}


void test_coloresDistintos(){
    
    assert(coloresDistintos("B\n","n\n"));
    assert(coloresDistintos("N\n","b\n"));
    assert(coloresDistintos("b\n","n\n"));
    assert(! coloresDistintos("B\n","b\n"));
    assert(! coloresDistintos("N\n","n\n"));
}


void test_partidaTerminada(){

    int cantidad1[] = {30,30};
    int cantidad2[] = {0,32};
    int cantidad3[] = {60,4};

    Casilla jugadas1[] = {crearCasilla(-1,-1),crearCasilla(-1,-1)};
    Casilla jugadas2[] = {crearCasilla(1,1),crearCasilla(2,3)};

    assert(! partidaTerminada(cantidad1,jugadas2));
    assert(partidaTerminada(cantidad3,jugadas2));
    assert(! partidaTerminada(cantidad1,jugadas2));
    assert(partidaTerminada(cantidad2,jugadas2));
    assert(partidaTerminada(cantidad2,jugadas1));
    assert(partidaTerminada(cantidad1,jugadas1));
    return;
}


void test_finLectura(){
    
    assert(finLectura(NULL));
    assert(! finLectura("x32bboa"));
}


void test_jugadaVerifica(){
    
    Tablero tablero1,tablero2;
    inicializarTablero(&tablero1,8);

    char* fichas[8] = {"BNXXXXXX","NNXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX","XXXXXXXX"};
    tablero2.casillas = fichas;
    tablero2.dimension = 8;

    Casilla* registroVolteadas = NULL;
    int cantidadVolteadas;

    assert(! jugadaVerifica("\n",'N',&tablero1,&registroVolteadas,&cantidadVolteadas));
    assert(! jugadaVerifica("\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));
    assert(jugadaVerifica("\n",'N',&tablero2,&registroVolteadas,&cantidadVolteadas));

    assert(! jugadaVerifica("AA\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));
    assert(! jugadaVerifica("AB2\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));

    assert(! jugadaVerifica("a9\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));
    assert(! jugadaVerifica("Z1\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));

    assert(! jugadaVerifica("d3\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));
    assert(! jugadaVerifica("E4\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));

    assert(! jugadaVerifica("A1\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));
    assert(! jugadaVerifica("G8\n",'N',&tablero1,&registroVolteadas,&cantidadVolteadas));

    assert(jugadaVerifica("d6\n",'B',&tablero1,&registroVolteadas,&cantidadVolteadas));
    assert(jugadaVerifica("C4\n",'N',&tablero1,&registroVolteadas,&cantidadVolteadas));

    free(registroVolteadas);
    liberarMemoriaTablero(&tablero1);
}


void test_partidaIncompleta(){

    int cantidad1[] = {30,30};
    int cantidad2[] = {0,32};
    int cantidad3[] = {60,4};

    Casilla jugadas1[] = {crearCasilla(-1,-1),crearCasilla(-1,-1)};
    Casilla jugadas2[] = {crearCasilla(1,1),crearCasilla(2,3)};

    assert(partidaIncompleta(NULL,cantidad1,jugadas2));
    assert(! partidaIncompleta(NULL,cantidad2,jugadas2));
    assert(! partidaIncompleta(NULL,cantidad3,jugadas2));
    assert(! partidaIncompleta("x3b3",cantidad1,jugadas2));
    assert(! partidaIncompleta("x3b3",cantidad2,jugadas2));
    assert(! partidaIncompleta("x3b3",cantidad2,jugadas1));
    assert(! partidaIncompleta(NULL,cantidad1,jugadas1));
}


void test_dobleSaltoTurno(){

    Casilla jugadas1[] = {crearCasilla(-1,-1),crearCasilla(-1,-1)};
    Casilla jugadas2[] = {crearCasilla(-1,-1),crearCasilla(1,2)};
    Casilla jugadas3[] = {crearCasilla(1,1),crearCasilla(2,3)};

    assert(dobleSaltoTurno(jugadas1));
    assert(! dobleSaltoTurno(jugadas2));
    assert(! dobleSaltoTurno(jugadas3));
}


void test_existenJugadasPosibles(){
    
    Tablero tablero1,tablero2,tablero3;
    inicializarTablero(&tablero1,8);

    char* fichas2[8] = {"XXXNBBBX","XXXXXXBB","XXXXXBXB","XXXXBXXB","XXXNXXXN","XXXXXXXX","XXXXXXXX","XXXXXXXX"};
    tablero2.casillas = fichas2;
    tablero2.dimension = 8;

    char* fichas3[8] = {"NNNNNNNN","XXXXXXXX","BBBBBBBB","XXXXXXXX","NNNNNNNN","XXXXXXXX","BBBBBBBB","XXXXXXXX"};
    tablero3.casillas = fichas3;
    tablero3.dimension = 8;

    assert(existenJugadasPosibles('B',&tablero1));
    assert(existenJugadasPosibles('N',&tablero1));
    assert(existenJugadasPosibles('N',&tablero2));
    assert(existenJugadasPosibles('B',&tablero2));
    assert(! existenJugadasPosibles('B',&tablero3));
    assert(! existenJugadasPosibles('N',&tablero3));

    liberarMemoriaTablero(&tablero1);
}


void test_verificarFormato(){
    
    assert(verificarFormato("B3\n"));
    assert(verificarFormato("a2"));
    assert(! verificarFormato("B23"));
    assert(! verificarFormato("2B"));
    assert(! verificarFormato("BB"));        
}


void test_verificarLargo(){
    
    assert(verificarLargo("B3\n"));
    assert(verificarLargo("B3"));
    assert(verificarLargo("b2\n"));
    assert(! verificarLargo("B23\n"));
    assert(! verificarLargo("b23"));
}


void test_verificarRango(){
    
    assert(verificarRango("A3",8));
    assert(verificarRango("h8",8));
    assert(! verificarRango("Z3",8));
    assert(! verificarRango("A9",8));
}


void test_ocupada(){

    Tablero tablero;
    inicializarTablero(&tablero,8);

    assert(ocupada(crearCasilla(4,4),tablero.casillas));
    assert(ocupada(crearCasilla(3,3),tablero.casillas));
    assert(! ocupada(crearCasilla(0,0),tablero.casillas));
    assert(! ocupada(crearCasilla(7,7),tablero.casillas));

    liberarMemoriaTablero(&tablero);
}


void test_cambiarTurno(){

    assert(cambiarTurno('N') == 'B');
    assert(cambiarTurno('B') == 'N');
}


void test_buscarARray(){
    
    char arrayLetras[] = {'A','B','C'};

    assert(buscarArray('A',arrayLetras,3));
    assert(buscarArray('C',arrayLetras,3));
    assert(! buscarArray('D',arrayLetras,3));
}


void test_fichasVolteadasJugada(){

    Tablero tablero1,tablero2;
    inicializarTablero(&tablero1,8);

    char* fichas[8] = {"XXXNBBBX","XXXXXXBB","XXXXXBXB","XXXXBXXB","XXXNXXXN","XXXXXXXX","XXXXXXXX","XXXXXXXX"};
    tablero2.casillas = fichas;
    tablero2.dimension = 8;

    Casilla* bufferVolteadas = NULL;

    assert(fichasVolteadasJugada(crearCasilla(0,0),'N',&tablero1,&bufferVolteadas) == 0);
    assert(fichasVolteadasJugada(crearCasilla(0,0),'B',&tablero1,&bufferVolteadas) == 0);
    assert(fichasVolteadasJugada(crearCasilla(3,2),'N',&tablero1,&bufferVolteadas) == 1);
    assert(fichasVolteadasJugada(crearCasilla(5,3),'B',&tablero1,&bufferVolteadas) == 1);
    assert(fichasVolteadasJugada(crearCasilla(0,7),'N',&tablero2,&bufferVolteadas) == 9);
    assert(fichasVolteadasJugada(crearCasilla(5,2),'B',&tablero2,&bufferVolteadas) == 1);
    assert(fichasVolteadasJugada(crearCasilla(0,2),'B',&tablero2,&bufferVolteadas) == 1);
    assert(fichasVolteadasJugada(crearCasilla(5,7),'B',&tablero2,&bufferVolteadas) == 1);

    free(bufferVolteadas);
    liberarMemoriaTablero(&tablero1);
}


void test_enRango(){

    assert(enRango(crearCasilla(0,0),1,crearVector(1,0),8));
    assert(enRango(crearCasilla(0,0),1,crearVector(1,1),8));
    assert(! enRango(crearCasilla(0,0),-1,crearVector(1,1),8));
    assert(! enRango(crearCasilla(0,0),1,crearVector(1,-1),8));
    assert(! enRango(crearCasilla(4,0),1,crearVector(1,-1),8));
    assert(enRango(crearCasilla(4,4),-1,crearVector(1,1),8));
    assert(enRango(crearCasilla(7,7),-1,crearVector(1,1),8));
    assert(enRango(crearCasilla(6,3),1,crearVector(1,0),8));
    assert(enRango(crearCasilla(1,3),-1,crearVector(1,-1),8));
}