#include "listaAlumnos.hpp"

void ListaAlumnos::listarAlumnos(int lista, int param, int orden) {
	
	// Antes de listar, se ordena el vector según el parámetro y el orden (asc o desc)
	ordenarAlumnos(param, orden);
	
	// Se recorre el vector imprimiendo alumno a alumno
	for(int i=0; i<getSize(); i++) {
		
		_alumnos[i].imprimirAlumno(lista);
		cout << endl;
	}
}

void ListaAlumnos::listarAlumnosHTML(char * fichero, int lista, int param, int orden) {
	
	ofstream fs(fichero);
	
	fs << "<!DOCTYPE html>\n<html>\n<head>\n<meta charset=\"UTF-8\">\n<title>Lista de alumnos</title>\n</head>\n<body>\n<h1>Lista de alumnos</h1>\n";
	
	// Antes de listar, se ordena el vector según el parámetro y el orden (asc o desc)
	ordenarAlumnos(param, orden);
	
	// Se recorre el vector imprimiendo alumno a alumno
	for(int i=0; i<getSize(); i++) {
		
		fs << "<p>";
		fs << "<b>Nombre:</b> " << _alumnos[i].getNombre() << "<br>";
		fs << "<b>Apellidos:</b> " << _alumnos[i].getApellidos() << "<br>";
	
		if(lista == 2) {
		
			fs << "<b>DNI:</b> " << _alumnos[i].getDNI() << "<br>";
			fs << "<b>Teléfono:</b> " << _alumnos[i].getTelefono() << "<br>";
			fs << "<b>Email:</b> " << _alumnos[i].getEmail() << "<br>";
			fs << "<b>Dirección:</b> " << _alumnos[i].getDireccion() << "<br>";
			fs << "<b>Curso más alto:</b> " << _alumnos[i].getCurso() << "<br>";
			fs << "<b>Fecha de nacimiento:</b> " << _alumnos[i].getFecha().d << "-" << _alumnos[i].getFecha().m << "-" << _alumnos[i].getFecha().y << "<br>";
			fs << "<b>Grupo:</b> ";
			
			if(_alumnos[i].getIDgrupo() < 0)
				fs << "sin grupo <br>";
			else
				fs << _alumnos[i].getIDgrupo() << "<br>";
			
			fs << "<b>Líder:</b> ";
		
			if(_alumnos[i].getLider() == true)
				fs << "Sí" << "<br>";
			else
				fs << "No" << "<br>";
		}
		
		fs << "</p>";
		cout << endl;
	}
	
	fs << "\n</body>\n</html>";
}

bool ListaAlumnos::insertarAlumno(const Alumno & a) {
	
	// Insertamos al final del vector
	_alumnos.push_back(a);
	
	if(existeAlumno(a.getDNI()) == true)
		return true;
	else
		return false;
}

