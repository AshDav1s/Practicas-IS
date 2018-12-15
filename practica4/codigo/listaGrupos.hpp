#ifndef LISTA_GRUPOS_HPP
#define LISTA_GRUPOS_HPP

#include "grupo.hpp"

class ListaGrupos {
	
	private:
	
		vector<Grupo> _grupos;	// Vector con todos los grupos
		
	public:
		
		// Constructor vacío
		ListaGrupos(){}

		// Busca un grupo por su ID
		Grupo * buscarGrupo(int id);
		
		// Crea un grupo y lo inserta en la lista
		bool crearGrupo(int id);
		
		// Devuelve si un grupo existe o no
		bool existeGrupo(int id) const;
		
		// Devuelve el número de grupos
		inline int getSize() const {
			return _grupos.size();
		}
		
		// Devuelve si la lista de grupos está vacía
		inline int estaVacia() const {
			return _grupos.empty();
		}
		
		// Elimina un grupo
		bool eliminarGrupo(int id);
		
		// Elimina todos los grupos
		bool vaciarLista();
};

#endif
