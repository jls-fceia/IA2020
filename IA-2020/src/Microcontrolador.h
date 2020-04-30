/*
 * Microcontrolador.h
 *
 *  Created on: 23/4/2020 ..
 *      Author: jose
 */

#ifndef MICROCONTROLADOR_H_
#define MICROCONTROLADOR_H_

#include <iostream>
#include <string>

#include "LedOnOff.h"
#include "LedPWM.h"
using namespace std;


typedef enum { TERMINAR, APAGAR_TODO, INVERTIR_TODO, APAGAR_ONOFF, ENCENDER_TODO, CAMBIAR_CT0, CAMBIAR_CT1,
	APAGAR_L0, ENCENDER_L0, APAGAR_L1, ENCENDER_L1 } Opciones;

class Microcontrolador {
public:
	Microcontrolador(string nombre);
	virtual ~Microcontrolador();

	int ejecutar();


private:
	Led * leds[4];
	PWM * pwms[2];
	int menu();
	void mostrarLeds();
	string nombre;
};

#endif /* MICROCONTROLADOR_H_ */
