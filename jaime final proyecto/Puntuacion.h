/*
 * Puntuacion.h
 *
 *  Created on: 17 jun. 2020
 *      Author: jaime
 */

#ifndef PUNTUACION_H_
#define PUNTUACION_H_

class Puntuacion{
private:
	char* usuario;
	char* puntos;

public:
	Puntuacion(const char* usuario,const char* puntos);

	Puntuacion(const Puntuacion &P);

	virtual~Puntuacion();

	Puntuacion();

	char* getusuario() const;
	char* getpuntos() const;
};



#endif /* PUNTUACION_H_ */
