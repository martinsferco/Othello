# Trabajo Practico Final - R123 Programacion II 2022
Este trabajo fue como entrega final para la materia Programacion II de la Licenciatura en Ciencias de la Computacion de la Facultad de Ciencias Exactas, Ingenieria y Agrimensura de la Universidad Nacional de Rosario.

El trabajo consta de dos partes:
- La parte C consiste analizar las jugadas que se encuentran en un archivo .txt e ir generando los cambios adecuados.
- La parte en Python, toma la continuacion de la partida en C, y hace que el jugador se enfrente a la maquina en distintos niveles de dificultad.

---

### Ejecucion programa C
Para compilar el programa debemos entrar a la carpeta C/ que se encuentra en la raiz del proyecto. Luego abrimos una terminal dentro de dicha carpeta y ejecutamos el siguiente comando:

    $ gcc main.c functions.c -o othello

Una vez compilado, ejecutamos el programa con el siguiente comando:

    $ ./othello ../partidas/<nombreArchivo> 

en donde "nombreArchivo" debe colocarse el nombre de archivo de juego que 
quieras procesar (con la extension .txt), que se encuentra dentro de la
carpeta partidas/. En el caso que se quiera utilizar otra carpeta con
archivos de prueba deberiamos utilizar el siguiente comando:

    $ ./othello ../<tuCarpeta>/<nombreArchivo> 

reeemplazando "tuCarpeta" por el nombre de la carpeta que hayas agregado
en la raiz del proyecto.

---

### Ejecucion tests C
Para compilar los archivos de tests, primero debemos entrar a la carpeta C/ que se encuentra en la raiz del del proyecto. Luego abrimos una terminal dentro de dicha carpeta y ejecutamos el siguiente comando:

    $ gcc test.c functions.c -o tests

Una vez compilado, ejecutamos los test con el siguiente comando:

    $ ./tests

---

### Ejecucion programa Python
Para ejecutar el programa, debemos abrir una consola dentro de la carpeta Python/, la cual se encuentra en la raiz del proyecto. Luego, ejecutamos el siguiente comando:

    $ python3 main.py ../generados/<nombreArchivo> <colorJugador> <nivelDificultad>
        
en donde todos los argumentos deben estar separados por un espacio. En el caso de que estemos en Windows, debemos utilizar el siguiente comando:

    $python main.py ../generados/<nombreArchivo> <colorJugador> <nivelDificultad>

Cada uno de los argumentos nombreArchivo, turnoJugador y nivelDificultad los debera elegir el
usuario y pueden tomar los siguientes valores:
 - "nombreArchivo": Es el nombre del archivo del cual vamos a empezar la partida. Tiene que incluir la terminacion .txt y debe estar dentro de la carpeta generados/.

- "colorJugador": Es el color del jugador, y puede ser B o N. 

- "nivelDificultad": Es el nivel de dificultad de la maquina y puede ser 0 o 1.


En el caso de que se quiera utilizar otra carpeta con archivos generados, se tiene que incluir dicha carpeta en la raiz del proyecto y se debe ejecutar el comando de la siguiente manera:

    $ python3 main.py ../<tuCarpeta>/<nombreArchivo> <colorJugador> <nivelDificultad>

reemplazando "tuCarpeta" por el nombre de la carpeta que hayas incluido.

---

### Ejecucion tests Python
Para ejecutar los tests de las funciones del programa, debemos abrir una terminal en la carpeta Python/, la cual se encuentra en la raiz del proyecto. A continuacion, ejecutamos el siguiente comando.

    $ python3 -m pytest test.py

En el caso de que estemos en Windos, debemos utilizar el siguiente comando:

    $python -m pytest test.py
---