/*
 * LedOnOff.h
 *
 *  Created on: 21 abr. 2020
 *      Author: joseluis
 */

#ifndef LEDONOFF_H_
#define LEDONOFF_H_

#include "Led.h"

class Led_OnOff: public Led {
public:
	Led_OnOff(short unsigned puerto, short unsigned bit);
	virtual ~Led_OnOff();

	void encender();
	void apagar();
	virtual void invertir();
	virtual bool esta_encendido() { return this->encendido; };

private:
	short unsigned int nPuerto;
	short unsigned int nBit;
};

#endif /* LEDONOFF_H_ */
