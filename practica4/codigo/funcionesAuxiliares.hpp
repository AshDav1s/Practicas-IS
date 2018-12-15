#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP

#include "profesor.hpp"
#include "macros.hpp"
	
	// Estructura auxiliar para almacenar los datos del usuario
	struct usuario {

		char nombre[100];
		char password[100];
		bool coordinador;
	};
	
	// Muestra las opciones del menú y devuelve la seleccionada
	int menu();
	
	// Muestra los miembros de un grupo
	void opcionVerGrupo(ListaAlumnos & alumnos, ListaGrupos & grupos);
	
	// Inserta un alumno en la lista
	void opcionInsertar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	
	// Muestra la lista de alumnos
	void opcionListar(ListaAlumnos & alumnos);
	
	// Muestra la información de un alumno concreto
	void opcionMostrar(ListaAlumnos & alumnos);
	
	// Modifica los parámetros de un alumno
	void opcionEditar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	
	// Borra un alumno
	void opcionBorrar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	
	// Controla el inicio de sesión
	int inicioSesion(Profesor & p);
	
	// Guarda un fichero con los alumnos
	void opcionGuardar(ListaAlumnos & alumnos, Profesor & p);
	
	// Guarda copia de seguridad
	void opcionGuardarCopia(ListaAlumnos & alumnos, Profesor & p);
	
	// Carga un fichero con los alumnos
	void opcionCargar(ListaAlumnos & alumnos, ListaGrupos & grupos, Profesor & p);
	
	// Carga una copia de seguridad	
	void opcionCargarCopia(ListaAlumnos & alumnos, ListaGrupos & grupos, Profesor & p);
	
	// Comprueba la existencia de un fichero
	bool existeFichero(string fichero);
	
#endif
