OBJETOS = main.o alumno.o listaAlumnos.o funcionesAuxiliares.o grupo.o listaGrupos.o profesor.o
CPPFLAGS = -c -g -Wall -ansi -std=c++0x

objetivo: alumnos.exe

alumnos.exe: $(OBJETOS)
	@echo Creando ejecutable...
	@g++ -o alumnos.exe $(OBJETOS)
					
main.o: main.cpp funcionesAuxiliares.hpp
	@echo Creando main.o...
	@g++ $(CPPFLAGS) main.cpp 

listaAlumnos.o: listaAlumnos.cpp  listaAlumnos.hpp alumno.hpp
	@echo Creando listaAlumnos.o...
	@g++ $(CPPFLAGS) listaAlumnos.cpp 

alumno.o: alumno.cpp alumno.hpp
	@echo Creando alumno.o...
	@g++ $(CPPFLAGS) alumno.cpp 
  
funcionesAuxiliares.o: funcionesAuxiliares.cpp funcionesAuxiliares.hpp listaAlumnos.hpp
	@echo Creando funcionesAuxiliares.o...
	@g++ $(CPPFLAGS) funcionesAuxiliares.cpp 
	
grupo.o: grupo.cpp grupo.hpp listaAlumnos.hpp
	@echo Creando grupo.o...
	@g++ $(CPPFLAGS) grupo.cpp 
	
listaGrupos.o: listaGrupos.cpp listaGrupos.hpp grupo.hpp
	@echo Creando listaGrupos.o...
	@g++ $(CPPFLAGS) listaGrupos.cpp
	
profesor.o: profesor.cpp profesor.hpp listaGrupos.hpp
	@echo Creando profesor.o...
	@g++ $(CPPFLAGS) profesor.cpp
	
.PHONY: clean  
clean:
	@echo Eliminando objetos...
	@rm -f $(OBJETOS) *~ s
