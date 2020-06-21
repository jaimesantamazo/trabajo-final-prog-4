
#include "Usuario.h"
#include "Pregunta.h"
#include "Puntuacion.h"
#include "sqlite3.h"
#include <iostream>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
using namespace std;

int menuprincipal(){
	int r=-1;
	cout << " _______________________________________________" << endl;
	cout << "|                                               |" << endl;
	cout << "|   QUIZ DE LEAGUE OF LEGENDS - MENU PRINCIPAL  |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|                                               |" << endl;
	cout << "|           0. Registro                         |" << endl;
	cout << "|           1. Inicio de Sesion                 |" << endl;
	cout << "|           2. Instrucciones                    |" << endl;
	cout << "|           3. Salir del quiz                   |" << endl;
	cout << "|_______________________________________________|" << endl;
	do{
		cout << "Elige una de estas opciones: ";
		cin>>r;
	}while((r<0)||(r>3));
	return r;
}

int menusecundario(){
	int r=-1;
	cout << " _______________________________________________" << endl;
	cout << "|                                               |" << endl;
	cout << "|       QUIZ DE LEAGUE OF LEGENDS - JUEGO       |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|                                               |" << endl;
	cout << "|           0. Empezar el quiz                  |" << endl;
	cout << "|           1. Administración de preguntas      |" << endl;
	cout << "|           2. Tabla de puntuaciones            |" << endl;
	cout << "|           3. Volver atras                     |" << endl;
	cout << "|_______________________________________________|" << endl;
	do{
		cout << "Elige una de estas opciones: ";
		cin>>r;
	}while((r<0)||(r>3));
	return r;
}

int menuadministracion(){
	int r=-1;
	cout << " _______________________________________________" << endl;
	cout << "|                                               |" << endl;
	cout << "|  QUIZ DE LEAGUE OF LEGENDS - ADMINISTRACION   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "|                                               |" << endl;
	cout << "|           0. Crear pregunta                   |" << endl;
	cout << "|           1. Borrar pregunta                  |" << endl;
	cout << "|           2. Visualizar preguntas             |" << endl;
	cout << "|           3. Volver atras                     |" << endl;
	cout << "|_______________________________________________|" << endl;
	do{
		cout << "Elige una de estas opciones: ";
		cin>>r;
	}while((r<0)||(r>3));
	return r;
}

void instrucciones(){
	cout << " _______________________________________________" << endl;
	cout << "|                                               |" << endl;
	cout << "|   QUIZ DE LEAGUE OF LEGENDS - INSTRUCCIONES   |" << endl;
	cout << "|_______________________________________________|" << endl;
	cout << "ESTE ES EL QUIZ DE EL JUEGO LEAGUE OF LEGENDS " << endl;
	cout << "TE APARECERAN UNAS PREGUNTAS SOBRE EL JUEGO "<< endl;
	cout << "Y TENDRAS QUE RESPONDERLAS."<< endl;
	cout << "SI FALLAS UNA DE LAS PREGUNTAS AUTOMATICAMENTE SE ACABA LA PARTIDA "<< endl;
	cout << "Y SE GUARDA TU PUNTUACION EN LA TABLA DE PUNTUACIONES." << endl;
	cout << "PARA ACCEDER AL JUEGO ES NECESARIO REGISTRARSE Y LOGGEASE. "<< endl;
	cout << "SI ECHAS EN FALTA ALGUN TEMA O PREGUNTA SOBRE EL JUEGO PODRAS" << endl;
	cout << "AÑADIRLA O BORRAR ALGUNA SI NO TE PARECE INTERESANTE." << endl;
	cout << "BUENA SUERTE EN EL QUIZ, LA NECESITARAS ;)" << endl;
	cout << endl;
	system("PAUSE");
}

int tablapreguntas(sqlite3 *bd){

	char sql[]="create table preguntas(codigo NVARCHAR(5) primary key,pregunta NVARCHAR(100),respuesta1 NVARCHAR(30),respuesta2 NVARCHAR(30), respuesta3 NVARCAHR(30), respuesta4 NVARCAHR(30), respuestacorrecta NVARCHAR(1))";
	int result = sqlite3_exec(bd, sql, NULL,NULL,NULL) ;
	if (result != SQLITE_OK) {
		return result;
	}
	return result;
}
int tablapuntuaciones(sqlite3 *bd){

	char sql[]="create table puntuaciones(usuario NVARCHAR(20) primary key, puntos NVARCHAR(20)";
	int result = sqlite3_exec(bd, sql, NULL,NULL,NULL) ;
	if (result != SQLITE_OK) {
		return result;
	}
	return result;
}
int tablausuarios(sqlite3 *bd){

	char sql[]="create table usuarios(usuario NVARCHAR(30) primary key, clave NVARCHAR(30), nombre NVARCHAR(20), apellido NVARCHAR(30), edad NVARCHAR(3), email NVARCHAR(100), dir NVARCHAR(100))";
	int result = sqlite3_exec(bd, sql, NULL,NULL,NULL) ;
	if (result != SQLITE_OK) {
		return result;
	}
	return result;
}

