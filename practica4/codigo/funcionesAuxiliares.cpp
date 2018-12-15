#include "funcionesAuxiliares.hpp"
#include <string.h>

void opcionVerGrupo(ListaAlumnos & alumnos, ListaGrupos & grupos) {
	
		int id;
		Grupo * g;
		
		cout << "\n\tID del grupo: ";
		cin >> id;
		
		cin.ignore();
		
		// Se comprueba que el grupo existe
		if(not grupos.existeGrupo(id)) {
			
			cout << IRED << "\n\tError: no existe el grupo <" << id << ">.\n" << RESET;
			return;
		}
		
		// Buscamos el grupo
		g = grupos.buscarGrupo(id);
		
		cout << "\n\tGRUPO " << id << ":\n\n";
		
		// Imprimimos los miembros uno a uno
		for(int i=0; i<g->getSize(); i++) {
			
			string dni = g->getAlumno(i);
			Alumno * a = alumnos.buscarAlumno(dni);
			
			cout << "\t" << a->getApellidos() << ", " << a->getNombre();
			
			if(a->getLider() == true) // Mostramos si un miembro es líder
				cout << " (líder)\n";
			else
				cout << endl;
		}
}
	
bool existeFichero(char * fichero) {
	
	ifstream fentrada(fichero, ios::in | ios::binary);
	return fentrada.good();
}

void opcionCargarCopia(ListaAlumnos & alumnos, ListaGrupos & grupos, Profesor & p) {
	
	char fichero[100];
	
	// Comprobamos que el usuario sea coordinador
	if(p.getCoordinador() == false) {
		
		cout << IRED << "\n\tNecesita ser coordinador para acceder a esta opción.\n" << RESET;
		return;
	}
	
	if(not alumnos.estaVacia() or not grupos.estaVacia()) {
		
		int opcion; 
		
		do {
			
			cout << IYELLOW << "\n\tSe perderán los datos que no haya guardado, ¿desea continuar?" << endl;
			cout << "\t\t[1] Sí\n";
			cout << "\t\t[2] No\n\t\t";
			
			cin >> opcion;
			
		} while(opcion!=1 and opcion!=2);
	
		if(opcion == 2)
			return;
	}
	
	cout << "\n\tNombre del fichero: ";
	cin.getline(fichero, 100);
	
	// Comprobamos que el fichero exista
	if(not existeFichero(fichero)) {
		
			cout << IRED << "\n\tError: el fichero <" << fichero << "> no existe." << RESET << endl;
			return;
	}
	
	p.setFichero(fichero);
	
	// Cargamos fichero
	if(p.cargarFichero(alumnos, grupos) == true)
		cout << IGREEN << "\n\tFichero cargado correctamente." << RESET <<endl;
	else
		cout << IRED << "\n\tError al cargar fichero." << RESET << endl;
}

void opcionCargar(ListaAlumnos & alumnos, ListaGrupos & grupos, Profesor & p) {
	
	char fichero[100];
	
	if(not alumnos.estaVacia() or not grupos.estaVacia()) {
		
		int opcion; 
		
		do {
			
			cout << IYELLOW << "\n\tSe perderán los datos que no haya guardado, ¿desea continuar?" << endl;
			cout << "\t\t[1] Sí\n";
			cout << "\t\t[2] No\n\t\t";
			
			cin >> opcion;
			
		} while(opcion!=1 and opcion!=2);
	
		if(opcion == 2)
			return;
	}
	
	cout << "\n\tNombre del fichero: ";
	cin.getline(fichero, 100);
	
	// Comprobamos que exista
	if(not existeFichero(fichero)) {
		
			cout << IRED << "\n\tError: el fichero <" << fichero << "> no existe." << RESET << endl;
			return;
	}
	
	// Comprobamos que el fichero no sea una copia de seguridad (empieza por "copia_")
	if(strncmp(fichero, "copia_", 6) == 0) {
		
			cout << IRED << "\n\tError: para cargar una copia de seguridad use la opción 10 del menú." << RESET << endl;
			return;
	}
	
	p.setFichero(fichero);
	
	// Cargamos fichero
	if(p.cargarFichero(alumnos, grupos) == true)
		cout << IGREEN << "\n\tFichero cargado correctamente." << RESET <<endl;
	else
		cout << IRED << "\n\tError al cargar fichero." << RESET << endl;
}

