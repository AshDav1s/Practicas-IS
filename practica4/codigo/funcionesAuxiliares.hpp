#ifndef FUNCIONES_AUXILIARES_HPP
#define FUNCIONES_AUXILIARES_HPP

#include "listaAlumnos.hpp"
#include "listaGrupos.hpp"
#include "macros.hpp"

	int menu();
	void opcionInsertar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	void opcionListar(ListaAlumnos & alumnos);
	void opcionMostrar(ListaAlumnos & alumnos);
	void opcionEditar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	void opcionBorrar(ListaAlumnos & alumnos, ListaGrupos & grupos);
	
#endif
