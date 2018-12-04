#ifndef GRUPO_HPP
#define GRUPO_HPP

#include "listaAlumnos.hpp"
#include "alumno.hpp"
class Grupo : public ListaAlumnos {

	private:
		
		int _id;
		Alumno * _lider;
		
	public:
	
		// Constructor
		Grupo(int id=-1);
		
		// Devuelve el lider del grupo
		inline Alumno * getLider() {
			return _lider;
		}
		
		// Devuelve el id del grupo
		inline int getID() {
			return _id;
		}
		
		// Modifica el lider del grupo
		bool setLider(Alumno * lider);
		
		// Modifica el id del grupo
		bool setID(int id);
		
};

#endif
