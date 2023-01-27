from functions import *
from arguments import *


# Tests de funciones de arguments.py

def test_verificarExistenciaArchivo():
    pass
    # Ver como podemos testear esto en la carpeta de asserts
    assert verificarExistenciaArchivo('../generados/initialGame.txt')
    assert not verificarExistenciaArchivo('../generados/juego.txt')



def test_verificarNivelDificultad():
    
    assert verificarNivelDificultad('1')
    assert verificarNivelDificultad('0')
    assert not verificarNivelDificultad('2')



def test_verificarColorJugador():

    assert verificarColorJugador('N')
    assert verificarColorJugador('B')
    assert verificarColorJugador('b')
    assert verificarColorJugador('n')
    assert not verificarColorJugador('R')



def test_verificarArgumentos():

    assert not verificarArgumentos('../generados/initialGame.txt', 'B', '2')
    assert not verificarArgumentos('../generados/initialGame.txt', 'R', '1')
    assert not verificarArgumentos('../generados/juego.txt', 'B', '2')
    assert verificarArgumentos('../generados/initialGame.txt', 'b', '1')
    assert verificarArgumentos('../generados/initialGame.txt', 'N', '0')


    
# Tests de funciones de functions.py

def test_lecturaArchivoJuego():
    
    assert lecturaArchivoJuego('../generados/initialGame.txt') == ({'B':{(4,4),(3,3)},'N':{(3,4),(4,3)}},'N')



def test_partidaTerminada():

    listaJugadas1 = [(2,2),(3,2),(-1,1)]
    listaJugadas2 = [(2,2),(3,2),(-1,1),(-1,-1)]
    listaJugadas3 = [(-1,-1)]

    pass



def test_dobleSalto():

    listaJugadas1 = [(2,2),(3,2),(-1,-1)]
    listaJugadas2 = [(2,2),(3,2),(-1,-1),(-1,-1)]

    assert not dobleSalto(listaJugadas1)
    assert dobleSalto(listaJugadas2)



def test_jugadaJugadoVerifica():
    
    fichasJugadas1 = {'B':{(4,4),(3,3)},'N':{(3,4),(4,3)}}
    fichasJugadas2 = {'B':{(0,0)},'N':{(0,1),(1,0),(1,1)}}

    assert not jugadaJugadorVerifica("", fichasJugadas1, 'B', 8) 
    assert not jugadaJugadorVerifica("", fichasJugadas1, 'N', 8)
    assert jugadaJugadorVerifica("", fichasJugadas2, 'N', 8)
    
    assert not jugadaJugadorVerifica("AA", fichasJugadas1, 'B', 8)
    assert not jugadaJugadorVerifica("AB2", fichasJugadas1, 'B', 8)

    assert not jugadaJugadorVerifica("A9", fichasJugadas1, 'B', 8)
    assert not jugadaJugadorVerifica("Z1", fichasJugadas1, 'B', 8)

    assert not jugadaJugadorVerifica("D3", fichasJugadas1, 'B', 8)
    assert not jugadaJugadorVerifica("e4", fichasJugadas1, 'B', 8)

    assert not jugadaJugadorVerifica("A1", fichasJugadas1, 'B', 8)
    assert not jugadaJugadorVerifica("G8", fichasJugadas1, 'N', 8)

    assert jugadaJugadorVerifica("D6", fichasJugadas1, 'B', 8)
    assert jugadaJugadorVerifica("C4", fichasJugadas1, 'N', 8)
    


def test_jugadasMaximizadoras():
    
    posicionesPosibles1 = {(1,0):{(2,0),(3,0)},(4,0):{(1,3)}}
    posicionesPosibles2 = {(1,0):{(2,0),(3,0)},(4,0):{(1,3),(3,2)}}
    posicionesPosibles3 = {(1,0):{(2,0),(3,0)},(4,0):{(1,3)},(1,7):{(2,7),(3,7),(4,7)}}
    posicionesPosibles4 = {(1,0):{(2,0)},(4,0):{(1,3)},(1,7):{(3,7)}}

    assert jugadasMaximizadoras(posicionesPosibles1) == [(1,0)]
    assert jugadasMaximizadoras(posicionesPosibles2) == [(1,0),(4,0)]
    assert jugadasMaximizadoras(posicionesPosibles3) == [(1,7)]
    assert jugadasMaximizadoras(posicionesPosibles4) == [(1,0),(4,0),(1,7)]



def test_posicionesPermitidas():
    
    fichasJugadas = {'B':{(4,4),(3,3)},'N':{(3,4),(4,3)}}

    assert posicionesPermitidas('B',fichasJugadas,8) == {(4,2):{(4,3)},(2,4):{(3,4)},(3,5):{(3,4)},(5,3):{(4,3)}}
    assert posicionesPermitidas('N',fichasJugadas,8) == {(3,2):{(3,3)},(2,3):{(3,3)},(4,5):{(4,4)},(5,4):{(4,4)}}



