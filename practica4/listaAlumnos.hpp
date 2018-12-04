#ifndef LISTA_ALUMNOS_HPP
#define LISTA_ALUMNOS_HPP

#include "alumno.hpp"
#include <list>

class ListaAlumnos {

	private:
		
		list<Alumno> _alumnos;
		
	public:
		
		// Constructor
		ListaAlumnos(){}
		
		// Imprime por pantalla todos los alumnos de la lista
		void listarAlumnos();
		
		// Inserta un alumno al final de la lista
		bool insertarAlumno(const Alumno & a);
		
		// Elimina un alumno de la lista
		bool eliminarAlumno(string dni);
		
		// Busca un alumno mediante su DNI
		const Alumno & buscarAlumno(string dni);
		
		// Busca un alumno mediante su email
		const Alumno & buscarAlumnoEmail(string email);
		
		// Devuelve una lista con todos los alumnos cuyos apellidos corresponden con el argumento
		list<Alumno> buscarAlumnoApellidos(string apellidos);
		
		// Comprueba si existe un alumno mediante su DNI
		bool existeAlumno(string DNI);
		
		// Comprueba si existe un alumno mediante su email
		bool existeAlumnoEmail(string email);
		
		// Devuelve el número de alumnos que hay en la lista
		inline int getSize() {
			return _alumnos.size();
		}
		
		// Devuelve true si la lista de alumnos está vacía
		inline bool estaVacia() {
			if(_alumnos.empty() == true)
				return true;
			else
				return false;
		}
};

#endif
