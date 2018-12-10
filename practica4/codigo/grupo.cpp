#include "grupo.hpp"

Grupo::Grupo(int id) {

	_id = id;
	_lider = NULL;
}

bool Grupo::setLider(Alumno * lider) {

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
