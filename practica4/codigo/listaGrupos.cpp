#include "listaGrupos.hpp"

Grupo * ListaGrupos::buscarGrupo(int id) {
	
	Grupo * g;
	
	for(int i=0; i<getSize(); i++) {
		if(id == _grupos[i].getID())
			g = &_grupos[i];
	}
	
	return g;
}

bool ListaGrupos::crearGrupo(int id) {
	
	Grupo g(id);
	
	_grupos.push_back(g);
	
	return existeGrupo(id);
}

bool ListaGrupos::existeGrupo(int id) {
	
	if(estaVacia())
		return false;
		
	for(int i=0; i<getSize(); i++) {
	
		if(_grupos[i].getID() == id)
			return true;
			
	}
	
	return false;
}
