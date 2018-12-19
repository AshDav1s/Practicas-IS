# HISTORIAS DE USUARIO

## (ANVERSO)

**ID:** 001 **Introducir alumno**

---- 

Como usuario quiero introducir los datos de un alumno para almacenarlos y poder consultarlos posteriormente.

**Prioridad:** 1

----

## (REVERSO)

---- 

* Quiero poder introducir el DNI, nombre, apellidos, teléfono, email, dirección, curso y fecha de nacimiento.

* De forma opcional, quiero poder introducir el equipo y si es líder o no.

* No se aceptarán DNI o email que ya existan.

----

----

----


## (ANVERSO)

**ID:** 002 **Buscar alumno**

----

Como usuario quiero poder buscar un alumno introducido.

**Prioridad:** 2

----

## (REVERSO)

----

* Quiero poder buscar alumnos a través de 3 de sus parámetros: DNI, Apellidos o email.

* Si hay alumnos con idéntico apellido se mostraran todos ellos.


----

----

----

## (ANVERSO)

**ID:** 003 **Listar alumnos**

----

Como usuario quiero ver una lista con todos los alumnos introducidos.

**Prioridad:** 2

----

## (REVERSO)

----

* Quiero poder mostrar los alumnos de dos formas distintas:
	* **Simple**: mostrando nombre, apellidos, grupo y líder
	* **Completa**: mostrando todos los campos introducidos
	
* Los alumnos serán ordenados según el parámetro que el usuario seleccione


----

----

----

	
## (ANVERSO)

**ID:** 004 **Mostrar alumno**

----

Tras buscar un alumno (ID 002) se mostrarán sus datos.

**Prioridad:** 3

----

## (REVERSO)	

----

* Quiero buscar un alumno según su DNI, apellidos o email

* Se mostrarán todos los datos del alumno

* Si dos alumnos comparten apellido, se mostrarán ambos

----

----

----


## (ANVERSO)

**ID:** 005 **Editar alumno**

----

Como usuario quiero seleccionar un alumno para poder editar sus datos sin modificar el resto.

**Prioridad:** 6

----

## (REVERSO)

----

* Quiero poder elegir un alumno según su DNI, apellidos o email

* Si dos alumnos comparten apellido, quiero elegir qué alumno editar

* Quiero poder modificar cualquier parámetro del alumno seleccionado

----

----

----


## (ANVERSO)

**ID:** 006 **Borrar alumno**

----

Como usuario quiero seleccionar un alumno para poder borrar sus datos.

**Prioridad:** 5

----

## (REVERSO)

----

* Quiero poder elegir un alumno segun su DNI o email.


----

----

----


## (ANVERSO)

**ID:** 007 **Cargar fichero**

----

Como usuario quiero seleccionar un fichero binario para poder cargar sus datos.

**Prioridad:** 4

----

## (REVERSO)

----

* Quiero poder cargar una lista de alumnos a partir de un fichero binario.

* El programa preguntará al usuario si quiere sobrescribir el fichero actual, si procede.

----

----

----

## (ANVERSO)

**ID:** 008 **Guardar fichero**

----

Como usuario quiero seleccionar un nombre de fichero para guardar la lista de alumnos actual. 

**Prioridad:** 4

----

## (REVERSO)

----

* Quiero poder guardar la lista de alumnos actual en un fichero binario.

* El programa preguntará al usuario si quiere sobrescribir el fichero introducido, si procede.

----
----
----

## (ANVERSO)
**ID:** 009 **Guardar copia de seguridad**

----

Como usuario coordinador quiero poder guardar una copia de seguridad en un fichero binario. 

**Prioridad:** 7

----

## (REVERSO)

----

* Quiero poder guardar una copia de seguridad de la lista de alumnos actual en un fichero binario.

* El sistema guardará la copia asignandole un nombre con el siguiente formato: copia_(fecha)_(hora).

----
----
----

## (ANVERSO)

**ID:** 010 **Cargar copia de seguridad**

----

Como usuario coordinador quiero poder cargar una copia de seguridad anteriormente almacenada.

**Prioridad:** 7

----

## (REVERSO)

----

* Quiero poder guardar la lista de alumnos actual en un fichero binario.

* El programa preguntará al usuario si quiere sobrescribir el fichero introducido, si procede.

----
----
----

## (ANVERSO)

**ID:** 011 **Iniciar sesion**

----

El sistema requerirá el inicio de sesión para acceder al programa y se iniciará en modo coordinador o ayudante. 

**Prioridad:** 6

----

## (REVERSO)

----

* Distinguirá entre coordinador y ayudante.

* Será necesario introducir login y contraseña para acceder al programa.

----
----
----

## (ANVERSO)

**ID:** 012 **Mostrar grupo**

----

El sistema mostrará un grupo y sus alumnos. 

**Prioridad:** 6

----

## (REVERSO)

----

* Indicará que alumno del grupo es el líder (si lo tiene).

* Se buscará el grupo por su ID.

----
----
----


