#ifndef LISTA_GRUPOS_HPP
#define LISTA_GRUPOS_HPP

#include "grupo.hpp"

class ListaGrupos {
	
	private:
	
		vector<Grupo> _grupos;
		
	public:
	
		ListaGrupos(){}
		
		// Busca un grupo por su ID
		Grupo * buscarGrupo(int id);
		
		// Crea un grupo y lo inserta en la lista
		bool crearGrupo(int id);
		
		// Devuelve si un grupo existe o no
		bool existeGrupo(int id);
		
		// Devuelve el número de grupos
		inline int getSize() {
			return _grupos.size();
		}
		
		// Devuelve si la lista de grupos está vacía
		inline int estaVacia() {
			return _grupos.empty();
		}
};

#endif
