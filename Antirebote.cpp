#include "Antirebote.h"

Antirebote::Antirebote(unsigned long tRebote, int n_Pin){
    this -> tConsigna = tConsigna;
    lEstado = 0;
    tInicial = 0;
    salidaEnclavamiento = 0;
    this -> n_Pin = n_Pin;
}

bool Antirebote::pulsadorEnclavamiento(){

    pEstado=digitalRead(n_Pin);

    if (pEstado != lEstado){
        if(millis() >= tInicial + tConsigna){
            lEstado = pEstado;
            salidaEnclavamiento = !salidaEnclavamiento;
        }
    }

    else {
        tInicial = millis();
    }

    return salidaEnclavamiento;
}

bool Antirebote::interruptor(){

    pEstado=digitalRead(n_Pin);

    if (pEstado != lEstado){
        if (millis() >= tInicial + tConsigna){
            lEstado = pEstado;
        } 
    }
    else {
        tInicial = millis();
    } 
    return lEstado;
}