void opcionGuardarCopia(ListaAlumnos & alumnos, Profesor & p) {
	
	// Comprobamos que el usuario es coordinador
	if(p.getCoordinador() == false) {
		
		cout << IRED << "\n\tNecesita ser coordinador para acceder a esta opción.\n" << RESET;
		return;
	}
	
	// Guardamos
	if(p.guardarCopia(alumnos) == true)
		cout << IGREEN << "\n\tCopia guardada correctamente." << RESET <<endl;
	else
		cout << IRED << "\n\tError al guardar copia." << RESET << endl;
		
}
	
void opcionGuardar(ListaAlumnos & alumnos, Profesor & p) {
	
	char fichero[100];
	int opcion;
	
	cout << "\n\tNombre del fichero: ";
	cin.getline(fichero, 100);
	
	// Comprobamos si el fichero ya existe y si el usuario desea sobreescribirlo
	if(existeFichero(fichero)) {
		
		do {
		
			cout << "\n\tEl fichero <" << fichero << "> ya existe, ¿desea sobreescribirlo?:" << endl;
			cout << "\t\t[1] Sí\n";
			cout << "\t\t[2] No\n\t\t";
			
			cin >> opcion;
			
		} while(opcion!=1 and opcion!=2);
		
		if(opcion == 2)
			return;
	}
	
	p.setFichero(fichero);
	
	// Guardamos
	if(p.guardarFichero(alumnos) == true)
		cout << IGREEN << "\n\tFichero guardado correctamente." << RESET <<endl;
	else
		cout << IRED << "\n\tError al guardar fichero." << RESET << endl;
		
	cin.ignore();
}

void opcionBorrar(ListaAlumnos & alumnos, ListaGrupos & grupos) {
	
	int opcion;
	char aux[100];
	Alumno * a;
	Grupo * g;
	
	// Parámetro para buscar al alumno
	do {
	
		cout << "\n\tSeleccione parámetro de búsqueda." << endl;
		cout << "\t\t[1] DNI" << endl;
		cout << "\t\t[2] Email" << endl;
		cout << "\t\t";
		
		cin >> opcion;
		cin.ignore();
		
	} while(opcion != 1  and  opcion != 2);
	
	if(opcion == 1) { // Buscamos por DNI
		
		cout << "\n\tDNI: ";
		cin.getline(aux, 100);
		
		if(alumnos.existeAlumno(aux)) {
			
			a = alumnos.buscarAlumno(aux);
		}
		else {
			cout << IRED << "\n\tError: el alumno con dni <" << aux << "> no está en el sistema." << RESET << endl;
			return;	
		}
	}
	
	if(opcion == 2) { // Buscamos por email
		
		cout << "\n\tEmail: ";
		cin.getline(aux, 100);
		
		if(alumnos.existeAlumnoEmail(aux)) {
			
			a = alumnos.buscarAlumnoEmail(aux);
		}
		else {
			cout << IRED << "\n\tError: el alumno con email <" << aux << "> no está en el sistema." << RESET << endl;
			return;	
		}
	}
	
	// Comprobamos si el alumno pertenece a algún grupo
	if(a->getIDgrupo() >= 0) {
	
		// Buscamos a qué grupo pertenece
		g = grupos.buscarGrupo(a->getIDgrupo());
		
		// En caso de que el alumno sea líder
		if(a->getLider() == true) {
			g->setLider("");
			a->setLider(false);
		}
		//Eliminamos al alumno del grupo
		g->eliminarAlumno(a->getDNI());
		
		// Si el grupo queda vacío se borra
		if(g->estaVacio())
			grupos.eliminarGrupo(g->getID());
	}

	// Se elimina al alumno	
	if(alumnos.eliminarAlumno(a->getDNI()) == true)
		cout << IGREEN << "\n\tAlumno eliminado correctamente." << RESET << endl;
	
	else
		cout << IRED << "\n\tError: no se pudo borrar el alumno." << RESET << endl;
	
}

