#include <iostream>
#include "macros.hpp"
#include <fstream>
#include <string.h>

using namespace std;

struct usuario {

	char nombre[100];
	char password[100];
	bool coordinador;
};
	
int menu();
void nuevoUsuario();
void verUsuarios();
void eliminarUsuario();

int main() {
	
	int opcion;
		
	do {

		// Se elige la opción del menú
		opcion = menu();		

		cout << CLEAR_SCREEN;
		LUGAR(5,7);

		// Se ejecuta la opción del menú elegida
		switch(opcion) {
	
			case 0: 
				cout << INVERSE;
				cout << "Fin del programa" << std::endl;
				cout << RESET;
			break;

			case 1: 
				cout << "[1] Ver usuarios" << endl;
				verUsuarios();
			break;
					
			case 2: 
				cout << "[2] Añadir usuario" << endl;
				nuevoUsuario();
			break;
			
			case 3: 
				cout << "[3] Eliminar usuario" << endl;
				eliminarUsuario();
			break;
			
			default:
				LUGAR(25,25);
				cout << INVERSE;
				cout << "Opción incorrecta ";
				cout << RESET;
			  	cout << RED;
				cout << " --> " << opcion << endl;
				cout << RESET;
		}
  
		if (opcion != 0) {
		
			LUGAR(30,5);
			cout << "pulse ";
			cout << UNDERLINE;
			cout << IYELLOW;
			cout << "ENTER";
			cout << RESET;
			cout << " para ";
			cout << INVERSE;
			cout << "continuar"; 
			cout << RESET;
			// Pausa
			cin.ignore();

			cout << CLEAR_SCREEN;
		}
		
	} while(opcion != 0);
	
	return 0; 	
}

void nuevoUsuario() {

	struct usuario u;
	int opcion;
	ofstream fsalida("usuarios.bin", ios::out | ios::binary | ios::app);
	
	cout << "\n\tNombre: ";
	cin.getline(u.nombre, 100);
	
	cout << "\n\tContraseña: ";
	cin.getline(u.password, 100);
	
	do {
		
		cout << "\n\tCoordinador\n";
		cout << "\t\t[1] Sí" << endl;
		cout << "\t\t[2] No" << endl;
		cout << "\t\t";
		
		cin >> opcion;
		
	} while(opcion!=1 and opcion!=2);
	
	if(opcion == 1)
		u.coordinador = true;
	else
		u.coordinador = false;
		
	fsalida.write((char*)&u, sizeof(struct usuario));
	
	fsalida.close();
}

void eliminarUsuario() {
	
	struct usuario u;
	char nombre[100];
	ifstream fentrada("usuarios.bin", ios::in | ios::binary);
	ofstream fsalida("temporal.bin", ios::out | ios::binary);
	
	cout << "\n\tNombre del usuario a borrar: ";
	cin.getline(nombre, 100);
	
	fentrada.read((char*)&u, sizeof(struct usuario));
	
	while(!fentrada.eof()) {
		
		if(strcmp(nombre, u.nombre) != 0) // si no coincide, se copia al otro fichero
			fsalida.write((char*)&u, sizeof(struct usuario));
		
		fentrada.read((char*)&u, sizeof(struct usuario));
	}
	
	fentrada.close();
	fsalida.close();
	remove("usuarios.bin");
	rename("temporal.bin", "usuarios.bin");
}

void verUsuarios() {
	
	struct usuario u;
	ifstream fentrada("usuarios.bin", ios::in | ios::binary);
	
	fentrada.read((char*)&u, sizeof(struct usuario));
	
	while(!fentrada.eof()) {
		
		cout << "\n\tNombre: " << u.nombre << endl;
		cout << "\tCoordinador: ";
		
		if(u.coordinador == true)
			cout << "Sí" << endl;
		else
			cout << "No" << endl;
			
		fentrada.read((char*)&u, sizeof(struct usuario));
	}
	
	fentrada.close();
}

int menu() {
	
	int opcion, posicion;

	// Se muestran las opciones del menú
	posicion=8;

	// Se borra la pantalla
	cout << CLEAR_SCREEN;

	LUGAR(5,10);
   cout << BBLUE;
	cout << "Programa para administrar usuarios | Opciones del menú";
	cout << RESET;

	LUGAR(posicion++,10);
	cout << "[1] Ver usuarios";
	
	LUGAR(posicion++,10);
	cout << "[2] Añadir usuario";
	
	LUGAR(posicion++,10);
	cout << "[3] Eliminar usuario";
	
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
