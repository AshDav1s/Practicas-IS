#include "funcionesAuxiliares.hpp"

int main() {
	
	int opcion;
	ListaAlumnos alumnos;
	ListaGrupos grupos;
	
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
			break;
			
			case 3: 
				cout << "[3] Insertar alumno nuevo" << endl;
				opcionInsertar(alumnos, grupos);
			break;

			case 4: 
				cout << "[4] Editar alumno" << endl;
			break;
					
			case 5: 
				cout << "[5] Borrar alumno" << endl;
			break;
					
			case 6: 
				cout << "[6] Cargar fichero" << endl;
			break;
			
			case 7: 
				cout << "[7] Guardar fichero" << endl;
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