void opcionEditar(ListaAlumnos & alumnos, ListaGrupos & grupos) {

	Alumno * a;
	int opcion;
	char aux[100];
	int auxiliar;
	
	// Preguntamos parámetro de búsqueda y buscamos al alumno
	do {
	
		cout << "\n\tSeleccione parámetro de búsqueda." << endl;
		cout << "\t\t[1] DNI" << endl;
		cout << "\t\t[2] Email" << endl;
		cout << "\t\t";
		
		cin >> opcion;
		cin.ignore();
		
	} while(opcion != 1  and  opcion != 2);
	
	if(opcion == 1) {
		
		cout << "\n\tDNI: ";
		cin.getline(aux, 100);
		
		if(alumnos.existeAlumno(aux)) {
			
			a = alumnos.buscarAlumno(aux);
		}
		else {
			cout << IRED << "\n\tError: el alumno con dni <" << aux << "> no está en el sistema." << RESET << endl;
			return;	
		}
	}
	
	if(opcion == 2) {
		
		cout << "\n\tEmail: ";
		cin.getline(aux, 100);
		
		if(alumnos.existeAlumnoEmail(aux)) {
			
			a = alumnos.buscarAlumnoEmail(aux);
		}
		else {
			cout << IRED << "\n\tError: el alumno con email <" << aux << "> no está en el sistema." << RESET << endl;
			return;	
		}
	}
	
	// Preguntamos parámetro a modificar y mostramos el actual valor
	do {
	
		cout << "\n\tSeleccione parámetro a modificar." << endl;
		cout << "\t\t[1] Nombre (actual: " << a->getNombre() << ")" << endl;
		cout << "\t\t[2] Apellidos (actual: " << a->getApellidos() << ")" << endl;
		cout << "\t\t[3] DNI (actual: " << a->getDNI() << ")" << endl;
		cout << "\t\t[4] Teléfono (actual: " << a->getTelefono() << ")" << endl;
		cout << "\t\t[5] Email (actual: " << a->getEmail() << ")" << endl;
		cout << "\t\t[6] Dirección (actual: " << a->getDireccion() << ")" << endl;
		cout << "\t\t[7] Curso más alto (actual: " << a->getCurso() << ")" << endl;
		cout << "\t\t[8] Fecha de nacimiento (actual: " << a->getFecha().d << "-" << a->getFecha().m << "-" << a->getFecha().y << ")" << endl;
		cout << "\t\t[9] Grupo (actual: " << a->getIDgrupo() << ")" << endl;
		cout << "\t\t[10] Líder (actual: "; 
			if(a->getLider() == true)
				cout << "Sí)" << endl;
			else
				cout << "No)" << endl;
				
		cout << "\t\t";
		
		cin >> opcion;
		cin.ignore();
		
	} while(opcion < 1  or  opcion > 10);
	
	// Dependiendo de la opción seleccionada se modifica
	
	if(opcion == 3) {
		
		cout << "\n\tDNI: ";
		cin.getline(aux, 100);
	
		// Comprobamos que sea un dni válido
		while(strlen(aux) > 9 or strlen(aux) < 9) {
		
			cout << IRED << "\n\tError: dni no válido." << endl;
			cout << RESET << "\n\tDNI: ";
			cin.getline(aux, 100);
		}
	
		// Comprobamos que no esté repetido el dni
		while(alumnos.existeAlumno(aux)) {
		
			cout << IRED << "\n\tError: ya existe un alumno con el dni <" << aux << ">." << endl;
			cout << RESET << "\n\tDNI: ";
			cin.getline(aux, 100);
		}
	
		if(a->setDNI(aux) == true)
			cout << IGREEN << "\n\tDNI modificado correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar el DNI." << RESET << endl;
	}
	
	if(opcion == 5) {
		
		cout << "\n\tEmail: ";
		cin.getline(aux, 100);
	
		// Comprobamos que no esté repetido el email
		while(alumnos.existeAlumnoEmail(aux)) {
		
			cout << IRED << "\n\tError: ya existe un alumno con el email <" << aux << ">." << endl;
			cout << RESET << "\n\tEmail: ";
			cin.getline(aux, 100);
		}
	
		if(a->setEmail(aux) == true)
			cout << IGREEN << "\n\tEmail modificado correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar el Email." << RESET << endl;
	}
	
	if(opcion == 1) {
		
		cout << "\n\tNombre: ";
		cin.getline(aux, 100);
	
		if(a->setNombre(aux) == true)
			cout << IGREEN << "\n\tNombre modificado correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar el nombre." << RESET << endl;
	}
	
	if(opcion == 2) {
		
		cout << "\n\tApellidos: ";
		cin.getline(aux, 100);
	
		if(a->setApellidos(aux) == true)
			cout << IGREEN << "\n\tApellidos modificados correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudieron modificar los apellidos." << RESET << endl;
	}
	
	if(opcion == 4) {
		
		cout << "\n\tTeléfono: ";
		cin >> auxiliar;
	
		if(a->setTelefono(auxiliar) == true)
			cout << IGREEN << "\n\tTeléfono modificado correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar el teléfono." << RESET << endl;
	}
	
	if(opcion == 6) {
		
		cout << "\n\tDirección: ";
		cin.getline(aux, 100);
	
		if(a->setDireccion(aux) == true)
			cout << IGREEN << "\n\tDirección modificada correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar la dirección." << RESET << endl;
	}
	
	if(opcion == 7) {
		
		cout << "\n\tCurso: ";
		cin >> auxiliar;
	
		if(a->setCurso(auxiliar) == true)
			cout << IGREEN << "\n\tCurso modificado correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar el curso." << RESET << endl;
	}
	
	if(opcion == 8) {
		
		struct date f;
		
		cout << "\n\tFecha de nacimiento: ";
		cout << "\n\t\tDía: ";
		cin >> f.d;
		cout << "\t\tMes: ";
		cin >> f.m;
		cout << "\t\tAño: ";
		cin >> f.y;
	
		if(a->setFecha(f) == true)
			cout << IGREEN << "\n\tFecha de nacimiento modificada correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar la fecha de nacimiento." << RESET << endl;
	}
	
	if(opcion == 9) {
		
		cout << "\n\tID de grupo: ";
		cin >> auxiliar;
	
		// Si el grupo no existe aún, se crea
		if(grupos.existeGrupo(auxiliar) == false)
			grupos.crearGrupo(auxiliar);
		
		// Buscamos el grupo nuevo (g1) y el actual (g2)
		Grupo * g1 = grupos.buscarGrupo(auxiliar);
		Grupo * g2 = grupos.buscarGrupo(a->getIDgrupo());
		
		// Insertamos al alumno en el grupo nuevo
		g1->insertarAlumno(a->getDNI());
		
		// En caso de que el alumno fuese líder en su anterior grupo, se modifica
		if(g2->getLider() == a->getDNI())
			g2->setLider("");
			
		a->setLider(false);
		
		if(a->setIDgrupo(auxiliar) == true)
			cout << IGREEN << "\n\tGrupo modificado correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar el grupo." << RESET << endl;
	}
	
	if(opcion == 10) {
		
		// Si el alumno era líder de su grupo
		if(a->getLider() == true) {
			
			// Buscamos el grupo y eliminamos su líder
			Grupo * g = grupos.buscarGrupo(a->getIDgrupo());
			g->setLider("");
			
			if(a->setLider(false) == true)
				cout << IGREEN << "\n\tCambios realizados con éxito." << RESET << endl;
			else
				cout << IRED << "\n\tError: no se pudieron efectuar los cambios." << RESET << endl;
		}
		
		// Si el alumno no era líder
		else {
			
			// Comprobamos que pertenezca a algún grupo
			if(a->getIDgrupo() < 0)
				cout << IRED << "\n\tError: el alumno debe pertenecer a un grupo primero." << RESET << endl;
				
			else {
				// Buscamos a qué grupo pertenece
				Grupo * g = grupos.buscarGrupo(a->getIDgrupo());
				
				// Si el grupo no tiene líder, se asigna
				if(g->getLider() == "") {
					
					g->setLider(a->getDNI());
					
					if(a->setLider(true) == true)
						cout << IGREEN << "\n\tCambios realizados con éxito." << RESET << endl;
					else
						cout << IRED << "\n\tError: no se pudieron efectuar los cambios." << RESET << endl;
				}
				
				// Si el grupo ya tiene un líder se sobreescribe
				else {
					
					do {
	
						cout << "\n\tEl grupo ya tiene líder, ¿desea sobreescribirlo?." << endl;
						cout << "\t\t[1] Sí" << endl;
						cout << "\t\t[2] No" << endl;
						cout << "\t\t";
		
						cin >> opcion;
						cin.ignore();
		
					} while(opcion != 1  and  opcion != 2);
				
					if(opcion == 1) {
						
						string liderAntiguo = g->getLider();
						Alumno * a2 = alumnos.buscarAlumno(liderAntiguo);
						a2->setLider(false);
						g->setLider(a->getDNI());
						
						if(a->setLider(true) == true)
							cout << IGREEN << "\n\tCambios realizados con éxito." << RESET << endl;
						else
							cout << IRED << "\n\tError: no se pudieron efectuar los cambios." << RESET << endl;
					}
					
					else
						cout << "\n\tNo se ha realizado ningún cambio." << endl;
				}
				
			}
		}
	}
}

