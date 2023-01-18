from arguments import verificarArgumentos
from show import *
from functions import *
import sys
from time import sleep



def main(nombreArchivoJuego, colorJugador, nivelDificultad):

    tamTablero = 8

    # Primero verificamos que todos los argumentos pasados son corecctos
    if not verificarArgumentos(nombreArchivoJuego, colorJugador, nivelDificultad):
        
        print("Finalizando programa...")
        return

    # Leemos la informacion del archivo .txt generado por el programa de C
    fichasJugadas, turnoActual = lecturaArchivoJuego(nombreArchivoJuego)

    colorMaquina = turnoOpuesto(colorJugador)

    cantidadFichasJugadas = len(fichasJugadas['N']) + len(fichasJugadas['B'])

    # Mostramos las condciones iniciales
    mensajeInicio(nivelDificultad,colorJugador,colorMaquina,turnoActual)
    mostrarTablero(fichasJugadas,tamTablero)

    sleep(1)

    # Registraremos las jugadas, para ver si en algun momento los dos jugadores saltaron
    # el turno de manera consecutiva
    listaJugadas = []

    while not partidaTerminada(cantidadFichasJugadas,fichasJugadas,listaJugadas):

        # Vemos de quien es el turno
        if turnoActual == colorJugador:

            jugadaActual, fichasModificadas  = pedirJugadaJugador(colorJugador, fichasJugadas, tamTablero)
            # jugadaActual, fichasModificadas = realizarJugadaMaquina(colorJugador, nivelDificultad, fichasJugadas, tamTablero)            

        else:

            jugadaActual, fichasModificadas = realizarJugadaMaquina(colorMaquina, nivelDificultad, fichasJugadas, tamTablero)
        

        # Si no se salteo la jugada, generamos los cambios del tablero
        if jugadaActual != (-1,-1):

            fichasJugadas = actualizarFichasJugadas(fichasJugadas,jugadaActual,fichasModificadas,turnoActual)
            
            cantidadFichasJugadas += 1

        # Registramos la jugada
        listaJugadas.append(jugadaActual)

        # Mostramos el tablero despues de hacer la jugada
        mostrarTablero(fichasJugadas,tamTablero)

        # Cambiamos el turno de juego
        turnoActual = turnoOpuesto(turnoActual)


    # Mostramos el mensaje que determina el ganador del juego
    mensajeFinalJuego(fichasJugadas)




if __name__ == "__main__":

    # Vemos si se ingreso la cantidad correcta de argumentos
    if len(sys.argv) == 4:

        nombreArchivoJuego = sys.argv[1]
        colorJugador = sys.argv[2]
        nivelDificultad = sys.argv[3]
        
        main(nombreArchivoJuego, colorJugador, nivelDificultad)
    
    else:

        print("ERROR: Ha ingresado la cantidad incorrecta de argumentos. Finalizando programa...")



