from show import errorJugada
from random import randrange



def lecturaArchivoJuego(nombreArchivoJuego):
    
    """
    lecturaArchivoJuego :: str -> dict(str: set(int,int)) str

    Dado el nombre de un archivo de juego, abre el archivo correspondiente
    y nos devuelve una estructura de datos con la informacion de las fichas
    jugadas de cada uno de los colores y el color de a quien le toca jugar
    en la siguiente jugada.
    """

    print("Abriendo el archivo de juego...")
    archivoJuego = open(nombreArchivoJuego, 'r')

    # Inicializamos la estructura donde guardaremos las fichas jugadas
    fichasJugadas = {'B': set(), 'N': set()}

    coordenadaFila = 0 

    while coordenadaFila < 8:

        linea = archivoJuego.readline().upper()

        coordenadaColumna = 0

        while coordenadaColumna < 8:

            if linea[coordenadaColumna] == 'B':
                fichasJugadas['B'].update({(coordenadaColumna,coordenadaFila)})

            if linea[coordenadaColumna] == 'N':
                fichasJugadas['N'].update({(coordenadaColumna,coordenadaFila)})

            coordenadaColumna += 1

        coordenadaFila += 1

    # Leemos la ultima linea del archivo
    colorJugador = archivoJuego.read(1).upper()

    archivoJuego.close() 

    return fichasJugadas,colorJugador




def partidaTerminada(cantidadFichasJugadas,fichasJugadas,listaJugadas):
    
    """
    partidaTerminada :: int dict(str:set((int,int))) -> bool

    Dada las fichas jugadas, la cantidad de las mismas y la lista de jugadas,
    determina si la partida ha terminado o si es posible continuar.
    """

    if cantidadFichasJugadas == 64:
        return True

    if len(fichasJugadas['N']) == 0:
        return True

    if len(fichasJugadas['B']) == 0:
        return True

    if len(listaJugadas) >= 2 and dobleSalto(listaJugadas):
        return True

    return False




def dobleSalto(listaJugadas):
    
    """
    dobleSalto :: list((int,int)) -> bool

    Dada la lista de jugadas pasadas, nos determina si las dos ultimas
    jugadas han sido salto de turno.
    """

    return listaJugadas[-1] == listaJugadas[-2]




def pedirJugadaJugador(colorJugador, fichasJugadas, tamTablero):
    
    """
    pedirJugadaJugador :: str dict(str:set((int,int))) int -> (int,int) set((int,int))

    Esta funcion toma el color del jugador, las fichas jugadas y el tamanio
    del tablero, y se encarga de devolvernos una jugada valida por parte del
    jugador.
    """
    
    print("TURNO DEL JUGADOR...")

    jugadaJugador = input("Ingrese la jugada que quiere realizar: ").upper()
    
    while not jugadaJugadorVerifica(jugadaJugador,fichasJugadas, colorJugador, tamTablero):

        jugadaJugador = input("Ingrese nuevamente la jugada que quiere realizar: ").upper()
        
        
    # Si la jugada verifica, la convertimos a la tupla de coordenadas y la retornamos
    jugadaJugador = convertirCoordenadas(jugadaJugador)
    
    # Devolvemos la fichas jugadas y las posiciones que modifica
    return jugadaJugador, fichasVolteadasJugada(fichasJugadas, jugadaJugador, colorJugador, tamTablero)




def jugadaJugadorVerifica(jugadaJugador, fichasJugadas, colorJugador, tamTablero):

    """
    jugadaJugadorVerifica :: str dict(str:set((int,int))) str int -> bool

    Esta funcion toma la jugada que nos proporciona el jugador, y nos devuelve un
    booleano de acuerdo si la jugada es o no valida.
    """

    # Cuando la jugada es un Salto de turno
    if jugadaJugador == '': 
        
        # Verificamos que sea correcto saltar el turno
        if posicionesPermitidas(colorJugador, fichasJugadas, tamTablero) != {}:
            
            errorJugada("salteo")
            return False

        return True


    # Verificamos que cumpla el formato
    if not verificarFormato(jugadaJugador):
        errorJugada("formato")
        return False

    # Verificamos que se encuentre dentro del rango
    if not verificarRango(jugadaJugador):
        errorJugada("rango")
        return False
    
    jugadaJugador = convertirCoordenadas(jugadaJugador)
        
    # Vemos si la casilla se encuentra ocupada
    if ocupada(fichasJugadas,jugadaJugador):
        errorJugada("ocupada")
        return False

    # Vemos si genera cambios en el tablero
    if fichasVolteadasJugada(fichasJugadas, jugadaJugador, colorJugador, tamTablero) == set():
        errorJugada("imposible")
        return False

    return True