bool ListaAlumnos::eliminarAlumno(string dni) {
	
	// Se recorre el vector buscando al alumno a eliminar
	for(int i=0; i<getSize(); i++) {
		
		// Una vez encontrado se elimina
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
	
	// Se recorre el vector buscando al alumno
	for(int i=0; i<getSize(); i++) {

		// Si se encuentra se asigna en "a"
		if(_alumnos[i].getDNI() == dni) {
			a = &_alumnos[i];
			break;
		}
	}
	
	return a; // Devolvemos el alumno
}

Alumno * ListaAlumnos::buscarAlumnoEmail(string email) {
	
	Alumno * a;
	
	// Se recorre el vector buscando al alumno
	for(int i=0; i<getSize(); i++) {
		
		// Si se encuentra se asigna en "a"
		if(_alumnos[i].getEmail() == email) {
			a = &_alumnos[i];
			break;
		}
	}
	
	return a; // Devolvemos el alumno
}

bool ListaAlumnos::existeAlumno(string dni) {
	
	if(estaVacia()) // Si la lista no tiene alumnos devolvemos false
		return false;
		
	// Recorremos buscando al alumno
	for(int i=0; i<getSize(); i++) {
	
		// Si lo encontramos devolvemos true
		if(_alumnos[i].getDNI() == dni)
			return true;
	}
	
	// Si no lo encontramos devolvemos false
	return false;
}

bool ListaAlumnos::existeAlumnoEmail(string email) {
	
	// Recorremos buscando al alumno
	for(int i=0; i<getSize(); i++) {

		// Si lo encontramos devolvemos true
		if(_alumnos[i].getEmail() == email)
			return true;
	}
	
	// Si no lo encontramos devolvemos false
	return false;
}

vector<Alumno> ListaAlumnos::buscarAlumnoApellidos(string apellidos) {

	vector<Alumno> v;
	
	// Recorremos el vector buscando alumnos que coincidan
	for(int i=0; i<getSize(); i++) {
		
		// Cada vez que encontramos un alumno que coincida lo insertamos en un vector
		if(_alumnos[i].getApellidos() == apellidos)
			v.push_back(_alumnos[i]);
	}
	
	return v; // Devolvemos el vector con todos los alumnos encontrados
}

bool ListaAlumnos::vaciarLista() {
	
	_alumnos.clear(); // Limpiamos el vector
	
	if(estaVacia())
		return true;
	else
		return false;
}

void ListaAlumnos::ordenarAlumnos(int parametro, int orden) {
	
	// Segun el parámetro y el tipo de orden llamaremos a una función un otra
	
	if(parametro == 1) {
	 	
	 	if(orden == 1)
	 		sort(_alumnos.begin(), _alumnos.end(), ordenacionAscendenteNombre);
	
		else
			sort(_alumnos.begin(), _alumnos.end(), ordenacionDescendenteNombre);
	}
	
	if(parametro == 2) {
		
		if(orden == 1)
	 		sort(_alumnos.begin(), _alumnos.end(), ordenacionAscendenteApellidos);
	
		else
			sort(_alumnos.begin(), _alumnos.end(), ordenacionDescendenteApellidos);
	}
	
	if(parametro == 3) {
		
		if(orden == 1)
	 		sort(_alumnos.begin(), _alumnos.end(), ordenacionAscendenteDNI);
	
		else
			sort(_alumnos.begin(), _alumnos.end(), ordenacionDescendenteDNI);
	}
	
	if(parametro == 4) {
		
		if(orden == 1)
	 		sort(_alumnos.begin(), _alumnos.end(), ordenacionAscendenteCurso);
	
		else
			sort(_alumnos.begin(), _alumnos.end(), ordenacionDescendenteCurso);
	}
	
	if(parametro == 5) {
		
		if(orden == 1)
	 		sort(_alumnos.begin(), _alumnos.end(), ordenacionAscendenteGrupo);
	
		else
			sort(_alumnos.begin(), _alumnos.end(), ordenacionDescendenteGrupo);
	}
	
	if(parametro == 6) {
		
		if(orden == 1)
	 		sort(_alumnos.begin(), _alumnos.end(), ordenacionAscendenteLider);
	
		else
			sort(_alumnos.begin(), _alumnos.end(), ordenacionDescendenteLider);
	}
}

// Funciones auxiliares para utilizar sort()

bool ordenacionAscendenteNombre(Alumno i, Alumno j) {
	return i.getNombre() < j.getNombre();
}

bool ordenacionDescendenteNombre(Alumno i, Alumno j) {
	return i.getNombre() > j.getNombre();
}

bool ordenacionAscendenteApellidos(Alumno i, Alumno j) {
	return i.getApellidos() < j.getApellidos();
}

bool ordenacionDescendenteApellidos(Alumno i, Alumno j) {
	return i.getApellidos() > j.getApellidos();
}

bool ordenacionAscendenteDNI(Alumno i, Alumno j) {
	return i.getDNI() < j.getDNI();
}

bool ordenacionDescendenteDNI(Alumno i, Alumno j) {
	return i.getDNI() > j.getDNI();
}

bool ordenacionAscendenteCurso(Alumno i, Alumno j) {
	return i.getCurso() < j.getCurso();
}

bool ordenacionDescendenteCurso(Alumno i, Alumno j) {
	return i.getCurso() > j.getCurso();
}

bool ordenacionAscendenteGrupo(Alumno i, Alumno j) {
	return i.getIDgrupo() < j.getIDgrupo();
}

bool ordenacionDescendenteGrupo(Alumno i, Alumno j) {
	return i.getIDgrupo() > j.getIDgrupo();
}

bool ordenacionAscendenteLider(Alumno i, Alumno j) {
	return i.getLider() < j.getLider();
}

bool ordenacionDescendenteLider(Alumno i, Alumno j) {
	return i.getLider() > j.getLider();
}