void opcionMostrar(ListaAlumnos & alumnos) {

	int opcion;
	char aux[100];
	
	// Seleccionamos parámetro de búsqueda
	do {
	
		cout << "\n\tSeleccione parámetro de búsqueda." << endl;
		cout << "\t\t[1] DNI" << endl;
		cout << "\t\t[2] Apellidos" << endl;
		cout << "\t\t[3] Email" << endl;
		cout << "\t\t";
		
		cin >> opcion;
		cin.ignore();
		
	} while(opcion < 1  or  opcion > 3);
	
	if(opcion == 1) {
	
		cout << "\n\tDNI: ";
		cin.getline(aux, 100);
		
		if(alumnos.existeAlumno(aux)) {
			
			cout << CLEAR_SCREEN;
			LUGAR(5,7);
			
			alumnos.buscarAlumno(aux)->imprimirAlumno(2);	
		}
		else
			cout << IRED << "\n\tError: el alumno con dni <" << aux << "> no está en el sistema." << RESET << endl;
	}
	
	if(opcion == 2) {
	
		cout << "\n\tApellidos: ";
		cin.getline(aux, 100);
						
		// En el caso de los apellidos, mostramos todos los alumnos que coincidan 
		vector<Alumno> v = alumnos.buscarAlumnoApellidos(aux);	
			
		if(v.empty())
			cout << IRED << "\n\tError: no existe ningún alumno con los apellidos <" << aux << ">." << RESET << endl;
				
		else {
				
			cout << CLEAR_SCREEN;
			LUGAR(5,7);
				
			for(unsigned int i=0; i<v.size(); i++) {
				v[i].imprimirAlumno(2);
				cout << endl;
			}
		}
	}		
	
	if(opcion == 3) {
	
		cout << "\n\tEmail: ";
		cin.getline(aux, 100);
		
		if(alumnos.existeAlumnoEmail(aux)) {
			
			cout << CLEAR_SCREEN;
			LUGAR(5,7);
			
			alumnos.buscarAlumnoEmail(aux)->imprimirAlumno(2);	
		}
		else
			cout << IRED << "\n\tError: el alumno con email <" << aux << "> no está en el sistema." << RESET << endl;
	}
}

