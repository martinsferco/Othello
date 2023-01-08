
def mostrarTablero(fichasJugadas,tamTablero):
    """
    mostrarTablero :: dict(str:set((int,int))) int -> None

    Dadas las fichas jugadas de cada color y el tamaño del tablero,
    la función imprime en pantalla una representación del mismo.
    """
    
    fichaBlanca = "⚪"
    fichaNegra = "⚫"

    #Imprimimos el tablero

    print("\n\n    A  B  C  D  E  F  G  H",end = "")

    for fila in range(tamTablero):
        
        print("\n   -------------------------")

        print(f' {fila + 1} ',end = "")

        for columna in range(tamTablero):

            if (columna,fila) in fichasJugadas["B"]:
                print(f'|{fichaBlanca}',end = "")

            elif (columna,fila) in fichasJugadas["N"]:
                print(f'|{fichaNegra}',end = "")
             
            else:
                print('|  ',end = "")

        print('|',end = "")

    print("\n   -------------------------")
