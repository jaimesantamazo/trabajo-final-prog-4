/*
 * Pregunta.h
 *
 *  Created on: 16 jun. 2020
 *      Author: jaime
 */

#ifndef PREGUNTA_H_
#define PREGUNTA_H_

class Pregunta{
private:
	char* codigo;
	char* pregunta;
	char* respuesta1;
	char* respuesta2;
	char* respuesta3;
	char* respuesta4;
	char* respuestacorrecta;

public:
	Pregunta(const char* codigo,const char* pregunta,const char* respuesta1,const char* respuesta2,const char* respuesta3,const char* respuesta4,const char* respuestacorrecta);

	Pregunta(const Pregunta &P);

	virtual ~Pregunta();

	Pregunta();

	char* getcodigo() const;
	char* getpregunta() const;
	char* getrespuesta1()const;
	char* getrespuesta2()const;
	char* getrespuesta3()const;
	char* getrespuesta4()const;
	char* getrespuestacorrecta()const;
};



#endif /* PREGUNTA_H_ */
