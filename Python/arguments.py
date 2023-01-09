def verificarExistenciaArchivo(nombre):

    """
    verificarExistenciaArchivo :: str -> bool

    Toma un string, y verifica si es posible abrir un archivo cuyo nombre
    sea el string dado como argumento.
    """

    try:
        open(nombre,'r')

    except:

        print("ERROR: No existe ningun archivo con el nombre pasado.")
        return False

    else:
        
        return True




def verificarNivelDificultad(nivelDificultad):
    
    """
    verificarNivelDificulad :: str -> bool
    
    Dado el nivel de dificultad pasado como argumento,
    verificamos que sea un nivel de dificultad correcto.
    """

    if nivelDificultad != '0' and nivelDificultad != '1':

        print("ERROR: El nivel de dificultad pasado como argumento es incorrecto.") 
        return False

    return True




def verificarColorJugador(colorJugador):

    """
    verificarColorJugador :: str -> bool

    Dado el color pasado como argumento, verificamos 
    que sea un color correcto.
    """
    
    if colorJugador != 'B' and colorJugador != 'N':
        
        print("ERROR: El color pasado como argumento es incorrecto.")
        return False

    return True




def verificarArgumentos(nombreArchivo, colorJugador, nivelDificultad):
    
    """
    verificarArgumentos :: str str str -> bool

    Dados los tres argumentos que se le deben pasar al programa, 
    verificamos que todos sean correctos.
    """

    return verificarExistenciaArchivo(nombreArchivo) and verificarNivelDificultad(nivelDificultad) and verificarColorJugador(colorJugador)