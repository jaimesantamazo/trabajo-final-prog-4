/*
 * Pregunta.cpp
 *
 *  Created on: 16 jun. 2020
 *      Author: jaime
 */

#include "Pregunta.h"
#include <string.h>
#include <iostream>
using namespace std;

Pregunta::Pregunta(const char* codigo,const char* pregunta,const char* respuesta1,const char* respuesta2,const char* respuesta3,const char* respuesta4,const char* respuestacorrecta){
	this->codigo = new char[strlen(codigo)+1];
		strcpy(this->codigo,codigo);
	this->pregunta = new char[strlen(pregunta)+1];
		strcpy(this->pregunta,pregunta);
	this->respuesta1 = new char[strlen(respuesta1)+1];
		strcpy(this->respuesta1,respuesta1);
	this->respuesta2 = new char[strlen(respuesta2)+1];
		strcpy(this->respuesta2,respuesta2);
	this->respuesta3 = new char[strlen(respuesta3)+1];
		strcpy(this->respuesta3,respuesta3);
	this->respuesta4 = new char[strlen(respuesta4)+1];
		strcpy(this->codigo,codigo);
	this->respuestacorrecta = new char[strlen(respuestacorrecta)+1];
		strcpy(this->respuestacorrecta,respuestacorrecta);
}
Pregunta::~Pregunta(){
	delete[]codigo;
	delete[]pregunta;
	delete[]respuesta1;
	delete[]respuesta2;
	delete[]respuesta3;
	delete[]respuesta4;
	delete[]respuestacorrecta;
}
Pregunta::Pregunta(const Pregunta &P){
	this->codigo = new char[strlen(P.codigo)+1];
			strcpy(this->codigo,P.codigo);
		this->pregunta = new char[strlen(P.pregunta)+1];
			strcpy(this->pregunta,P.pregunta);
		this->respuesta1 = new char[strlen(P.respuesta1)+1];
			strcpy(this->respuesta1,P.respuesta1);
		this->respuesta2 = new char[strlen(P.respuesta2)+1];
			strcpy(this->respuesta2,P.respuesta2);
		this->respuesta3 = new char[strlen(P.respuesta3)+1];
			strcpy(this->respuesta3,P.respuesta3);
		this->respuesta4 = new char[strlen(P.respuesta4)+1];
			strcpy(this->codigo,P.codigo);
		this->respuestacorrecta = new char[strlen(P.respuestacorrecta)+1];
			strcpy(this->respuestacorrecta,P.respuestacorrecta);
}
Pregunta::Pregunta(){
	this->codigo="";
	this->pregunta="";
	this->respuesta1="";
	this->respuesta2="";
	this->respuesta3="";
	this->respuesta4="";
	this->respuestacorrecta="";
}
char* Pregunta::getcodigo() const{
	return this->codigo;
}
char* Pregunta::getpregunta() const{
	return this->pregunta;
}
char* Pregunta::getrespuesta1() const{
	return this->respuesta1;
}
char* Pregunta::getrespuesta2() const{
	return this->respuesta2;
}
char* Pregunta::getrespuesta3() const{
	return this->respuesta3;
}
char* Pregunta::getrespuesta4() const{
	return this->respuesta4;
}
char* Pregunta::getrespuestacorrecta() const{
	return this->respuestacorrecta;
}
