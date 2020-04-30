/*
 * LedPWM.cpp
 *
 *  Created on: 22 abr. 2020
 *      Author: joseluis
 */

#include "LedPWM.h"

Led_PWM::Led_PWM( PWM * p ) {
	this->pPwm = p;

}

Led_PWM::~Led_PWM() {
	// TODO Auto-generated destructor stub
}

void Led_PWM::invertir() {
	if (this->pPwm->leerEstado() == true )
		this->encendido = true;
	else
		this->encendido = false;

	this->pPwm->establecer_CT( 100 - this->pPwm->leer_CT() );

	this->encendido = !this->encendido;
	return;
}

void Led_PWM::establecer_ciclo_trabajo(unsigned short int ct) {
	this->pPwm->establecer_CT( ct );
	this->encendido = (ct > 0U );
	return;
}

bool Led_PWM::esta_encendido() {
	if (this->pPwm->leerEstado() == true )
		this->encendido = true;
	else
		this->encendido = false;

	return this->encendido;
}
