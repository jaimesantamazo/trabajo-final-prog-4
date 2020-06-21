/*
 * Puntuacion.cpp
 *
 *  Created on: 17 jun. 2020
 *      Author: jaime
 */

#include "Puntuacion.h"
#include <string.h>
#include <iostream>
using namespace std;

Puntuacion::Puntuacion(const char* usuario, const char* puntos){
	this->usuario = new char[strlen(usuario)+1];
		strcpy(this->usuario,usuario);
	this->puntos = new char[strlen(puntos)+1];
		strcpy(this->puntos,puntos);
}
Puntuacion::~Puntuacion(){
	delete[]usuario;

}
Puntuacion::Puntuacion(const Puntuacion &P){
	this->usuario = new char[strlen(P.usuario)+1];
		strcpy(this->usuario,P.usuario);
	this->puntos = new char[strlen(P.puntos)+1];
		strcpy(this->puntos,P.puntos);
}
Puntuacion::Puntuacion(){
	this->usuario = "";
	this->puntos = "";
}
char* Puntuacion::getusuario() const{
	return this->usuario;
}
char* Puntuacion::getpuntos() const{
	return this->puntos;
}