void opcionListar(ListaAlumnos & alumnos) {
	
	int lista, param, orden, html;
	
	//Comprobamos que existan alumnos en el sistema
	if(alumnos.estaVacia())
		cout << "\n\tLa lista de alumnos está vacía." << endl;
		
	else {
		
		// Preguntamos si se va a mostrar nombre y apellidos o lista completa
		do {
			cout << "\n\t¿Desea mostrar lista simple o completa?" << endl;
			cout << "\t\t[1] Simple" << endl;
			cout << "\t\t[2] Completa" << endl;
			cout << "\t\t";
	
			cin >> lista;
	
		} while(lista != 1  and  lista != 2);
		
		// Parámetro de ordenación
		do {
			cout << "\n\t¿Según qué parámetro desea ordenar la lista?" << endl;
			cout << "\t\t[1] Nombre" << endl;
			cout << "\t\t[2] Apellidos" << endl;
			cout << "\t\t[3] DNI" << endl;
			cout << "\t\t[4] Curso" << endl;
			cout << "\t\t[5] Grupo" << endl;
			cout << "\t\t[6] Líder" << endl;
			
			cout << "\t\t";
	
			cin >> param;
	
		} while(param < 1  and  param > 6);

		do {
			cout << "\n\t¿Desea ordenarla ascendente o descendentemente?" << endl;
			cout << "\t\t[1] Ascendente" << endl;
			cout << "\t\t[2] Descendente" << endl;
			cout << "\t\t";
	
			cin >> orden;
	
		} while(orden != 1  and  orden != 2);

		do {
			cout << "\n\t¿Desea imprimir por terminal o en un fichero .html?" << endl;
			cout << "\t\t[1] Terminal" << endl;
			cout << "\t\t[2] HTML" << endl;
			cout << "\t\t";
	
			cin >> html;
	
		} while(html != 1  and  html != 2);		
		
		
		cout << CLEAR_SCREEN;
		
		LUGAR(5,7);
		
		if(html == 1)
			alumnos.listarAlumnos(lista, param, orden);
		
		else {
			
			char fichero[50];
			cout << "\n\tNombre del fichero: ";
			cin >> fichero;
			alumnos.listarAlumnosHTML(fichero, lista, param, orden);
		}
		
		cin.ignore();	
	}
}

