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


// FUNCIONES RELACIONADAS CON MENSAJES


// FUNCIONES RELACIONADAS 


// FUNCIONES QUE GENERAN EL ARCHIVO DE FIN DE JUEGO