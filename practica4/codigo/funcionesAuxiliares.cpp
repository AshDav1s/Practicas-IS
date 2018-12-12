#include "funcionesAuxiliares.hpp"
#include <string.h>

void opcionBorrar(ListaAlumnos & alumnos, ListaGrupos & grupos) {
	
	int opcion;
	char aux[100];
	Alumno * a;
	Grupo * g;
	
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
	
	if(a->getLider() == true) {
		
		g = grupos.buscarGrupo(a->getIDgrupo());
		g->setLider(NULL);
		a->setLider(false);
	}
	
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
	
	if(opcion == 3) {
		
		cout << "\n\tDNI: ";
		cin.getline(aux, 100);
	
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
	
		if(a->setDNI(aux) == true)
			cout << IGREEN << "\n\tDNI modificado correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar el DNI." << RESET << endl;
	}
	
	if(opcion == 5) {
		
		cout << "\n\tEmail: ";
		cin.getline(aux, 100);
	
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
		cout << "\n\t\tAño: ";
		cin >> f.y;
		cout << "\t\tDía: ";
		cin >> f.d;
		cout << "\t\tMes: ";
		cin >> f.m;
	
		if(a->setFecha(f) == true)
			cout << IGREEN << "\n\tFecha de nacimiento modificada correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar la fecha de nacimiento." << RESET << endl;
	}
	
	if(opcion == 9) {
		
		cout << "\n\tID de grupo: ";
		cin >> auxiliar;
	
		if(grupos.existeGrupo(auxiliar) == false)
			grupos.crearGrupo(auxiliar);
			
		Grupo * g1 = grupos.buscarGrupo(auxiliar);
		Grupo * g2 = grupos.buscarGrupo(a->getIDgrupo());
		
		g1->insertarAlumno(*a);
		
		
		if(g2->getLider() == a)
			g2->setLider(NULL);
			
		a->setLider(false);
		
		if(a->setIDgrupo(auxiliar) == true)
			cout << IGREEN << "\n\tGrupo modificado correctamente." << RESET << endl;
		else
			cout << IRED << "\n\tError: no se pudo modificar el grupo." << RESET << endl;
	}
	
	if(opcion == 10) {
		
		if(a->getLider() == true) {
			
			Grupo * g = grupos.buscarGrupo(a->getIDgrupo());
			g->setLider(NULL);
			
			if(a->setLider(false) == true)
				cout << IGREEN << "\n\tCambios realizados con éxito." << RESET << endl;
			else
				cout << IRED << "\n\tError: no se pudieron efectuar los cambios." << RESET << endl;
		}
		
		else {
			
			if(a->getIDgrupo() < 0)
				cout << IRED << "\n\tError: el alumno debe pertenecer a un grupo primero." << RESET << endl;
				
			else {
				// Buscamos a qué grupo pertenece
				Grupo * g = grupos.buscarGrupo(a->getIDgrupo());
				
				// Si el grupo no tiene líder, se asigna directamente
				if(g->getLider() == NULL) {
					
					g->setLider(a);
					a->setLider(true);
					
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
						
						Alumno * a2 = g->getLider();
						a2->setLider(false);
						g->setLider(a);
						
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
	
	if(alumnos.estaVacia())
		cout << "\n\tLa lista de alumnos está vacía." << endl;
		
	else {
		
		do {
			cout << "\n\t¿Desea mostrar lista simple o completa?" << endl;
			cout << "\t\t[1] Simple" << endl;
			cout << "\t\t[2] Completa" << endl;
			cout << "\t\t";
	
			cin >> lista;
	
		} while(lista != 1  and  lista != 2);
		
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
	
	cout << "\tFecha de nacimiento\n\t\tAño: ";
	cin >> fecha.y;
	cout << "\t\tDía: ";
	cin >> fecha.d;
	cout << "\t\tMes: ";
	cin >> fecha.m;
	a.setFecha(fecha);
	
	do {
		cout << "\n\t¿Desea que el alumno pertenezca a algún grupo?" << endl;
		cout << "\t\t[1] Sí" << endl;
		cout << "\t\t[2] No" << endl;
		cout << "\t\t";
	
		cin >> auxiliar;
	
	} while(auxiliar != 1  and auxiliar != 2);
	
	if(auxiliar == 1) {
		
		cout << "\n\tID del grupo: ";
		cin >> auxiliar;
		a.setIDgrupo(auxiliar);
		
		if(grupos.existeGrupo(auxiliar) == false)
			grupos.crearGrupo(auxiliar);
		
		grupo = grupos.buscarGrupo(auxiliar);
		grupo->insertarAlumno(a);
		
		do {
			cout << "\n\t¿Desea que el alumno sea líder del grupo? (En caso afirmativo se sobreescribirá el anterior líder)" << endl;
			cout << "\t\t[1] Sí" << endl;
			cout << "\t\t[2] No" << endl;
			cout << "\t\t";
		
			cin >> auxiliar;
		
		} while(auxiliar != 1  and  auxiliar != 2);
			
		bool check = false;
		
		if(auxiliar == 1) {
		
			if(grupo->getLider() != NULL) 
				grupo->getLider()->setLider(false);
				
			a.setLider(true);
			check = alumnos.insertarAlumno(a);
			grupo->setLider(alumnos.buscarAlumno(a.getDNI()));
		}
		
		else
			check = alumnos.insertarAlumno(a);		

		if(check == true)
			cout << IGREEN << "\n\tAlumno insertado correctamente.\n" << RESET << endl;
		else
			cout << IRED << "\n\tError al insertar alumno.\n"  << RESET << endl;
	}
	
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
	cout << "[3] Insertar alumno nuevo";
	
	LUGAR(posicion++,10);
	cout << "[4] Editar alumno";
	
	LUGAR(posicion++,10);
	cout << "[5] Borrar alumno";
	
	LUGAR(posicion++,10);
	cout << "[6] Cargar fichero";
	
	LUGAR(posicion++,10);
	cout << "[7] Guardar fichero";
	
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
