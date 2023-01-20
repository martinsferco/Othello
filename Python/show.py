from time import sleep


def mostrarTablero(fichasJugadas,tamTablero):
    
    """
    mostrarTablero :: dict(str:set((int,int))) int -> None

    Dadas las fichas jugadas de cada color y el tamaño del tablero,
    la función imprime en pantalla una representación del mismo.
    """
    
    print("\n    A  B  C  D  E  F  G  H",end = "")

    for fila in range(tamTablero):
        
        print("\n   -------------------------")

        print(f' {fila + 1} ',end = "")

        for columna in range(tamTablero):

            if (columna,fila) in fichasJugadas["B"]:
                print('| B',end = "")

            elif (columna,fila) in fichasJugadas["N"]:
                print('| N',end = "")
             
            else:
                print('|  ',end = "")

        print('|',end = "")

    print("\n   -------------------------\n")




def mensajeFinalJuego(fichasJugadas):
    
    """
    mensajeFinalJuego :: str dict(str:set((int,int))) str -> None

    Dada las condiciones de la última jugada, las fichas jugadas, y el turno
    nos muestra un mensaje adecuado relacionado a la terminación del juego.
    """
    
    print("EL JUEGO HA TERMINADO !\n")

    cantidadFichasBlancas = len(fichasJugadas["B"])
    cantidadFichasNegras = len(fichasJugadas["N"])
    cantidadFichasJugadas = cantidadFichasBlancas + cantidadFichasNegras
    

    # Analizamos los casos de finalizacion de la partida
    if cantidadFichasJugadas == 64:

        print("Se colocaron todas las fichas sobre el tablero.")

    else:

        if cantidadFichasBlancas == 0:
            print("El jugador blanco se quedó sin fichas.")

        elif cantidadFichasNegras == 0:
            print("El jugador negro se quedó sin fichas.")

        # Entonces hubo dos salto de turno seguidos, implica que termino la partida
        else:
            print("Los dos jugadores saltearon turno. No hay mas jugadas posibles.") 


    # Mostramos quien es el ganador
    mensajeSobreCantidadFichas(cantidadFichasBlancas,cantidadFichasNegras)




def mensajeSobreCantidadFichas(cantidadFichasBlancas,cantidadFichasNegras):
    
    """
    mensajeSobreCantidadFichas :: int int -> None

    Dadas las cantidades de fichas de cada uno de los colores, nos muestra un mensaje
    sobre quien gano la partida.
    """

    if cantidadFichasBlancas > cantidadFichasNegras:
        print("Ganó el jugador de las fichas blancas!")

    elif cantidadFichasBlancas < cantidadFichasNegras:
        print("Ganó el jugador de las fichas negras!")

    else:
        print("Los jugadores empataron!")    




def errorJugada(error):
    
    """
    errorJugada :: str -> None

    Nos indica en que jugada se produjo un error y nos proporciona
    información sobre el error.
    """

    if error == "salteo":
        print("ERROR JUGADA: Se salteó el turno cuando había jugadas posibles.\n")

    if error == "formato":
        print("ERROR JUGADA: La jugada no cumple con el formato estipulado.\n")

    if error == "rango":
        print("ERROR JUGADA: La jugada se sale fuera del rango del tablero.\n")

    if error == "ocupada":
        print("ERROR JUGADA: La jugada cae sobre una casilla ya ocupada.\n")

    if error == "imposible":
        print("ERROR JUGADA: La jugada no genera cambios en el tablero.\n")




def mensajeInicio(nivelDificultad, colorJugador, colorMaquina,turnoActual):

    """
    mensajeInicio :: int str -> None

    Nos muestra un mensaje de inicio antes de comenzar el juego.
    """ 

    print("__________________________________")
    print("# El jugador juega con el color:",colorJugador)
    print("# La maquina juega con el color:",colorMaquina)
    print("# El nivel de dificultad es:",nivelDificultad)
    print("# Inicia el color:",turnoActual)
    sleep(0.5)