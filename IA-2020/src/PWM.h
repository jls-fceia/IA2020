/*
 * PWM.h
 *
 *  Created on: 21 abr. 2020
 *      Author: joseluis
 */

#ifndef PWM_H_
#define PWM_H_
#include <chrono>
using namespace std::chrono;

class PWM {
public:
	PWM( int nro_canal, int peri );
	virtual ~PWM();

	virtual bool leerEstado();
	virtual void establecer_CT( const double ciclo );
	virtual unsigned short int leer_CT()const { return this->ciclo_de_trabajo; };

private:
	high_resolution_clock::time_point t0, t1;
	std::chrono::nanoseconds periodo;
	int periodo_ticks;

	double ciclo_de_trabajo;
	int ticks_alto;
};

#endif /* PWM_H_ */
