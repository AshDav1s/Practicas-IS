#include "listaGrupos.hpp"

Grupo * ListaGrupos::buscarGrupo(int id) {
	
	Grupo * g;
	
	// Recorre el vector buscando el grupo	
	for(int i=0; i<getSize(); i++) {
		// Se asigna el grupo encontrado
		if(id == _grupos[i].getID())
			g = &_grupos[i];
	}
	
	return g; // Se devuelve el grupo
}

bool ListaGrupos::crearGrupo(int id) {
	
	Grupo g(id);
	
	// Se inserta el grupo al final del vector
	_grupos.push_back(g);
	
	return existeGrupo(id);
}

bool ListaGrupos::existeGrupo(int id) const {
	
	if(estaVacia()) // Si no hay grupos
		return false;
		
	for(int i=0; i<getSize(); i++) { // Se busca el grupo
	
		if(_grupos[i].getID() == id) // Si se encuentra el grupo
			return true;
			
	}
	
	return false; // Si no se encuentra el grupo
}

bool ListaGrupos::eliminarGrupo(int id) {
	
	// Buscamos el grupo
	for(int i=0; i<getSize(); i++) {
		
		// Lo eliminamos
		if(_grupos[i].getID() == id) {
			
			_grupos.erase(_grupos.begin() + i);
			break;
		}
	}
	
	if(not existeGrupo(id))
		return true;
	else
		return false;
}

bool ListaGrupos::vaciarLista() {
		
	_grupos.clear(); // Limpiamos el vector
		
	if(estaVacia())
		return true;
	else
		return false;
}
