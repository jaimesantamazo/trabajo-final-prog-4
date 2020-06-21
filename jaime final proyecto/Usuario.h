/*
 * Usuario.h
 *
 *  Created on: 16 jun. 2020
 *      Author: jaime
 */

#ifndef USUARIO_H_
#define USUARIO_H_

class Usuario {

private:
	char *usuario;
	char *clave;
	char *nombre;
	char *apellido;
	char *edad;
	char *email;
	char *dir;

public:
	Usuario(const char *usuario, const char *clave, const char *nombre,const char *apellido, const char *edad, const char *email,const char *dir);

	Usuario(const Usuario &U);

	virtual ~Usuario();

	Usuario();

	char* getusuario() const;
	char* getclave() const;
	char* getnombre() const;
	char* getapellido() const;
	char* getedad() const;
	char* getemail() const;
	char* getdir() const;
};



#endif /* USUARIO_H_ */
