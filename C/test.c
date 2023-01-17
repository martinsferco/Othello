#include "test.h"



int main(){

    test_cambiarTurno();



}



void test_cambiarTurno(){

    assert(cambiarTurno('N') == 'B');
    assert(cambiarTurno('B') == 'N');

}