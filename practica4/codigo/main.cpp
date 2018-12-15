#include "funcionesAuxiliares.hpp"

int main() {
	
	int opcion;
	ListaAlumnos alumnos;
	ListaGrupos grupos;
	Profesor p;
	int sesion;
	
	// Se inicia sesión
	sesion = inicioSesion(p);
	
	// Si el usuario no existe
	if(sesion == -1) {
		cout << IRED << "\n\tEl nombre de usuario no existe.\n";
		return 0;
	}
	
	// Si la contraseña no existe
	if(sesion == -2) {
		cout << IRED << "\n\tContraseña incorrecta.\n";
		return 0;
	}
	
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
				cout << "[1] Listar alumnos" << endl;
				opcionListar(alumnos);
			break;
					
			case 2: 
				cout << "[2] Buscar alumno" << endl;
				opcionMostrar(alumnos);
			break;
			
			case 3: 
				cout << "[3] Mostrar grupo" << endl;
				opcionVerGrupo(alumnos, grupos);
			break;
			
			case 4: 
				cout << "[4] Insertar alumno nuevo" << endl;
				opcionInsertar(alumnos, grupos);
			break;

			case 5: 
				cout << "[5] Editar alumno" << endl;
				opcionEditar(alumnos, grupos);
			break;
					
			case 6: 
				cout << "[6] Borrar alumno" << endl;
				opcionBorrar(alumnos, grupos);
			break;
					
			case 7: 
				cout << "[7] Cargar fichero" << endl;
				opcionCargar(alumnos, grupos, p);
			break;
			
			case 8: 
				cout << "[8] Guardar fichero" << endl;
				opcionGuardar(alumnos, p);
			break;
			
			case 9:
				cout << "[9] Guardar copia de seguridad" << endl;
				opcionGuardarCopia(alumnos, p);
			break;
			
			case 10:
				cout << "[10] Cargar copia de seguridad" << endl;
				opcionCargarCopia(alumnos, grupos, p);
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
