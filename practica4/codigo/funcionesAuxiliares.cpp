#include "funcionesAuxiliares.hpp"
#include <string.h>

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