def test_vecinasLibresFichasOpuestas():
    
    fichasJugadas1 = {'B':{(4,4),(3,3)},'N':{(3,4),(4,3)}}
    fichasJugadas2 = {'B':{(0,0)},'N':{(0,1),(1,0),(1,1)}}
    
    assert vecinasLibresFichasOpuestas('B',fichasJugadas1,8) == {(2,3),(2,4),(2,5),(3,5),(4,5),(5,2),(5,3),(5,4),(4,2),(3,2)}
    assert vecinasLibresFichasOpuestas('N',fichasJugadas1,8) == {(2,2),(2,3),(2,4),(3,5),(4,5),(5,5),(5,3),(5,4),(4,2),(3,2)} 
    assert vecinasLibresFichasOpuestas('N',fichasJugadas2,8) == set()



def test_vecinasLibres():
    
    fichasJugadas = {'B':{(4,4),(3,3)},'N':{(3,4),(4,3)}}

    assert vecinasLibres((4,4),fichasJugadas,8) == {(5,3),(5,4),(5,5),(3,5),(4,5)}
    assert vecinasLibres((3,4),fichasJugadas,8) == {(2,3),(2,4),(2,5),(3,5),(4,5)}
    assert vecinasLibres((0,0),fichasJugadas,8) == {(1,0),(1,1),(0,1)}
    assert vecinasLibres((4,0),fichasJugadas,8) == {(3,0),(3,1),(4,1),(5,0),(5,1)}



def test_fichasVolteadasJugada():
    
    fichas = {(2,2),(3,3),(5,5),(6,6),(2,6),(3,5),(5,3),(6,2),(2,4),(3,4),(5,4),(6,4),(4,2),(4,3),(4,5),(4,6)}

    fichasJugadas1 = {"B":{(1,1),(4,1),(7,1),(1,4),(1,7),(4,7),(7,4),(7,7)},"N":fichas}
    fichasJugadas2 = {"N":{(1,1),(4,1),(7,1),(1,4),(1,7),(4,7),(7,4),(7,7)},"B":fichas}

    fichasJugadas3 = {'B':{(0,6),(1,7),(1,6)},'N':{(0,5),(2,5),(2,7)}}

    assert fichasVolteadasJugada(fichasJugadas1,(4,4),'B',8) == fichas
    assert fichasVolteadasJugada(fichasJugadas2,(4,4),'N',8) == fichas
    assert fichasVolteadasJugada(fichasJugadas3,(0,7),'N',8) == {(0,6),(1,7),(1,6)}



def test_enRango():
    
    assert enRango((0,0),1,(1,0),8)
    assert enRango((0,0),1,(1,1),8)
    assert not enRango((0,0),-1,(1,1),8)
    assert not enRango((0,0),1,(1,-1),8)
    assert not enRango((4,0),1,(1,-1),8)
    assert enRango((4,4),-1,(1,1),8)
    assert enRango((7,7),-1,(1,1),8)
    assert enRango((6,3),1,(1,0),8)
    assert enRango((1,3),-1,(1,-1),8)



def test_actualizarFichasJugadas():

    # fichasJugadas, jugadaActual, fichasModificadas, turnoActual
    fichasJugadas = {'B':{(4,4),(3,3)},'N':{(3,4),(4,3)}}    
    assert actualizarFichasJugadas(fichasJugadas,(3,2),{(3,3)},'N') == {'B':{(4,4)},'N':{(3,3),(3,4),(4,3),(3,2)}}
    
    fichasJugadas = {'B':{(4,4),(3,3)},'N':{(3,4),(4,3)}}
    assert actualizarFichasJugadas(fichasJugadas,(5,3),{(4,3)},'B') == {'B':{(4,4),(3,3),(4,3),(5,3)},'N':{(3,4)}}



def test_ocupada():
    
    fichasJugadas = {'B':{(4,4),(3,3)},'N':{(3,4),(4,3)}}

    assert ocupada(fichasJugadas,(4,4))
    assert ocupada(fichasJugadas,(4,3))
    assert not ocupada(fichasJugadas,(0,0))



def test_verificarFormato():
    
    assert not verificarFormato("B23")
    assert not verificarFormato("AA2")
    assert not verificarFormato("22")
    assert not verificarFormato("AA")
    assert verificarFormato("A1")



def test_verificarRango():
    
    assert not verificarRango("A9")
    assert not verificarRango("Z2")
    assert verificarRango("B3")
    assert verificarRango("A1")    



def test_convertirCoordenadas():
    
    assert convertirCoordenadas("A1") == (0,0)
    assert convertirCoordenadas("H8") == (7,7)
    assert convertirCoordenadas("c4") == (2,3)
    assert convertirCoordenadas("e5") == (4,4)
    assert convertirCoordenadas("") == (-1,-1)



def test_reconvertirCoordenadas():

    assert reconvertirCoordenada((0,0)) == "A1"
    assert reconvertirCoordenada((7,7)) == "H8"



def test_turnoOpuesto():

    assert turnoOpuesto('B') == 'N'
    assert turnoOpuesto('N') == 'B'