def realizarJugadaMaquina(colorMaquina, nivelDificultad, fichasJugadas, tamTablero):

    """
    realizarJugadaMaquina :: str str dict(str:set((int,int))) int -> (int,int)

    Esta funcion toma el color de ficha de la maquina y el nivel
    de dificultad que se eligio, y se encarga de devolver la jugada
    realizada por la maquina.
    """

    print("TURNO DE LA MAQUINA...")
    print("Eligiendo jugada maximizadora...")    
    # Vemos todas las jugadas posibles
    posicionesPosibles = posicionesPermitidas(colorMaquina, fichasJugadas, tamTablero)

    # Si no hay jugadas posibles, saltea el turno
    if posicionesPosibles == {}:
        return (-1,-1), set()

    if nivelDificultad == '0':

        coordenadas = list(posicionesPosibles.keys())

    else:
        # Tomamos solo las posiciones que maximizan cantidad fichas

        coordenadas = jugadasMaximizadoras(posicionesPosibles)
        
    # Elegimos una al azar
    jugadaElegida = coordenadas[randrange(0,len(coordenadas))]

    return jugadaElegida, posicionesPosibles[jugadaElegida]




def jugadasMaximizadoras(posicionesPosibles):
    
    """
    jugadasMaximizadoras :: dict((int,int):set((int,int))) -> list((int,int))

    Dado el diccionario de todas las jugadas posibles, con las fichas que afectan, nos devuelve
    una lista de tuplas que representa todas las jugadas que generan el mayor numero de cambios.
    """

    listaJugadasMaximizadoras = []

    for coordenada in posicionesPosibles:

        cantidadFichasVolteadas = len(posicionesPosibles[coordenada])
        
        # Si esta vacio consideramos el primer elemento como maximizaodr
        if listaJugadasMaximizadoras == []:

            listaJugadasMaximizadoras = [coordenada]
            maximaCantidadFichasVolteadas = cantidadFichasVolteadas

        # Si tiene la misma cantidad de fichas volteadas
        elif cantidadFichasVolteadas == maximaCantidadFichasVolteadas:

            listaJugadasMaximizadoras.append(coordenada)

        # Si encontramos una nueva jugada maximizadora
        elif cantidadFichasVolteadas > maximaCantidadFichasVolteadas:       

            listaJugadasMaximizadoras = [coordenada]
            maximaCantidadFichasVolteadas = cantidadFichasVolteadas
               
    return listaJugadasMaximizadoras




def posicionesPermitidas(turnoActual, fichasJugadas, tamTablero):

    """
    posicionesPermitidas :: str dict(str:set((int,int))) int -> dict((int,int):set((int,int)))

    Dado el turno actual, las fichas que ya se colocaron en el tablero y su tamaño, 
    nos devuelve un diccionarion en donde las claves son las coordenadas de las posiciones
    permitidas y los valores son un conjunto de tuplas que representan las fichas que fueron 
    volteadas. 
    En caso de que no exista una casilla permitida, el diccionario que se devuelve es vacío.
    """

    posicionesValidas = {}

    vecinasLibresColorOpuesto = vecinasLibresFichasOpuestas(turnoActual,fichasJugadas,tamTablero)
 
    for coordenada in vecinasLibresColorOpuesto:

        fichasModificadas = fichasVolteadasJugada(fichasJugadas, coordenada, turnoActual, tamTablero)

        if fichasModificadas != set():

            posicionesValidas[coordenada] = fichasModificadas

    return posicionesValidas




