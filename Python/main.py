from arguments import verificarArgumentos
from show import *
from functions import *
from os import system
from sys import argv
from time import sleep



def main(nombreArchivoJuego, colorJugador, nivelDificultad):

    tamTablero = 8

    # Primero verificamos que todos los argumentos pasados son corecctos
    if not verificarArgumentos(nombreArchivoJuego, colorJugador, nivelDificultad):        
        return

    # Leemos la informacion del archivo .txt generado por el programa de C
    fichasJugadas, turnoActual = lecturaArchivoJuego(nombreArchivoJuego)

    colorJugador = colorJugador.upper()
    colorMaquina = turnoOpuesto(colorJugador)
    
    cantidadFichasJugadas = len(fichasJugadas['N']) + len(fichasJugadas['B'])

    # Mostramos las condciones iniciales leidas del archivo
    mostrarTablero(fichasJugadas,tamTablero)
    mensajeInicio(nivelDificultad,colorJugador,colorMaquina,turnoActual)

    # Registraremos las jugadas para ver si se saltea dos veces el turno
    listaJugadas = []

    while not partidaTerminada(cantidadFichasJugadas,fichasJugadas,listaJugadas):

        # Vemos de quien es el turno
        if turnoActual == colorJugador:

            jugadaActual, fichasModificadas  = pedirJugadaJugador(colorJugador, fichasJugadas, tamTablero)
            
        else:

            sleep(1.5)
            system('clear')
            jugadaActual, fichasModificadas = realizarJugadaMaquina(colorMaquina, nivelDificultad, fichasJugadas, tamTablero)
        

        # Si no se salteo la jugada, generamos los cambios del tablero
        if jugadaActual != (-1,-1):

            fichasJugadas = actualizarFichasJugadas(fichasJugadas,jugadaActual,fichasModificadas,turnoActual)
            
            cantidadFichasJugadas += 1

        # Registramos la jugada
        listaJugadas.append(jugadaActual)

        mostrarTablero(fichasJugadas,tamTablero)

        # Cambiamos el turno de juego
        turnoActual = turnoOpuesto(turnoActual)


    # Mostramos el mensaje que determina el ganador del juego
    mensajeFinalJuego(fichasJugadas)




if __name__ == "__main__":

    # Vemos si se ingreso la cantidad correcta de argumentos
    if len(argv) == 4:

        nombreArchivoJuego = argv[1]
        colorJugador = argv[2]
        nivelDificultad = argv[3]
        
        main(nombreArchivoJuego, colorJugador, nivelDificultad)
    
    else:

        print("ERROR: Ha ingresado la cantidad incorrecta de argumentos. Finalizando programa...")