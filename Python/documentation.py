# _______________________________________________________________________
# LICENCIATURA EN CIENCIAS DE LA COMPUTACION - R123 Programacion II - 2022
# 
# Documentacion Trabajo Practico Final - Parte Python
# Alumno: Sferco Martin
# ________________________________________________________________________
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
# - EJECUCION DEL PROGRAMA:
#                           Para ejecutar el programa en Linux, primero tenemos que 
#   colocar el archivo que queremos abrir en la misma carpeta que main.py. Luego debemos 
#   abrir la terminal en la misma carpeta y ejecutar el siguiente comando:
#   
#           $ python3 main.py nombreArchivo colorJugador nivelDificultad
#           
#   en donde todos los argumentos deben estar separados por un espacio. Cada uno 
#   de los argumentos nombreArchivo, turnoJugador y nivelDificultad los debera elegir el
#   usuario y pueden tomar los siguientes valores:
#
#       - nombreArchivo       Es el nombre del archivo del cual vamos a empezar la partida.
#                             Tiene que incluir la terminacion .txt
#   
#       - colorJugador        Es el color del jugador, y puede ser B o N. 
#
#       - nivelDificultad     Es el nivel de dificultad de la maquina y puede ser 0 o 1.
#
#   En el caso de que estemos en Windows, debemos utilizar python en lugar de python3. 
#
# - EJECUCION DE TESTS:
#                       Para ejecutar los tests de las funciones del programa, debemos abrir
#   una terminal en la misma carpeta donde se encuentra el archivo test.py y ejecutar el 
#   siguiente comando:
#
#           $ python3 -m pytest test.py