void opcionInsertar(ListaAlumnos & alumnos, ListaGrupos & grupos) {
	
	struct date fecha;
	Grupo * grupo;
	Alumno a;
	char aux[100];
	int auxiliar;
	
	cout << "\n\tDNI: ";
	cin.getline(aux, 100);
	
	// Comprobamos si el dni es válido y no existe ya
	
	while(strlen(aux) > 9 or strlen(aux) < 9) {
		
		cout << IRED << "\n\tError: dni no válido." << endl;
		cout << RESET << "\n\tDNI: ";
		cin.getline(aux, 100);
	}
	
	while(alumnos.existeAlumno(aux)) {
		
		cout << IRED << "\n\tError: ya existe un alumno con el dni <" << aux << ">." << endl;
		cout << RESET << "\n\tDNI: ";
		cin.getline(aux, 100);
	}
	
	a.setDNI(aux);
	
	cout << "\tEmail: ";
	cin.getline(aux, 100);
	
	// Comprobamos que el email no está repetido
	while(alumnos.existeAlumnoEmail(aux)) {
		
		cout << IRED << "\n\tError: ya existe un alumno con el email <" << aux << ">." << endl;
		cout << RESET << "\n\tEmail: ";
		cin.getline(aux, 100);
	}
	
	a.setEmail(aux);
	
	cout << "\tNombre: ";
	cin.getline(aux, 100);
	a.setNombre(aux);
	
	cout << "\tApellidos: ";
	cin.getline(aux, 100);
	a.setApellidos(aux);
	
	cout << "\tTeléfono: ";
	cin >> auxiliar;
	cin.ignore();
	a.setTelefono(auxiliar);
	
	cout << "\tDirección: ";
	cin.getline(aux, 100);
	a.setDireccion(aux);
	
	cout << "\tCurso más alto matriculado: ";
	cin >> auxiliar;
	a.setCurso(auxiliar);
	
	cout << "\tFecha de nacimiento\n\t\tDía: ";
	cin >> fecha.d;
	cout << "\t\tMes: ";
	cin >> fecha.m;
	cout << "\t\tAño: ";
	cin >> fecha.y;
	a.setFecha(fecha);
	
	do {
		cout << "\n\t¿Desea que el alumno pertenezca a algún grupo?" << endl;
		cout << "\t\t[1] Sí" << endl;
		cout << "\t\t[2] No" << endl;
		cout << "\t\t";
	
		cin >> auxiliar;
	
	} while(auxiliar != 1  and auxiliar != 2);
	
	// En caso de que el alumno pertenezca a un grupo
	if(auxiliar == 1) {
		
		cout << "\n\tID del grupo: ";
		cin >> auxiliar;
		
		while(auxiliar < 0) {
			 
			cout << IRED << "\n\tID de grupo negativo." << RESET << endl;
			cout << "\n\tID del grupo: ";
			cin >> auxiliar;
		}
		
		//Asignamos el id al alumno
		a.setIDgrupo(auxiliar);
		
		// Si el grupo no existe aún, se crea
		if(grupos.existeGrupo(auxiliar) == false)
			grupos.crearGrupo(auxiliar);
		
		// Buscamos grupo e insertamos al alumno
		grupo = grupos.buscarGrupo(auxiliar);
		grupo->insertarAlumno(a.getDNI());
		
		do {
			cout << "\n\t¿Desea que el alumno sea líder del grupo? (En caso afirmativo se sobreescribirá el anterior líder)" << endl;
			cout << "\t\t[1] Sí" << endl;
			cout << "\t\t[2] No" << endl;
			cout << "\t\t";
		
			cin >> auxiliar;
		
		} while(auxiliar != 1  and  auxiliar != 2);
			
		bool check = false;
		
		// Si el alumno es líder
		if(auxiliar == 1) {
		
			// Si el grupo tenía otro lider
			if(grupo->getLider() != "") { 
				// Buscamos al líder actual y lo modificamos
				string dniLider =	grupo->getLider();
				alumnos.buscarAlumno(dniLider)->setLider(false);
			}
			
			// Asignamos al nuevo alumno como líder y le insertamos en la lista de alumnos
			a.setLider(true);
			check = alumnos.insertarAlumno(a);
			grupo->setLider(a.getDNI());
		}
		
		else
			check = alumnos.insertarAlumno(a);		

		if(check == true)
			cout << IGREEN << "\n\tAlumno insertado correctamente.\n" << RESET << endl;
		else
			cout << IRED << "\n\tError al insertar alumno.\n"  << RESET << endl;
	}
	
	// Si el alumno no tiene grupo se le asigna un id negativo y se inserta
	else {
		
		a.setIDgrupo(-1);
		a.setLider(NULL);
		bool check = alumnos.insertarAlumno(a);		

		if(check == true)
			cout << IGREEN << "\n\tAlumno insertado correctamente.\n" << RESET << endl;
		else
			cout << IRED << "\n\tError al insertar alumno.\n"  << RESET << endl;
	}
	
	cin.ignore();
}

