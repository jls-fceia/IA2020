/*
 * Led.h
 *
 *  Created on: 21 abr. 2020
 *      Author: joseluis
 */

#ifndef LED_H_
#define LED_H_

class Led {
public:
	explicit Led();
	virtual ~Led();

	// Metodos
	virtual void invertir() = 0;
	virtual bool esta_encendido() = 0;

protected:
	bool encendido;
};

#endif /* LED_H_ */
