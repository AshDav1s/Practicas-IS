#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP

#include "profesor.hpp"
#include "macros.hpp"
	
	struct usuario {

		char nombre[100];
		char password[100];
		bool coordinador;
	};
	
	int menu();
	void opcionInsertar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	void opcionListar(ListaAlumnos & alumnos);
	void opcionMostrar(ListaAlumnos & alumnos);
	void opcionEditar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	void opcionBorrar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	int inicioSesion(Profesor & p);
	
#endif
