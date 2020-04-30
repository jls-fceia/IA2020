/*
 * LedOnOff.cpp
 *
 *  Created on: 21 abr. 2020
 *      Author: joseluis
 */

#include "LedOnOff.h"

Led_OnOff::Led_OnOff(short unsigned puerto, short unsigned bit)  {
	this->nPuerto = puerto;
	this->nBit = bit;
	this->encendido = false;
	return;
}

Led_OnOff::~Led_OnOff() {
	// TODO Auto-generated destructor stub
}

void Led_OnOff::encender() {
	this->encendido = true;
	return;
}

void Led_OnOff::apagar() {
	this->encendido = false;
	return;
}

void Led_OnOff::invertir() {
	this->encendido = ! this->encendido;
	return;
}
