// ________________________________________________________________________
// LICENCIATURA EN CIENCIAS DE LA COMPUTACION - R123 Programacion II - 2022
//
// Documentacion Trabajo Practico Final - Parte C
// Alumno: Sferco Martin
// ________________________________________________________________________
//
//
// - EJECUCION DEL PROGRAMA:
//                          Para ejecutar el programa, primero debemos abrir
//  una consola dentro de la carpeta C. Compilamos los archivos, ejecutando
//  el siguiente comando:
//
//          $ gcc main.c functions.c
// 
//  Una vez compilado el programa, se nos habra creado un ejectuable con el
//  nombre a.out o a.exe, dependiendo el sistema operativo. Ahora, debemos
//  ejecutar el programa, lo cual lo haremos abriendo una consola dentro de
//  de la carpeta de C y ejecutamos el siguiente comando:
// 
//          $ ./a.out ../juegosPrueba/nombreArchivo 
//  
//  en donde nombreArchivo debe colocarse el nombre de archivo de juego que 
//  quieras procesar (con la extension .txt) y que se encuentre dentro de la
//  carpeta juegosPrueba. En el caso que se quiera utilizar otra carpeta con
//  archivos de prueba deberiamos utilizar el siguiente comando:
//
//          $ ./a.out ../tuCarpeta/nombreArchivo 
//
//  reeemplazando tuCarpeta por el nombre de la carpeta que hayas agregado
//  en la carpeta principal del proyecto.
//
//
//  - EJECUCION DE LOS TESTS:
//                           Para ejecutar los tests, primero debemos 
//    compilar los archivos. Para eso, abrimos una consola dentro de la 
//    carpeta C y compilamos ejecutando el siguiente comando:
//
//          $ gcc test.c functions.c -o test.out
//
//    Una vez compilado, se nos habra creado un ejecutable con el nombre
//    test.out. Para ejecutarlo, escribimos el siguiente comando en una
//    consola abierta en la 
//
//          $ ./test.out 
//
//  
//  - DISENIO DE DATOS Y RESOLUCION:
//                                  A continuacion, explicaremos un poco el
//    disenio de datos que hemos utilizado y un poco sobre la resolucion:
//
//          - Jugadores:
//                      Para los jugadores creamos una estructura llamada
//            jugador, la cual tiene un campo de tipo char* donde guardaremos
//            de manera dinamica los nombres, y otro campo de tipo char donde
//            guardaremos el color del jugador.
//
//          - Tablero:       
//                    La informacion de las fichas jugadas de cada color, la
//            iremos almacenanando un dato de tipo char[][], para que podamos
//            tener una idea de coordenadas en X y en Y. Cada una de las 
//            casillas tendra tres posibles valores:
//
//                  - 'X' - No hay ninguna ficha colocada.
//                  - 'B' - Hay una ficha blanca colocada.
//                  - 'N' - Hay una ficha negra colocada.
//
//          - Casillas:
//                      Para ir pasando la informacion de las casillas entre 
//          funciones, trabajamos con una estructura llamada Casilla, la cual
//          tiene dos campos de tipo entero, las cuales guardan la posicion
//          X e Y de cada una de las casillas.
//
//          - Informacion preliminar:
//                                   Antes de comenzar con la lectura del 
//          archivo, verificaremos que los colores de los dos jugadores
//          sean correctos y diferentes entre si. Ademas, tenemos que ver
//          que el color de inicio sea correcto. Una vez que se haya 
//          verificado toda esta informacion, la almacenamos en variables
//          y ya podemos comenzar la verifiacion de las jugadas.
//
//          - Terminacion de partida:
//                                  El programa puede finalizar por 
//          diferentes razones:
//
//              - Error en jugada:
//
//                  - No cumple el formato estipulado.
//                  - Se sale de rango.
//                  - La casilla se encuentra ocupada.
//                  - La jugada no genera cambios.
//                  - Se salta el turno cuando habia jugadas posibles.
//      
//              - Finalizacion de lectura:
//                                       Esto indica que se llego al final
//              del archivo y no se se proporcionaron mas jugadas.
//
//              - Juego terminado: 
//
//                  - Se colocaron todas las fichas.
//                  - Alguno de los jugadores se quedo sin fichas.
//                  - Se salto el turno dos veces consecutivas.
//
//
//          - Generacion de archivo: 
//                                  En el caso de que la partida haya
//          quedado a medias y se pueda seguir jugando, el programa
//          generara un archivo .txt en la carpeta juegosGenerados.
//          Dicho archivo contendra informacion de la partida, la cual
//          sera la posicion de todas las fichas y el turno del jugador
//          que le toca en el siguiente turno.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
