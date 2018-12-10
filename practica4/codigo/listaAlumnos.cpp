#include "listaAlumnos.hpp"

void ListaAlumnos::listarAlumnos() {
	
	for(int i=0; i<getSize(); i++) {
		
		_alumnos[i].imprimirAlumno();
		cout << endl;
	}
}

bool ListaAlumnos::insertarAlumno(const Alumno & a) {
	
	cout<< getSize()<<endl;
	_alumnos.push_back(a);
		cout<< getSize()<<endl;
	if(existeAlumno(a.getDNI()) == true)
		return true;
	else
		return false;
}

bool ListaAlumnos::eliminarAlumno(string dni) {
	
	for(int i=0; i<getSize(); i++) {
		
		if(_alumnos[i].getDNI() == dni) {
			
			_alumnos.erase(_alumnos.begin() + i);
			break;
		}
	}
		
	if(not existeAlumno(dni))
		return true;
	else
		return false;
}

Alumno * ListaAlumnos::buscarAlumno(string dni) {
	
	Alumno * a;
	
	for(int i=0; i<getSize(); i++) {
		
		if(_alumnos[i].getDNI() == dni) {
			a = &_alumnos[i];
			break;
		}
	}
	
	return a;
}

Alumno *  ListaAlumnos::buscarAlumnoEmail(string email) {
	
	Alumno * a;
	
	for(int i=0; i<getSize(); i++) {
		
		if(_alumnos[i].getEmail() == email) {
			a = &_alumnos[i];
			break;
		}
	}
	
	return a;
}

bool ListaAlumnos::existeAlumno(string dni) {
	
	if(estaVacia())
		return false;
		
	for(int i=0; i<getSize(); i++) {
		cout << getSize() << "," << i << endl;
		//if(_alumnos[i].getDNI() == dni)
			//return true;
	}
	
	return false;
}

bool ListaAlumnos::existeAlumnoEmail(string email) {
	
	for(int i=0; i<getSize(); i++) {
		
		if(_alumnos[i].getEmail() == email)
			return true;
	}
	
	return false;
}

vector<Alumno> ListaAlumnos::buscarAlumnoApellidos(string apellidos) {

	vector<Alumno> v;
	
	for(int i=0; i<getSize(); i++) {
		
		if(_alumnos[i].getApellidos() == apellidos)
			v.push_back(_alumnos[i]);
	}
	
	return v;
}
