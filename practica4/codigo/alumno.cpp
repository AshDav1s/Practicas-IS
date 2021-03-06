#include "alumno.hpp"

Alumno::Alumno(string dni, string nombre, string apellidos, int telefono, string email, string direccion, int curso, int dia, int mes, int year, int IDgrupo, bool lider) {
	
	_dni = dni;
	_nombre = nombre;
	_apellidos = apellidos;
	_telefono = telefono;
	_email = email;
	_direccion = direccion;
	_curso = curso;
	_fecha.d = dia;
	_fecha.m = mes;
	_fecha.y = year;
	_IDgrupo = IDgrupo;
	_lider = lider;
}

void Alumno::imprimirAlumno(int s) {

	cout << "\tNombre: " << getNombre() << endl;
	cout << "\tApellidos: " << getApellidos() << endl;
	
	// Si se va a imprimir la versión completa, se imprimen el resto de parámetros
	if(s == 2) {
		cout << "\tDNI: " << getDNI() << endl;
		cout << "\tTeléfono: " << getTelefono() << endl;
		cout << "\tEmail: " << getEmail() << endl;
		cout << "\tDirección: " << getDireccion() << endl;
		cout << "\tCurso más alto: " << getCurso() << endl;
		cout << "\tFecha de nacimiento: " << getFecha().d << "-" << getFecha().m << "-" << getFecha().y << endl;
		cout << "\tGrupo: ";
		
		if(getIDgrupo() < 0)
			cout << "sin grupo" << endl;
		else
			cout << getIDgrupo() << endl;
			
		cout << "\tLíder: ";
	
		if(getLider() == true)
			cout << "Sí" << endl;
		else
			cout << "No" << endl;
	}
	
}

bool Alumno::setDNI(string dni) {

	_dni = dni;
	
	if(dni == _dni)
		return true;
	else
		return false;
}

bool Alumno::setNombre(string nombre) {

	_nombre = nombre;
	
	if(nombre == _nombre)
		return true;
	else
		return false;
}

bool Alumno::setApellidos(string apellidos) {

	_apellidos = apellidos;
	
	if(apellidos == _apellidos)
		return true;
	else
		return false;
}

bool Alumno::setTelefono(int telefono) {

	_telefono = telefono;
	
	if(telefono == _telefono)
		return true;
	else
		return false;
}

bool Alumno::setEmail(string email) {

	_email = email;
	
	if(email == _email)
		return true;
	else
		return false;
}

bool Alumno::setDireccion(string direccion) {

	_direccion = direccion;
	
	if(direccion == _direccion)
		return true;
	else
		return false;
}

bool Alumno::setCurso(int curso) {

	_curso = curso;
	
	if(curso == _curso)
		return true;
	else
		return false;
}

bool Alumno::setFecha(struct date fecha) {

	_fecha.d = fecha.d;
	_fecha.m = fecha.m;
	_fecha.y = fecha.y;
	
	if(fecha.d == _fecha.d  and  fecha.m == _fecha.m  and  fecha.y == _fecha.y)
		return true;
	else
		return false;
}

bool Alumno::setIDgrupo(int IDgrupo) {

	_IDgrupo = IDgrupo;
	
	if(IDgrupo == _IDgrupo)
		return true;
	else
		return false;
}

bool Alumno::setLider(bool lider) {

	_lider = lider;
	
	if(lider == _lider)
		return true;
	else
		return false;
}
