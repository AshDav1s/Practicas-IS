#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <string>
#include <iostream>

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
		Alumno(string dni, string nombre, string apellidos, int telefono, string email, string direccion, int curso, struct date fecha, int IDgrupo = -1, bool lider = false);
		
		// Imprime por pantalla los atributos del alumno
		void imprimirAlumno();
		
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
		
		// Funciones "set". Modifican el valor de cada uno de los atributos del alumno.
		
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
