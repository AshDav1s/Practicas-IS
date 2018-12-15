#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>
#include <iostream>
#include <fstream>

struct date {
	int d;
	int m;
	int y;
};

using namespace std;

class Alumno {

	private:
		
		string _dni;
		string _nombre;
		string _apellidos;
		int _telefono;
		string _email;
		string _direccion;
		int _curso;
		struct date _fecha;
		int _IDgrupo;
		bool _lider;
		
	public:
		
		// Constructor
		Alumno(string dni="", string nombre="", string apellidos="", int telefono=-1, string email="", string direccion="", int curso=-1, int dia=-1, int mes=-1, int year=-1, int IDgrupo = -1, bool lider = false);
		
		// Imprime por pantalla los atributos del alumno (s=1 sólo nombre y apellidos, s=2 versión completa)
		void imprimirAlumno(int s);
		
		// Funciones "get". Devuelven el valor de cada uno de los atributos del alumno
		
		inline string getDNI() const {
			return _dni;
		}
		
		inline string getNombre() const {
			return _nombre;
		}
		
		inline string getApellidos() const {
			return _apellidos;
		}
		
		inline int getTelefono() const {
			return _telefono;
		}
		
		inline string getEmail() const {
			return _email;
		}
		
		inline string getDireccion() const {
			return _direccion;
		}
		
		inline int getCurso() const {
			return _curso;
		}
		
		inline struct date getFecha() const {
			return _fecha;
		}
		
		inline int getIDgrupo() const {
			return _IDgrupo;
		}
		
		inline bool getLider() const {
			return _lider;
		}
		
		// Funciones "set". Modifican el valor de cada uno de los atributos del alumno. Devuelven true si se modifica correctamente.
		
		bool setDNI(string dni);
		bool setNombre(string nombre);
		bool setApellidos(string apellidos);
		bool setTelefono(int telefono);
		bool setEmail(string email);
		bool setDireccion(string direccion);
		bool setCurso(int curso);
		bool setFecha(struct date fecha);
		bool setIDgrupo(int IDgrupo);
		bool setLider(bool lider);
		
};

#endif