int mostrar(void *unused, int cuenta, char **datos, char **columnas){
   int i;

       for (i = 0; i < cuenta; i++) {

           printf("%s: %s ", columnas[i], datos[i]);

       }
   cout<<""<<endl;

   return 0;
}

int mostrarpreguntas(sqlite3 *bd){

	char sql[]="select codigo, pregunta from preguntas;";
	int result = sqlite3_exec(bd, sql, mostrar, NULL,NULL) ;
		if (result != SQLITE_OK) {
			return result;
		}
	return result;
}
int mostrarpuntuaciones(sqlite3 *bd){

	char sql[]="select usuario, puntos from puntuaciones;";
	int result1 = sqlite3_exec(bd, sql, mostrar, NULL,NULL) ;
		if (result1 != SQLITE_OK) {
			return result1;
		}
	return result1;
}

int mostrarusuarios(sqlite3 *bd){

	char sql[]="select usuario, nombre, apellido from usuarios;";
	int result2 = sqlite3_exec(bd, sql, mostrar, NULL,NULL) ;
		if (result2 != SQLITE_OK) {
			return result2;
		}
	return result2;
}

int nuevousuario(sqlite3 *bd, Usuario *U) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into usuarios (usuario, clave, nombre, apellido, edad, email, dir) values (?,?,?,?,?,?,?)";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, &stmt, NULL) ;

	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 1, U->getusuario(), strlen(U->getusuario()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, U->getclave(), strlen(U->getclave()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, U->getnombre(), strlen(U->getnombre()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, U->getapellido(), strlen(U->getapellido()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, U->getedad(), strlen(U->getedad()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, U->getemail(), strlen(U->getemail()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 7, U->getdir(), strlen(U->getdir()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
			return result;
	}
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
			return result;
	}
	cout <<"~~~~~~~~~~~"<<endl;
	cout <<"Se ha registrado un nuevo usuario"<<endl;
	cout <<"~~~~~~~~~~~"<<endl;
	return SQLITE_OK;
}

int nuevapuntuacion(sqlite3 *bd, Puntuacion *T) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into puntuaciones (usuario, puntos) values (?,?)";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, &stmt, NULL) ;

	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 1, T->getusuario(), strlen(T->getusuario()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, T->getpuntos(), strlen(T->getpuntos()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
			return result;
	}
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
			return result;
	}
	cout <<"~~~~~~~~"<<endl;
	cout <<"Se ha registrado una nueva puntuacion"<<endl;
	cout <<"~~~~~~~~"<<endl;
	return SQLITE_OK;
}

int nuevapregunta(sqlite3 *bd, Pregunta *P) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into preguntas (codigo, pregunta, respuesta1, respuesta2, respuesta3, respuesta4, respuestacorrecta) values (?,?,?,?,?,?,?)";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, &stmt, NULL) ;

	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 1, P->getcodigo(), strlen(P->getcodigo()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, P->getpregunta(), strlen(P->getpregunta()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, P->getrespuesta1(), strlen(P->getrespuesta1()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, P->getrespuesta2(), strlen(P->getrespuesta2()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, P->getrespuesta3(), strlen(P->getrespuesta3()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, P->getrespuesta4(), strlen(P->getrespuesta4()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_bind_text(stmt, 7, P->getrespuestacorrecta(), strlen(P->getrespuestacorrecta()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		return result;
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
			return result;
	}
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
			return result;
	}
	cout <<"~~~~~~~~"<<endl;
	cout <<"Se ha registrado una nueva pregunta"<<endl;
	cout <<"~~~~~~~~"<<endl;
	return SQLITE_OK;
}


int borrarpregunta(sqlite3 *bd, char* codigo){
	sqlite3_stmt *stmt;

	char sql[] = "delete from preguntas where codigo = ?";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, &stmt, NULL) ;

	if (result != SQLITE_OK) {
		result = sqlite3_finalize(stmt);
		return result;
	}
	result = sqlite3_bind_text(stmt, 1, codigo, strlen(codigo), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		result = sqlite3_finalize(stmt);
			return result;
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
			result = sqlite3_finalize(stmt);
			return result;
	}
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
			return result;
	}
	cout <<"~~~~~~~~"<<endl;
	cout <<"Se ha borrado la pregunta seleccionada"<<endl;
	cout <<"~~~~~~~~"<<endl;
	return SQLITE_OK;
}

bool buscarusuarioregistrado(sqlite3 *bd, char* usuario, char* clave) {
	sqlite3_stmt *stmt;

	char sql[] = "select * from usuarios where usuario = ? and clave = ?;";
	int result = sqlite3_prepare_v2(bd, sql, strlen(sql) + 1, &stmt, NULL) ;

	if (result != SQLITE_OK) {
		result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		return result;
	}
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, usuario, strlen(usuario), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		return result;
	}
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, clave, strlen(clave), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		return result;
	}
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_ROW) {
		cout <<"~~~~~~~~~~~~"<<endl;
		cout <<"El usuario no concuerda con ninguno, revisa tu usuario y contraseña\n"<<endl;
		cout <<"~~~~~~~~~~~~"<<endl;
		result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		return result;
	}
		return false;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		return result;
	}
		return true;
}

int main() {
	sqlite3 *bd;
	sqlite3_stmt *stmt;
	int i;
	int result;
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	int result1= sqlite3_open("datos.sqlite", &bd);
		if (result1 != SQLITE_OK) {
				return result1;
		}

	tablapreguntas(bd);
	tablausuarios(bd);
	tablapuntuaciones(bd);

	const unsigned char* preguntas[10];
	const unsigned char* respuestacorrectas[10];
	for(int j=0;j<10;j++){
		preguntas[j]=new unsigned char[10];
		respuestacorrectas[j]=new unsigned char[10];
	}

	int opcionprincipal;
	int opcionsecundaria;
	int opcionadmin;
	Usuario *U;
	Pregunta *P;
	Puntuacion *T;
	char* respuesta=new char[200];
	char* codigo=new char[200];
	char* pregunta=new char[200];
	char* respuesta1=new char[200];
	char* respuesta2=new char[200];
	char* respuesta3=new char[200];
	char* respuesta4=new char[200];
	char* respuestacorrecta=new char[200];
	char* usuario=new char[200];
	char* clave=new char[200];
	char* nombre=new char[200];
	char* apellido=new char[200];
	char* edad=new char[200];
	char* email=new char[200];
	char* dir=new char[200];
	char* eliminar=new char[200];
	char* puntos = new char[200];
	int contador = 0;
	bool usuarioexiste = false;
	do{
		opcionprincipal=menuprincipal();
		switch(opcionprincipal){
				case 0:
					cout <<" ____________"<<endl;
					cout <<"|            |"<<endl;
					cout <<"|  REGISTRO  |"<<endl;
					cout <<"|____________|"<<endl;
					cout <<""<<endl;
					cout <<"~~~~~~~~~~~~~~"<<endl;
					cout <<"Rellena todos los valores para validar tu cuenta"<<endl;
					cout <<"~~~~~~~~~~~~~~"<<endl;
					cout <<"  ___________________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu nuevo usuario: ";cin >> usuario;
					cout <<"||___________________________\n";
					cout <<"  ________________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu contraseña: ";cin >> clave;
					cout <<"||________________________\n";
					cout <<"  _____________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu nombre: ";cin >> nombre;
					cout <<"||_____________________\n";
					cout <<"  ______________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu apellido: ";cin >> apellido;
					cout <<"||______________________\n";
					cout <<"  __________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu edad: ";cin >> edad;
					cout <<"||__________________\n";
					cout <<"  ___________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu email: ";cin >> email;
					cout <<"||___________________\n";
					cout <<"  _______________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu poblacion: ";cin >> dir;
					cout <<"||_______________________\n";
					cout <<"";
					U = new Usuario(usuario,clave, nombre, apellido, edad, email, dir);
					nuevousuario(bd, U);
					cout <<"Usuario:"<<usuario<<", Clave:"<<clave<<", Nombre:"<<nombre<<", Apellido:"<<apellido<<", Edad:"<<edad<<", Email:"<<email<<", Poblacion:"<<dir<<endl;
					cout <<"~~~~~~~~~~~~"<<endl;
					break;
				case 1:
					cout <<" ____________________"<<endl;
					cout <<"|                    |"<<endl;
					cout <<"|  Inicio de sesion  |"<<endl;
					cout <<"|____________________|"<<endl;
					cout <<""<<endl;
					cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					cout <<"Introduce los datos de tu cuenta"<<endl;
					cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					cout <<"  _______________________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu nombre de usuario: ";cin >> usuario;
					cout <<"||_______________________________\n";
					cout <<"  ________________________\n";
					cout <<"||\n";
					cout <<"||Introduce tu contraseña: ";cin >> clave;
					cout <<"||________________________\n";
					cout <<"";
					usuarioexiste=buscarusuarioregistrado(bd,usuario,clave);
				if (usuarioexiste){
					cout <<"~~~~~~~~~~~~~~~~~~~~"<<endl;
					cout <<"  __________________\n";
					cout <<"||\n";
					cout <<"||Usuario conectado: "<<usuario<<endl;
					cout <<"||__________________\n";
					cout <<"  _______\n";
					cout <<"||\n";
					cout <<"||Nombre: "<<nombre<<endl;
					cout <<"||_______\n";
					cout <<"  _________\n";
					cout <<"||\n";
					cout <<"||Apellido: "<<apellido<<endl;
					cout <<"||_________\n";
					cout <<""<<endl;
					cout <<"~~~~~~~~~~~~~~~~~~~~"<<endl;
					do{
					   opcionsecundaria=menusecundario();
					    switch(opcionsecundaria){
					    	case(0):
					    		result = sqlite3_prepare_v2(bd, "SELECT codigo, pregunta, respuesta1, respuesta2, respuesta3, respuesta4, respuestacorrecta from preguntas limit 10 offset abs(random() % (select count(*) from preguntas))", strlen("select codigo, pregunta, respuesta1, respuesta2, respuesta3, respuesta4, respuestacorrecta from preguntas limit 10 offset abs(random() % (select count(*) from preguntas))") + 1, &stmt, NULL) ;
					    		if (result != SQLITE_OK) {
					    		result = sqlite3_finalize(stmt);
					    		}else{
					    		cout <<" ____________________"<<endl;
					    		cout <<"|                    |"<<endl;
					    		cout <<"|  Inicio del juego  |"<<endl;
					    		cout <<"|____________________|"<<endl;
					    		cout <<""<<endl;
					    		cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    		cout <<"Usuario que juega: "<<usuario<<endl;
					    		cout <<"Fecha y hora de inicio: "<<std::ctime(&end_time)<<endl;
					    		cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    		for(i=0;i<11;i++){
					    		if(i==10){
					    			cout <<" ________________________________"<<endl;
					    			cout <<"|                                |"<<endl;
					    			cout <<"|  La partida acaba de terminar  |"<<endl;
					    			cout <<"|________________________________|"<<endl;
					    			cout <<""<<endl;
					    			cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    			cout <<"Usuario: "<<usuario<<endl;
					    			cout <<"Puntuacion: "<<contador<<endl;
					    			cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    			system("PAUSE");
					    			//No entiendo muy buen porque no me funciona esta parte, la que esta con las dos barras.
					    			//puntos = (char*)contador;
					    			//T = new Puntuacion(usuario,puntos);
					    			//nuevapuntuacion(bd, T);
					    		}else{
					    			result = sqlite3_step(stmt);
					    			cout <<endl;
					    			cin.ignore();
					    			cout <<"La pregunta numero: "<<i+1<<endl;
					    			preguntas[i]=sqlite3_column_text(stmt,0);
					    			cout <<sqlite3_column_text(stmt,1)<<endl;
					    			cout <<"Respuesta 1. "<<sqlite3_column_text(stmt,2)<<endl;
					    			cout <<"Respuesta 2. "<<sqlite3_column_text(stmt,3)<<endl;
					    			cout <<"Respuesta 3. "<<sqlite3_column_text(stmt,4)<<endl;
					    			cout <<"Respuesta 4. "<<sqlite3_column_text(stmt,5)<<endl;
					    			cout <<"Introduce tu respuesta(Introducir un numero entre el 1 y el 4): ";
					    			cin.getline(respuesta,10,'\n');
					    			int numero1 = atoi(respuesta);
					    			int numero = atoi((const char *) sqlite3_column_text(stmt,6));
					    				if(numero1==numero){
					    					cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    					cout <<"Enhorabuena, has acertado la pregunta"<<endl;
					    					cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    					contador++;
					    				}else{
					    					cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    					cout <<"Lo siento, pero has fallado"<<endl;
					    					cout <<"La respuesta correcta era la respuesta "<<sqlite3_column_text(stmt,6)<<endl;
					    					cout <<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    						}
					    					}
					    				}
					    					result = sqlite3_finalize(stmt);
					    				if (result != SQLITE_OK) {

					    				}
					    				}
					    					break;
					    			case(1):
					    				opcionadmin = menuadministracion();
					    				switch(opcionadmin){
					    				case 0:
					    					cout <<" __________________"<<endl;
					    					cout <<"|                  |"<<endl;
					    					cout <<"|  Crear pregunta  |"<<endl;
					    					cout <<"|__________________|"<<endl;
					    					cout <<""<<endl;
					    					cout <<"~~~~~~~~~~~~~~~~~~~~"<<endl;
					    					cout <<"Introduce los siguientes datos para crear una nueva pregunta."<<endl;
					    					cout <<"Recuerda que el codigo no se puede repetir"<<endl;
					    					cout <<"~~~~~~~~~~~~~~~~~~~~"<<endl;
					    					cin.ignore();
					    					cout <<""<<endl;
					    					cout <<"  __________________________________\n";
					    					cout <<"||\n";
					    					cout <<"||Introduce el codigo: ";cin.getline(codigo,10,'\n');
					    					cout <<"||__________________________________\n";
					    					cout <<endl;
					    					cout <<"  __________________________________\n";
					    					cout <<"||\n";
					    					cout <<"||Introduce el texto de la pregunta: ";cin.getline(pregunta,100,'\n');
					    					cout <<"||__________________________________\n";
					    					cout <<endl;
					    					cout <<"  _________________________\n";
					    					cout <<"||\n";
					    					cout <<"||Introduce la respuesta 1: ";cin.getline(respuesta1,100,'\n');
					    					cout <<"||_________________________\n";
					    					cout <<endl;
					    					cout <<"  _________________________\n";
					    					cout <<"||\n";
					    					cout <<"||Introduce la respuesta 2: ";cin.getline(respuesta2,100,'\n');
					    					cout <<"||_________________________\n";
					    					cout <<endl;
					    					cout <<"  _________________________\n";
					    					cout <<"||\n";
					    					cout <<"||Introduce la respuesta 3: ";cin.getline(respuesta3,100,'\n');
					    					cout <<"||_________________________\n";
					    					cout <<endl;
					    					cout <<"  _________________________\n";
					    					cout <<"||\n";
					    					cout <<"||Introduce la respuesta 4: ";cin.getline(respuesta4,100,'\n');
					    					cout <<"||_________________________\n";
					    					cout<<endl;
					    					cout <<"  __________________________________________________\n";
					    					cout <<"||\n";
					    					cout <<"||Introduce la respuesta correcta de las anteriores: ";cin.getline(respuestacorrecta,10,'\n');
					    					cout <<"||__________________________________________________\n";
					    					cout <<endl;
					    					P = new Pregunta(codigo,pregunta,respuesta1, respuesta2, respuesta3, respuesta4, respuestacorrecta);
					    					nuevapregunta(bd, P);
					    					cout <<"Codigo:"<<codigo<<", Pregunta:"<<pregunta<<", respuesta 1:"<<respuesta1<<", respuesta 2:"<<respuesta2<<", respuesta 3:"<<respuesta3<<", respuesta 4:"<<respuesta4<<", respuesta correcta:"<<respuestacorrecta<<endl;
					    					cout <<"~~~~~~~~~~~~~"<<endl;
					    					break;
					    				case 1:
					    					cout <<" ___________________"<<endl;
					    					cout <<"|                   |"<<endl;
					    					cout <<"|  Borrar pregunta  |"<<endl;
					    					cout <<"|___________________|"<<endl;
					    					cout <<""<<endl;
					    					mostrarpreguntas(bd);
					    					cout <<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    					cout <<"Introduce el codigo de la pregunta que quieras borrar"<<endl;
					    					cout <<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
					    					cout <<"  ____________________\n";
					    					cout <<"||\n";
					    					cout <<"||Introduce el codigo: ";cin >>eliminar;
					    					cout <<"||____________________\n";
					    					borrarpregunta(bd, eliminar);
					    					cout <<"  ____________________\n";
					    					cout <<"||\n";
					    					cout <<"||Codigo de la pregunta eliminada: "<<eliminar<<endl;
					    					cout <<"||____________________\n";
					    					break;
					    				case 2:
					    					mostrarpreguntas(bd);
					    					break;
					    				case 3:
					    					opcionsecundaria = menusecundario();
					    					break;
					    			}
					    			case(2):
										mostrarpuntuaciones(bd);
					    			break;
					    		}
					    	}while(opcionsecundaria!=3);

					    	}else{

					    	}
					break;
				case 2:
					instrucciones();
					break;
				case 3:
					cout<<"Espero que hayas disfrutado del Quiz, muchas gracias por jugar."<<endl;
					break;
		}
		}while(opcionprincipal!=3);

		result = sqlite3_close(bd);
			if (result != SQLITE_OK) {
				return result;
		}
		return 0;
}
