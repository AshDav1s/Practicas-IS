#ifndef LISTA_ALUMNOS_HPP
#define LISTA_ALUMNOS_HPP

#include "alumno.hpp"
#include <vector>
#include <algorithm>

class ListaAlumnos {

	private:
		
		vector<Alumno> _alumnos;
		
	public:
		
		// Constructor
		ListaAlumnos() {
			_alumnos.resize(0);
		}
		
		inline const Alumno & getAlumno(int i) {
			return _alumnos[i];
		}
		
		// Imprime por pantalla todos los alumnos de la lista
		void listarAlumnos(int lista, int param, int orden);
		
		// Imprime la lista de alumnos en un fichero HTML
		void listarAlumnosHTML(char * fichero, int lista, int param, int orden);
		
		// Inserta un alumno al final de la lista
		bool insertarAlumno(const Alumno & a);
		
		// Elimina un alumno de la lista
		bool eliminarAlumno(string dni);
		
		// Busca un alumno mediante su DNI
		Alumno * buscarAlumno(string dni);
		
		// Busca un alumno mediante su email
		Alumno * buscarAlumnoEmail(string email);
		
		// Devuelve un vector con todos los alumnos cuyos apellidos corresponden con el argumento
		vector<Alumno> buscarAlumnoApellidos(string apellidos);
		
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
			return _alumnos.empty();
		}

		void ordenarAlumnos(int parametro, int orden);
		
		bool vaciarLista();
};

bool ordenacionAscendenteNombre(Alumno i, Alumno j);
bool ordenacionDescendenteNombre(Alumno i, Alumno j);
bool ordenacionAscendenteApellidos(Alumno i, Alumno j);
bool ordenacionDescendenteApellidos(Alumno i, Alumno j);
bool ordenacionAscendenteDNI(Alumno i, Alumno j);
bool ordenacionDescendenteDNI(Alumno i, Alumno j);
bool ordenacionAscendenteCurso(Alumno i, Alumno j);
bool ordenacionDescendenteCurso(Alumno i, Alumno j);
bool ordenacionAscendenteGrupo(Alumno i, Alumno j);
bool ordenacionDescendenteGrupo(Alumno i, Alumno j);
bool ordenacionAscendenteLider(Alumno i, Alumno j);
bool ordenacionDescendenteLider(Alumno i, Alumno j);

#endif
