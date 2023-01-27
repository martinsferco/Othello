// ________________________________________________________________________
// LICENCIATURA EN CIENCIAS DE LA COMPUTACION - R123 Programacion II - 2022
//
// Documentacion Trabajo Practico Final - Parte C
// Alumno: Sferco Martin
// ________________________________________________________________________
//
// - ARCHIVOS DE JUGADAS: 
//                     En cuanto al formato de los archivos de jugadas, una
//   vez que hayan escrito todas las jugadas que contendra el archivo NO
//   toquen la tecla enter nuevamente. El programa detectara que se quizo
//   saltar el turno y la partida terminara debido a un error de jugada. 
//   Esto afecta a cuando se quiere dejar una partida a medias, ya que la
//   partida se consideraria terminda por un error, y no se generaria el
//   archivo para su posterior continuacion en el programa de Python.  
//   
//   En resumen, el cursor debe terminar en el mismo renglon en el cual
//   se escribio la ultima jugada.
//
//
// - EJECUCION DEL PROGRAMA:
//                          Para compilar el programa debemos entrar a la 
//   carpeta C/ que se encuentra en la raiz del proyecto. Luego abrimos una
//   terminal dentro de dicha carpeta y ejecutamos el siguiente comando:
//
//          $ gcc main.c functions.c -o reversi
// 
//  Una vez compilado, ejecutamos el programa con el siguiente comando:
// 
//          $ ./reversi ../partidas/nombreArchivo 
//  
//  en donde nombreArchivo debe colocarse el nombre de archivo de juego que 
//  quieras procesar (con la extension .txt), que se encuentra dentro de la
//  carpeta partidas/. En el caso que se quiera utilizar otra carpeta con
//  archivos de prueba deberiamos utilizar el siguiente comando:
//
//          $ ./reversi ../tuCarpeta/nombreArchivo 
//
//  reeemplazando tuCarpeta por el nombre de la carpeta que hayas agregado
//  en la raiz del proyecto.
//
//
//  - EJECUCION DE LOS TESTS:
//                           Para compilar los archivos de tests, primero
//    debemos entrar a la carpeta C/ que se encuentra en la raiz del del 
//    proyecto. Luego abrimos una terminal dentro de dicha carpeta y 
//    ejecutamos el siguiente comando:
//
//          $ gcc test.c functions.c -o tests
//
//    Una vez compilado, ejecutamos los test con el siguiente comando:
//
//          $ ./tests
//
//    Apareceran muchos mensajes por pantalla, pero se debe a que las 
//    funciones que testeamos imprimen la informacion de las jugadas
//    erroneas. Aclaro que no son errores en los tests.
//
//  
//  - DISENIO DE DATOS Y RESOLUCION:
//                                  A continuacion, explicaremos un poco el
//    disenio de datos que hemos utilizado y un poco sobre la resolucion:
//
//          - Jugadores:
//                      Para los jugadores creamos una estructura llamada
//            Jugador, la cual tiene un campo de tipo char* donde guardaremos
//            de manera dinamica los nombres, y otro campo de tipo char donde
//            guardaremos el color del jugador.
//
//          - Tablero:       
//                    La informacion de las fichas jugadas de cada color, la
//            iremos almacenanando en un dato de tipo char[][], para que podamos
//            tener una idea de coordenadas en X e Y. Cada una de las 
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
//          generara un archivo partidaGenerada.txt en la carpeta 
//          generados/, la cual se encuentra en la raiz del proyecto.
//          Dicho archivo contendra informacion de la partida, la cual
//          sera la posicion de todas las fichas y el turno del jugador 
//          que le toca en el siguiente turno. 
//          
//          Si existe ya una partidaGenerada.txt, se reescribira todos
//          los datos del archivo. Seria conveniente que si quiere
//          conservar la informacion del archivo, le cambie el nombre
//          asi puede generar un nuevo archivo sin perder los datos del
//          anterior.
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
