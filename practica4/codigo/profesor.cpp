#include "profesor.hpp"
#include <string.h>
#include <ctime>

Profesor::Profesor(string fichero, bool coordinador) {

	_fichero = fichero;
	_coordinador = coordinador;
}

bool Profesor::setFichero(string fichero) {

	_fichero = fichero;
	
	if(_fichero == fichero)
		return true;
	else
		return false;
}
		
bool Profesor::setCoordinador(bool coordinador) {

	_coordinador = coordinador;

	if(_coordinador == coordinador)
		return true;
	else
		return false;
}

bool Profesor::guardarFichero(ListaAlumnos & alumnos, ListaGrupos & grupos) {

	bool returnValue = saveFile(getFichero(), alumnos, grupos);
	
	return returnValue;
}
		
bool Profesor::cargarFichero(ListaAlumnos & alumnos, ListaGrupos & grupos) {
	
	alumnos.vaciarLista();
	grupos.vaciarLista();
	
	bool returnValue = loadFile(getFichero(), alumnos, grupos);
	
	return returnValue;
}
		
bool saveFile(string fichero, ListaAlumnos & alumnos, ListaGrupos & grupos) {

	struct alumnoAux a;
	
	ofstream fsalida(fichero.c_str(), ios::out | ios::binary);
	
	if(fsalida.is_open() == false)
		return false;
	
	for(int i=0; i<alumnos.getSize(); i++) {
		
		strncpy(a.dni, alumnos.getAlumno(i).getDNI().c_str(), 9);
		a.dni[9] = '\0';
		
		strncpy(a.nombre, alumnos.getAlumno(i).getNombre().c_str(), 99);
		a.nombre[99] = '\0';
		
		strncpy(a.apellidos, alumnos.getAlumno(i).getApellidos().c_str(), 99);
		a.apellidos[99] = '\0';
	
		a.telefono = alumnos.getAlumno(i).getTelefono();
		
		strncpy(a.email, alumnos.getAlumno(i).getEmail().c_str(), 99);
		a.email[99] = '\0';
		
		strncpy(a.direccion, alumnos.getAlumno(i).getDireccion().c_str(), 99);
		a.direccion[99] = '\0';
		
		a.curso = alumnos.getAlumno(i).getCurso();
		
		a.d = alumnos.getAlumno(i).getFecha().d;
		a.m = alumnos.getAlumno(i).getFecha().m;
		a.y = alumnos.getAlumno(i).getFecha().y;
		
		a.grupo = alumnos.getAlumno(i).getIDgrupo();
		a.lider = alumnos.getAlumno(i).getLider();
		
		fsalida.write((char*)&a, sizeof(struct alumnoAux));

	}
	
	fsalida.close();
	
	return true;
}

bool Profesor::guardarCopia(ListaAlumnos & alumnos, ListaGrupos & grupos) {
	
	time_t current_time;
	struct tm * local_time;

	time ( &current_time );
	local_time = localtime(&current_time);

	int Year   = local_time->tm_year + 1900;
	int Month  = local_time->tm_mon + 1;
	int Day    = local_time->tm_mday;

	int Hour   = local_time->tm_hour;
	int Min    = local_time->tm_min;
	int Sec    = local_time->tm_sec;
	
	string fichero = "copia_" + to_string(Year) + "-" + to_string(Month) + "-" + to_string(Day) + "_" + to_string(Hour) + ":" + to_string(Min) + ":" + to_string(Sec);
	
	bool returnValue = saveFile(fichero, alumnos, grupos);
	
	return returnValue;
}
		
bool loadFile(string fichero, ListaAlumnos & alumnos, ListaGrupos & grupos) {
	
	struct alumnoAux a;
	
	ifstream fentrada(fichero.c_str(), ios::in | ios::binary);
	
	if(fentrada.is_open() == false)
		return false;
	
	fentrada.read((char *)&a, sizeof(struct alumnoAux));
	
	do {
		
		Alumno alumnoNuevo(a.dni, a.nombre, a.apellidos, a.telefono, a.email, a.direccion, a.curso, a.d, a.m, a.y, a.grupo, a.lider);	
		
		alumnos.insertarAlumno(alumnoNuevo);
		
		if(a.grupo >= 0) {// El alumno tiene grupo
			
			if(grupos.existeGrupo(a.grupo) == false) // El grupo aún no está creado
				grupos.crearGrupo(a.grupo);
				
			Grupo * g = grupos.buscarGrupo(a.grupo);
			g->insertarAlumno(alumnoNuevo);
			
			if(a.lider == true)
				g->setLider(alumnos.buscarAlumno(a.dni));
		}
		
		fentrada.read((char *)&a, sizeof(struct alumnoAux));
		
	} while(!fentrada.eof());

	fentrada.close();
	
	return true;
}
