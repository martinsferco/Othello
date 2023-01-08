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
    turnoOpuesto :: Str -> Str

    Dado el turno actual del juego, nos devuelve el turno opuesto:
    Si recibe 'B' devuelve 'N'
    Si recive 'N' devuelve 'B'
    """

    return 'N' if turno == 'B' else 'B'


def normalizarLectura(string):
    """
    normalizarLectura :: str -> str
    
    Dato 
    """
    
    return string.upper()

