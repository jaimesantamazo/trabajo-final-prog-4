/*
 * Usuario.cpp
 *
 *  Created on: 16 jun. 2020
 *      Author: jaime
 */

#include "Usuario.h"
#include <string.h>
#include <iostream>
using namespace std;

Usuario::Usuario(const char *usuario, const char *clave, const char *nombre,const char *apellido, const char *edad, const char *email,const char *dir){
	this->usuario = new char[strlen(usuario)+1];
		strcpy(this->usuario,usuario);
	this->clave = new char[strlen(clave)+1];
		strcpy(this->clave,clave);
	this->nombre = new char[strlen(nombre)+1];
		strcpy(this->nombre,nombre);
	this->apellido = new char[strlen(apellido)+1];
		strcpy(this->apellido,apellido);
	this->edad = new char[strlen(edad)+1];
		strcpy(this->edad,edad);
	this->email = new char[strlen(email)+1];
		strcpy(this->email,email);
	this->dir = new char[strlen(dir)+1];
		strcpy(this->dir,dir);
}
Usuario::~Usuario(){
	delete[]usuario;
	delete[]clave;
	delete[]nombre;
	delete[]apellido;
	delete[]edad;
	delete[]email;
	delete[]dir;
}
Usuario::Usuario(const Usuario &U){
	this->usuario = new char[strlen(U.usuario)+1];
			strcpy(this->usuario,U.usuario);
		this->clave = new char[strlen(U.clave)+1];
			strcpy(this->clave,U.clave);
		this->nombre = new char[strlen(U.nombre)+1];
			strcpy(this->nombre,U.nombre);
		this->apellido = new char[strlen(U.apellido)+1];
			strcpy(this->apellido,U.apellido);
		this->edad = new char[strlen(U.edad)+1];
			strcpy(this->edad,U.edad);
		this->email = new char[strlen(U.email)+1];
			strcpy(this->email,U.email);
		this->dir = new char[strlen(U.dir)+1];
			strcpy(this->dir,U.dir);
}
Usuario::Usuario(){
	this->usuario= "";
	this->clave= "";
	this->nombre= "";
	this->apellido= "";
	this->edad= "";
	this->email= "";
	this->dir= "";
}
char* Usuario::getusuario() const{
	return this->usuario;
}
char* Usuario::getclave() const{
	return this->clave;
}
char* Usuario::getnombre() const{
	return this->nombre;
}
char* Usuario::getapellido() const{
	return this->apellido;
}
char* Usuario::getedad() const{
	return this->edad;
}
char* Usuario::getemail() const{
	return this->email;
}
char* Usuario::getdir() const{
	return this->dir;
}