def vecinasLibresFichasOpuestas(turnoActual, fichasJugadas, tamTablero):

    """
    vecinasLibresFichaOpuesta :: str dict(str:set((int,int))) int -> set((int,int))

    Dado el turno actual, las fichas ya colocadas y el tamaño del tablero, nos devuelve un conjunto
    con todas las casillas que son adyacentes a una ficha del color opuesto.
    """

    colorOpuesto = turnoOpuesto(turnoActual)

    vecinasFichasOpuestas = set()

    for coordenada in fichasJugadas[colorOpuesto]:

        vecinasFichasOpuestas.update(vecinasLibres(coordenada,fichasJugadas,tamTablero))
        
    return vecinasFichasOpuestas




def vecinasLibres(coordenada, fichasJugadas, tamTablero):

    """
    vecinasLibres :: (int,int) dict(str:set((int,int))) int-> set((int,int))

    Dada una coordenada de ficha, las fichas jugadas en el tablero y el tamaño del mismo,
    nos devuelve un conjunto con todas las casillas adyacantes libres a dicha ficha.
    """

    vecinasDesocupadas = set()

    columna,fila = coordenada

    for x in range(columna-1,columna+2):

        for y in range(fila-1,fila+2):

            if (0 <= x <= (tamTablero - 1)) and (0 <= y <= (tamTablero - 1)) and not ocupada(fichasJugadas,(x,y)):

                vecinasDesocupadas.update([(x,y)])
 
    # Eliminamos la propia casilla
    vecinasDesocupadas.discard(coordenada)

    return vecinasDesocupadas




def fichasVolteadasJugada(fichasJugadas, jugadaRealizada, turnoActual, tamTablero):
    
    """
    fichasVolteadasJugada :: dict(str:set((int,int))) (int,int) str int -> set((int,int))
    
    Dadas las fichas jugadas, la coordenada donde se coloca la ficha, el turno en el que estamos,
    y el tamano del tablero, nos devuelve un conjunto de tuplas que representan todas las fichas
     que se dieron vuelta gracias a la jugada realizada.
    
    En caso de que no modifique ninguna fichas, nos devuelve un conjunto vacio.
    """

    fichasVolteadas = set()

    # Vemos si se salteo el turno
    if jugadaRealizada == (-1,-1): return fichasVolteadas

    # Definimos todas la direcciones en donde vamos a buscar fichas volteadas
    vectoresDireccion = [(1,0),(0,1),(1,-1),(1,1)]

    # Definimos los dos sentidos posibles para cada una de las direcciones
    sentidosDireccion = [1,-1]

    columnaJugada, filaJugada = jugadaRealizada

    colorOpuesto = turnoOpuesto(turnoActual)

    # Iteramos por cada una de las direcciones
    for direccion in vectoresDireccion:

        # Iteramos por cada uno de los sentidos
        for sentido in sentidosDireccion:
            
            # Nos comenzamos a mover en dicha direccion y sentido
            indiceX = columnaJugada + sentido * direccion[0]
            indiceY = filaJugada + sentido * direccion[1]

            casilla = (indiceX, indiceY)

            # Lista de fichas del otro color encontradas en esa direccion y sentido
            fichasColorOpuesto = []
        
            while enRango(casilla, sentido, direccion, tamTablero) and casilla in fichasJugadas[colorOpuesto]:

                fichasColorOpuesto.append(casilla)

                # Si encontramos una ficha del color actual que ecierre a todas las otras del color opuesto
                if (indiceX + sentido * direccion[0], indiceY + sentido * direccion[1]) in fichasJugadas[turnoActual]:
                    
                    fichasVolteadas.update(fichasColorOpuesto)

                # Nos seguimos moviendo en esa direccion y sentido
                indiceX += sentido * direccion[0]
                indiceY += sentido * direccion[1]

                casilla = (indiceX, indiceY)

    return fichasVolteadas




