/*
 * LedPWM.h
 *
 *  Created on: 22 abr. 2020
 *      Author: joseluis
 */

#ifndef LEDPWM_H_
#define LEDPWM_H_

#include "Led.h"
#include "PWM.h"

class Led_PWM: public Led {
public:
	Led_PWM( PWM * p );
	virtual ~Led_PWM();
	virtual void invertir();
	virtual void establecer_ciclo_trabajo( unsigned short int ct );
	virtual bool esta_encendido();

private:
	PWM * pPwm;

};

#endif /* LEDPWM_H_ */
