#ifndef GRUPO_HPP
#define GRUPO_HPP

#include "alumno.hpp"
#include <vector>

class Grupo {

	private:
		
		vector<string> _alumnos;	// Almacena los dni de los alumnos del grupo
		int _id;							// identificador del grupo
		string _lider;					// dni del líder del grupo
		
	public:
	
		// Constructor
		Grupo(int id=-1);
		
		// Devuelve el lider del grupo
		inline string getLider() const {
			return _lider;
		}
		
		// Devuelve el id del grupo
		inline int getID() const {
			return _id;
		}
		
		// Modifica el lider del grupo
		bool setLider(string lider);
		
		// Modifica el id del grupo
		bool setID(int id);
		
		// Devuelve el número de miembros del grupo
		inline int getSize() const{
			return _alumnos.size();
		}
		
		// Devuelve true si el grupo no tiene miembros
		inline bool estaVacio() const {
			return _alumnos.empty();
		}
		
		// Devuelve true si existe algún alumno que coincida con el dni pasado como argumento
		bool existeAlumno(string dni);
		
		// Inserta un alumno en el grupo
		bool insertarAlumno(string dni);
		
		// Elimina un alumno del grupo
		bool eliminarAlumno(string dni);
		
		// Elimina todos los alumnos del grupo
		bool vaciarGrupo();
		
		// Accede a una posición del vector de alumnos
		inline string getAlumno(int i) {
			return _alumnos[i];
		}
		
};

#endif
