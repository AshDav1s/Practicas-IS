#include "listaAlumnos.hpp"

void ListaAlumnos::listarAlumnos() {
	
	list<Alumno>::iterator it = _alumnos.begin();
	
	while(it != _alumnos.end()) {
		
		it->imprimirAlumno();
		cout << endl;
		it++;
	}
}

bool ListaAlumnos::insertarAlumno(const Alumno & a) {
	
	_alumnos.push_back(a);
	
	if(existeAlumno(a.getDNI()) == true)
		return true;
	else
		return false;
}

bool ListaAlumnos::eliminarAlumno(string dni) {
	
	list<Alumno>::iterator it = _alumnos.begin();
	
	while(it != _alumnos.end()) {
		
		if(it->getDNI() == dni) {
			_alumnos.erase(it);
			break;
		}
			
		it++;
	}
	
	
	if(not existeAlumno(dni))
		return true;
	else
		return false;
}

const Alumno & ListaAlumnos::buscarAlumno(string dni) {
	
	list<Alumno>::iterator it = _alumnos.begin();
	
	while(it != _alumnos.end()) {
		
		if(it->getDNI() == dni)
			break;
			
		it++;
	}
	
	return *it;
}

const Alumno & ListaAlumnos::buscarAlumnoEmail(string email) {
	
	list<Alumno>::iterator it = _alumnos.begin();
	
	while(it != _alumnos.end()) {
		
		if(it->getEmail() == email)
			break;
			
		it++;
	}
	
	return *it;
}

bool ListaAlumnos::existeAlumno(string dni) {
	
	list<Alumno>::iterator it = _alumnos.begin();
	
	while(it != _alumnos.end()) {
		
		if(it->getDNI() == dni)
			return true;
			
		it++;
	}
	
	return false;
}

bool ListaAlumnos::existeAlumnoEmail(string email) {
	
	list<Alumno>::iterator it = _alumnos.begin();
	
	while(it != _alumnos.end()) {
		
		if(it->getEmail() == email)
			return true;
			
		it++;
	}
	
	return false;
}

list<Alumno> ListaAlumnos::buscarAlumnoApellidos(string apellidos) {

	list<Alumno>::iterator it = _alumnos.begin();
	list<Alumno> lista;
		
	while(it != _alumnos.end()) {
		
		if(it->getApellidos() == apellidos) {
			lista.push_back(*it);
		}
			
		it++;
	}
	
	return lista;
}
