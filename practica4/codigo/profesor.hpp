#ifndef PROFESOR_HPP
#define PROFESOR_HPP

#include <fstream>
#include "listaGrupos.hpp"

class Profesor {

	private:
	
		string _fichero;
		bool _coordinador;
			
	public:
		
		Profesor(string fichero="", bool coordinador=false);
		
		inline string getFichero() {
			return _fichero;
		}
		
		inline bool getCoordinador() {
			return _coordinador;
		}
		
		bool setFichero(string fichero);
		
		bool setCoordinador(bool coordinador);
		
		bool guardarFichero(ListaAlumnos & alumnos, ListaGrupos & grupos);
		
		bool guardarCopia(ListaAlumnos & alumnos, ListaGrupos & grupos);
		
		bool cargarFichero(ListaAlumnos & alumnos, ListaGrupos & grupos); 
};

bool saveFile(string fichero, ListaAlumnos & alumnos, ListaGrupos & grupos);
bool loadFile(string fichero, ListaAlumnos & alumnos, ListaGrupos & grupos);

struct alumnoAux {
	
	char dni[10];
	char nombre[100];
	char apellidos[100];
	int telefono;
	char email[100];
	char direccion[100];
	int curso;
	int d;
	int m;
	int y;
	int grupo;
	bool lider;
};
#endif
