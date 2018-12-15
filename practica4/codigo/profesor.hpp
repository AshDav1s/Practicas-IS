#ifndef PROFESOR_HPP
#define PROFESOR_HPP

#include <fstream>
#include "listaGrupos.hpp"
#include "listaAlumnos.hpp"

class Profesor {

	private:
	
		string _fichero;		// Nombre del fichero con el que se va a trabajar
		bool _coordinador;	// Indica si el usuario tiene permiso de coordinador o no
			
	public:
		
		// Contructor
		Profesor(string fichero="", bool coordinador=false);
		
		// Devuelve el nombre del fichero
		inline string getFichero() const {
			return _fichero;
		}
		
		// Devuelve el valor del parámetro coordinador
		inline bool getCoordinador() const {
			return _coordinador;
		}
		
		// Cambia el nombre del fichero
		bool setFichero(string fichero);
		
		// Cambia el parámetro coordinador
		bool setCoordinador(bool coordinador);
		
		// Guarda la información en el fichero
		bool guardarFichero(ListaAlumnos & alumnos);
		
		// Guarda una copia de seguridad
		bool guardarCopia(ListaAlumnos & alumnos);
		
		// Carga la información del fichero
		bool cargarFichero(ListaAlumnos & alumnos, ListaGrupos & grupos); 

};

// Funciones y estructura auxiliares para el manejo de ficheros

bool saveFile(string fichero,  ListaAlumnos & alumnos);
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
