#include "listaGrupos.hpp"

const Grupo & ListaGrupos::buscarGrupo(int id) {
	
	list<Grupo>::iterator it = _grupos.begin();
	
	while(it != _grupos.end()) {
	
		if(it->getID() == id)
			break;
			
		it++;
	}
	
	return *it;
}

bool ListaGrupos::crearGrupo(int id) {
	
	Grupo g(id);
	
	_grupos.push_back(g);
	
	return existeGrupo(id);
}

bool ListaGrupos::existeGrupo(int id) {
	
	if(estaVacia())
		return false;
		
	list<Grupo>::iterator it = _grupos.begin();
	
	while(it != _grupos.end()) {
	
		if(it->getID() == id)
			return true;
			
		it++;
	}
	
	return false;
}