int inicioSesion(Profesor & p) {
	
	char nombre[100];
	char password[100];
	struct usuario u;
	bool encontrado = false;
	bool coincidencia = false;
	
	// Preguntamos usuario
	cout << "\n\tNombre de usuario: ";
	cin.getline(nombre, 100);
	
	// Abrimos el fichero con los usuarios
	ifstream fentrada("usuarios.bin", ios::in | ios::binary);
	
	// Buscamos al usuario
	fentrada.read((char*)&u, sizeof(struct usuario));
	
	while(!fentrada.eof()) {
		
		// Si encontramos al usuario
		if(strcmp(u.nombre, nombre) == 0) {
			
			// Preguntamos password
			cout << "\tContraseña: ";
			cin.getline(password, 100);
			
			// Comprobamos si coincide
			if(strcmp(u.password, password) == 0) {
				coincidencia = true;
			}
			
			encontrado = true;
			break;
		}
		
		fentrada.read((char*)&u, sizeof(struct usuario));
	}
	
	fentrada.close();
	
	//Si el usuario no existe o no coincide la contraseña, devolvemos códigos de error negativos
	if(encontrado == false)
		return -1;
		
	if(coincidencia == false)
		return -2;
		
	p.setCoordinador(u.coordinador);
	
	return 1; // Si el usuario y contraseña son válidos se devuelve 1
}

int menu() {
	
	int opcion, posicion;
	
	// Se muestran las opciones del menú
	posicion=8;

	// Se borra la pantalla
	cout << CLEAR_SCREEN;

	LUGAR(5,10);
   cout << BBLUE;
	cout << "Programa principal | Opciones del menú";
	cout << RESET;

	LUGAR(posicion++,10);
	cout << "[1] Listar alumnos";
	
	LUGAR(posicion++,10);
	cout << "[2] Buscar alumno";
	
	LUGAR(posicion++,10);
	cout << "[3] Mostrar grupo";
	
	LUGAR(posicion++,10);
	cout << "[4] Insertar alumno nuevo";
	
	LUGAR(posicion++,10);
	cout << "[5] Editar alumno";
	
	LUGAR(posicion++,10);
	cout << "[6] Borrar alumno";
	
	LUGAR(posicion++,10);
	cout << "[7] Cargar fichero";
	
	LUGAR(posicion++,10);
	cout << "[8] Guardar fichero";
	
	LUGAR(posicion++,10);
	cout << "[9] Guardar copia de seguridad";
	
	LUGAR(posicion++,10);
	cout << "[10] Cargar copia de seguridad";
	
	LUGAR(posicion++,10);	
	cout << GREEN << "[0] Salir";

	LUGAR(posicion++,20);
	cout << IYELLOW;
	cout << "Opción: ";
	cout << RESET;

	// Se lee el número de opción
	cin >> opcion;

   // Se elimina el salto de línea del flujo de entrada
	cin.ignore();

	return opcion;
}
