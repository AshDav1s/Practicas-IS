#include "grupo.hpp"

Grupo::Grupo(int id) {

	_alumnos.resize(0); // Se inicializa el número de alumnos a 0 
	_id = id;	
	_lider = "";			// Aún no hay líder asignado
}

bool Grupo::setLider(string lider) {

	_lider = lider;
	
	if(lider == _lider)
		return true;
	else
		return false;
		
}

bool Grupo::setID(int id) {

	_id = id;
	
	if(id == _id)
		return true;
	else
		return false;
		
}

bool Grupo::existeAlumno(string dni) {
	
	// Recorre el vector buscando coincidencia
	for(int i=0; i<getSize(); i++) {
		
		if(dni == _alumnos[i])
			return true;
	}
	
	return false;
}

bool Grupo::insertarAlumno(string dni) {
	
	// Inserta al final del vector
	_alumnos.push_back(dni);
	
	if(existeAlumno(dni))
		return true;
	else
		return false;
}

bool Grupo::eliminarAlumno(string dni) {
	
	// Recorre el vector buscando coincidencia, y si la encuentra la elimina
	for(int i=0; i<getSize(); i++) {
	
		if(_alumnos[i] == dni) {
			_alumnos.erase(_alumnos.begin() + i);
			break;	
		}
	}
	
	if(not existeAlumno(dni))
		return true;
	else
		return false;
}

bool Grupo::vaciarGrupo() {

	// Se limpia el vector
	_alumnos.clear();
	
	if(estaVacio())
		return true;
	else
		return false;
}
