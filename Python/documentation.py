# _______________________________________________________________________
# LICENCIATURA EN CIENCIAS DE LA COMPUTACION - R123 Programacion II - 2022
# 
# Documentacion Trabajo Practico Final - Parte Python
# Alumno: Sferco Martin
# ________________________________________________________________________
#
# 
# - EJECUCION DEL PROGRAMA:
#   
#       Para realizar la ejecucion del programa en python tenemos que tener
#   las siguientes consideraciones:
#        
#       - Debemos colocar los archivo de juego en la carpeta
#       - Para ejecutar el programa tenemos que ejecutar el siguiente programa
#
#           $ python3 main.py nombreArchivo turnoJugador nivelDificultad
#
#       Para ejecutar los test del programa, se tiene que ejecutar el siguiente
#   comado:
#
#           $ python3 -m pytest test.py
#
#
# - DIVISION DE ARCHIVOS:
#                        Dividimos la totalidad del programa en varios archivo
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
#
#
#
