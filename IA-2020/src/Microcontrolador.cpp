/*
 * Microcontrolador.cpp
 *
 *  Created on: 23/4/2020
 *      Author: jose
 */

#include "Microcontrolador.h"
using namespace std;

Microcontrolador::Microcontrolador( string nom ) {
	// Crear los objetos necesarios:
	// 2 Leds On-Off
	// 2 PWM
	// 2 Leds PWM
	this->leds[0] = new Led_OnOff( 2, 0);
	this->leds[1] = new Led_OnOff( 2, 1);
	this->pwms[0] = new PWM( 0, 50 );
	this->pwms[1] = new PWM( 1,  100 );
	this->leds[2] = new Led_PWM( this->pwms[0] );
	this->leds[3] = new Led_PWM( this->pwms[1] );
	this->nombre = nom;

}

Microcontrolador::~Microcontrolador() {
	// TODO Auto-generated destructor stub
}

int Microcontrolador::ejecutar() {
	int opcion;
	unsigned short int ct;

	cout << "\nSimulación de microcontrolador " << this->nombre << endl;

	for(;;){
		this->mostrarLeds();
		opcion = this->menu();
		switch( opcion ){
		case TERMINAR:
			cout << "\nFin de la simulación" << endl;
			return 0;

		case APAGAR_TODO:
			for( int i=0; i < 4; i++ )
				if( this->leds[i]->esta_encendido() )
					this->leds[i]->invertir();
			break;

		case INVERTIR_TODO:
			for( int i = 0; i < 4; i++ )
				this->leds[i]->invertir();

			break;

		case APAGAR_ONOFF:
			for( int i = 0; i < 2; i++ )
				if( this->leds[i]->esta_encendido())
					this->leds[i]->invertir();

			break;

		case ENCENDER_TODO:
			for( int i=0; i < 4; i++ )
				if( !(this->leds[i]->esta_encendido() ))
					this->leds[i]->invertir();

			break;

		case CAMBIAR_CT0:
			cout << "\nNuevo ciclo de trabajo para L2 (0~100%): ";
			cin >> ct;
			reinterpret_cast <Led_PWM *> (this->leds[2])->establecer_ciclo_trabajo(ct);

			break;

		case CAMBIAR_CT1:
			cout << "\nNuevo ciclo de trabajo para L3 (0~100%): ";
			cin >> ct;
			reinterpret_cast <Led_PWM *> (this->leds[3])->establecer_ciclo_trabajo(ct);

			break;

		case APAGAR_L0:
			if( this->leds[0]->esta_encendido())
				this->leds[0]->invertir();

			break;

		case ENCENDER_L0:
			if( !(this->leds[0]->esta_encendido()))
				this->leds[0]->invertir();

			break;

		case APAGAR_L1:
			if( this->leds[1]->esta_encendido())
				this->leds[1]->invertir();

			break;

		case ENCENDER_L1:
			if( !(this->leds[1]->esta_encendido()))
				this->leds[1]->invertir();

			break;
		}
	}
	return 0;
}

int Microcontrolador::menu() {
	int opc;

	cout << "Elija acción: " << endl;
	cout << "\t0 para terminar" << endl;
	cout << "\t1 para apagar todos los leds" << endl;
	cout << "\t2 para invertir el estado de los leds" << endl;
	cout << "\t3 para apagar L0 y L1" << endl;
	cout << "\t4 para encender todos los leds" << endl;
	cout << "\t5 para cambiar CT L2" << endl;
	cout << "\t6 para cambiar CT L3" << endl;
	cout << "\t7 para apagar L0" << endl;
	cout << "\t8 para encender L0" << endl;
	cout << "\t9 para apagar L1" << endl;
	cout << "\t10 para encender L1 " << endl;
	cin >> opc;
	return opc;
}

void Microcontrolador::mostrarLeds() {
	cout << "\nEstado leds:" << endl;
	for( int i = 0; i < 4; i++ ){
		cout << "Led" << i << ": ";
		if( this->leds[i]->esta_encendido())
			cout << "encendido";
		else
			cout << "apagado";
		cout << endl;
	}
	cout << "_____________________________________________" << endl;
	return;
}
