/*
Libreria para crear antirebotes
*/

#include "Arduino.h"

class Antirebote
{
private:
    /* data */
    bool lEstado;
    bool pEstado;
    bool salidaEnclavamiento;
    int n_Pin; //Se pone un int porque byte parece no existir en c++
    unsigned long tInicial;
    unsigned long tTranscurrido;
    unsigned long tConsigna;
public:
    //Constructor
    Antirebote(unsigned long tConsigna, int n_Pin);
    //Destructor
    Antirebote::~Antirebote();
    //Hace el antirebote para interruptor estado alto y bajo
    bool interruptor();
    //Hace el antirebote para pulsador flanco
    bool pulsador();
    bool pulsadorEnclavamiento();
};

