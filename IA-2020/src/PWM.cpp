/*
 * PWM.cpp
 *
 *  Created on: 21 abr. 2020
 *      Author: joseluis
 */

#include "PWM.h"

PWM::PWM( int nro_canal, int peri ) {
	this->ciclo_de_trabajo = 0;
	// Inicializar el temporizador del micro
	// ...
	this->t0 = high_resolution_clock::now();
	this->periodo = (std::chrono::nanoseconds) peri;
	this->periodo_ticks = duration_cast<nanoseconds>(this->periodo).count();
	this->ticks_alto = this->periodo_ticks * ( this->ciclo_de_trabajo / 100 );
	return;
}

PWM::~PWM() {
	// Liberar el timer del micro
}

bool PWM::leerEstado() {
	this->t1 = high_resolution_clock::now();
	long int dur = duration_cast<nanoseconds>( t1 - t0 ).count(); // nanosegundos desde el comienzo
	int este_periodo = dur % this->periodo_ticks;
	if( este_periodo <= this->ticks_alto )
		return true;

	return false;
}

void PWM::establecer_CT(double ciclo) {
	this->ciclo_de_trabajo = (ciclo < 100 ? ciclo : 100);
	this->ticks_alto = this->periodo_ticks * (this->ciclo_de_trabajo / 100);
	return;
}