def enRango(casilla, sentido, direccion, tamTablero):

    """
    enRango :: (int,int) int (int,int) int -> bool

    Dada la casilla donde nos encontramos, el sentido de movimiento, y 
    el tamanio del tablero, nos determina si nos encontramos dentro
    del rango de verificacion.
    """

    indiceX, indiceY = casilla

    minimo = 1
    maximo = (tamTablero - 1 ) - minimo

    # Definimos el desplazamiento en esa direccion y sentido en la que estamos
    # verificando si volteamos alguna ficha 
    desplazamientoX = sentido * direccion[0]
    desplazamientoY = sentido * direccion[1]


    if desplazamientoX != 0:
        
        enRangoX = indiceX <= maximo if desplazamientoX == 1 else indiceX >= minimo
    
    else: enRangoX = True

    
    if desplazamientoY != 0: 

        enRangoY = indiceY <= maximo if desplazamientoY == 1 else indiceY >= minimo
    
    else: enRangoY = True


    return enRangoX and enRangoY




def actualizarFichasJugadas(fichasJugadas, jugadaActual, fichasModificadas, turnoActual):

    """
    actualizarFichasJugadas :: dict(str:set((int,int))) (int,int) set((int,int)) str -> dic(str:set((int,int)))

    Dada las fichas jugadas, la jugada que se realizo, las fichas que se modificaron gracias a esa jugada
    y el turnoa actual, nos devuelve las fichas jugadas luega de la modificacion. 
    """

    colorTurnoOpuesto = turnoOpuesto(turnoActual)

    for ficha in fichasModificadas:

        fichasJugadas[turnoActual].update([ficha])
        fichasJugadas[colorTurnoOpuesto].discard(ficha)

    # Agregamos la jugada que se realizo
    fichasJugadas[turnoActual].update([jugadaActual])
   
    return fichasJugadas




def ocupada(fichasJugadas, jugada):

    """
    ocupada :: dict(str:set((int,int))) (int,int) -> bool
    
    Dada las fichas jugadas y una jugada que se quiere realizar, nos indica
    si la casilla en donde se quiere colocar la ficha se encuentra ocupada o no.
    """
    
    return (jugada in fichasJugadas['B']) or (jugada in fichasJugadas['N'])




def verificarFormato(jugada):
    
    """
    verificacionFormato :: str -> bool

    La función toma una jugada realizada y 
    nos determina si tiene como primer valor un string y un número
    como segundo. También verifica que dicho jugda, tenga exactamente
    una longitud de dos.
    """

    if len(jugada) != 2: # No verifica que tenga dos coordenadas 
        return False
    
    columna, fila = jugada[0], jugada[1]
        
    if not columna.isalpha(): # No verifica que la columna sea una letra
        return False

    if not fila.isdigit(): # No verifica que la fila sea un número
        return False

    return True




def verificarRango(jugada):

    """
    verificacionRango :: str -> bool

    Dada una jugada que no sea un salto de turno,
    nos determina si dicha jugdada se encuentra dentro de los límites del tablero.
    """
    
    columnas = ['A','B','C','D','E','F','G','H']

    columna = jugada[0].upper()
    fila = int(jugada[1])

    return (columna in columnas) and (1 <= fila <= 8)



 
def convertirCoordenadas(jugada):
    
    """
    convertirCoordenada :: str -> (int,int)

    Dada una jugada, la convertimos en la coordenada equivalente con la que trabajaremos:
    - A las letras de la A a la H, las relacionamos con los números
      del 0 al 7. - A los números del 1 al 8, los relacionamos con los números del 0 al 7.
    En el caso que nos encontremos con un salto de jugada, la asociaremos con la coordenada
    (-1,-1).
    """
    
    if jugada == '': return (-1,-1)

    columnas = ['A','B','C','D','E','F','G','H']

    columna = jugada[0].upper()
    fila = int(jugada[1])

    columnaEquivalente = columnas.index(columna)
    filaEquivalente = fila - 1

    return (columnaEquivalente,filaEquivalente)




def turnoOpuesto(turno):

    """
    turnoOpuesto :: str -> str

    Dado el turno actual del juego, nos devuelve el turno opuesto:
    Si recibe 'B' devuelve 'N'
    Si recibe 'N' devuelve 'B'
    """

    return 'N' if turno == 'B' else 'B'