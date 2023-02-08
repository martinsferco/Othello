# ________________________________________________________________________
# LICENCIATURA EN CIENCIAS DE LA COMPUTACION - R123 Programacion II - 2022
# 
# Documentacion Trabajo Practico Final - Parte Python
# Alumno: Sferco Martin
# ________________________________________________________________________
#
#
# - EJECUCION DEL PROGRAMA:
#                           Para ejecutar el programa, debemos abrir una consola dentro
#   de la carpeta Python/, la cual se encuentra en la raiz del proyecto. Luego, ejecutamos
#   el siguiente comando:
#   
#           $ python3 main.py ../generados/<nombreArchivo> <colorJugador> <nivelDificultad>
#           
#   en donde todos los argumentos deben estar separados por un espacio. Cada uno 
#   de los argumentos nombreArchivo, turnoJugador y nivelDificultad los debera elegir el
#   usuario y pueden tomar los siguientes valores:
#
#       - <nombreArchivo>       Es el nombre del archivo del cual vamos a empezar la partida.
#                             Tiene que incluir la terminacion .txt y debe estar dentro de
#                             la carpeta generados/.
#   
#       - <colorJugador>        Es el color del jugador, y puede ser B o N. 
#
#       - <nivelDificultad>     Es el nivel de dificultad de la maquina y puede ser 0 o 1.
#
#   En el caso de que estemos en Windows, debemos utilizar python en lugar de python3.
#   En el caso de que se quiera utilizar otra carpeta con archivos generados, se tiene 
#   que incluir dicha carpeta en la raiz del proyecto y se debe ejecutar el comando de 
#   la siguiente manera:
#
#           $ python3 main.py ../<tuCarpeta>/<nombreArchivo> <colorJugador> <nivelDificultad>
#
#   reemplazando <tuCarpeta> por el nombre de la carpeta que hayas incluido en la raiz
#   del proyecto.
#
#
# - EJECUCION DE LOS TESTS:
#                       Para ejecutar los tests de las funciones del programa, debemos abrir
#   una terminal en la carpeta Python/, la cual se encuentra en la raiz del proyecto. A 
#   continuacion, ejecutamos el siguiente comando.
#
#           $ python3 -m pytest test.py
#
#   En el caso de que estemos en Windos, debemos utilizar python en lugar de python3.
#   
#
# - DIVISION DE ARCHIVOS:
#                        Dividimos la totalidad del programa en varios archivos
#   para facilitar el trabajo y la lectura del mismo en un futuro:
#
#       - main.py       Aqui agrupamos todas las funciones y es donde ejecutaremos
#                       el programa.
#
#       - test.py       Aqui escribimos todos los test de las funciones.
#
#       - functions.py  Aqui escribimos todas las funciones relacionadas con el
#                       funcionamiento del programa. Luego son agrupadas en el 
#                       main.py.
#       
#       - show.py       Se encuentran todas las funciones que se encargan de 
#                       mostrar mensajes importantes o informacion por pantalla.
#
#       - arguments.py  Se encuentran todas las funciones que se encargan de verificar
#                       que todos los argumentos pasados por el jugador sean correctos.
# 
#  
# - DISENIO DE DATOS Y RESOLUCION:
#                                  A continuacion, explicaremos un poco como se diseniaron los 
#   los distintos tipos de datos y como trabajamos con la resolucion.
#   
#   
#       - Casillas:
#                   el tablero utiliza letras y numeros para representar las coordenadas de una 
#       casilla. Esto lo normalizamos realizando una asociacion entre las coordenadas reales en
#       en el tablero, con una tupla de enteros. Las columnas de la A a la H las asociamos con
#       numeros del 0 al 7, y con las filas del 1 al 8, tambien las asociamos con numeros del 
#       1 al 7. Algunos ejemplos de estas asociaciones serian:
#
#           "A1" -> (0,0)
#           "H8" -> (7,7)
#           "B3" -> (1,2)
#
#       - Tablero:
#                 Al tablero lo representamos de manera implicita. Utilizaremos un diccionario
#       de conjuntos y solo guardaremos aquellas fichas que se encuentren ocupadas. Las que no
#       se encuentren ocupadas, no las incluiremos en dicho diccionario.
#
#       - Analisis de archivo leido:
#                                   Como estamos suponiendo que el archivo pasado por linea de 
#       comandos es un archivo correcto, no verificamos la informacion que posee dentro. Lo 
#       consideramos correcto ya que fue generado por el programa en C.