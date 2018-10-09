# ESPECIFICACIÓN DE REQUISITOS

### DATOS A ALMACENAR

* DNI
* Nombre
* Apellidos
* Teléfono
* Email corporativo
* Dirección
* Curso más alto matriculado
* Fecha de nacimiento
* Equipo: Grupo de prácticas al que pertenece (opcional)
* Líder / No líder (opcional - no líder por defecto)

### REQUISITOS FUNCIONALES

* **RF1:** El programa debe permitir realizar la búsqueda de alumnos según los siguientes parámetros:
	* DNI
	* Apellidos
	* Email corporativo

* **RF2:** Se debe permitir la búsqueda de un grupo (mostrando los alumnos que lo forman).

* **RF3:** Se pueden editar y eliminar los datos de un alumno. Estas dos funcionalidades utilizarán la búsqueda especificada en el **RF1**.

* **RF4:** Debe mostrarse un menú principal que permita acceder a las diferentes funcionalidades del sistema.

* **RF5:** Se debe permitir al usuario tanto guardar un fichero con la información de los alumnos como cargar los datos de uno ya existente.

* **RF6:** Se podrá listar a los alumnos, ordenándolos en base a los siguientes parámetros:

	* Nombre
	* Apellidos
	* DNI
	* Curso más alto
	* Grupo al que pertenecen
	* Líder / No líder
	
	
La ordenación se podrá realizar tanto de forma ascendente como descendente.

### REQUISITOS NO FUNCIONALES

* **RNF1:** El software deberá funcionar en sistemas operativos Linux.

* **RNF2:** Respecto a la información almacenada de cada alumno, será opcional incluir el equipo y la opción de líder.

* **RNF3:** No podrá existir más de un líder en un mismo grupo.

* **RNF4:** Se permitirá la existencia de grupos sin líder.

* **RNF5:** La interfaz del programa se mostrará a través de línea de comandos.
	* **RNF5.1:** La interfaz será lo más sencilla y usable posible.
	* **RNF5.2:** La interfaz constará de un menú principal que permita acceder a las demás funcionalidades del programa.

* **RNF6:** Se dispondrá de un software diferente para cada profesor, de manera que no será necesario un login.

* **RNF7:** Los grupos no tendrán un límite de alumnos.

* **RNF8:** El sistema no podrá almacenar más de 150 alumnos.

* **RNF9:** El programa deberá mostrarse como mínimo en idioma español.

* **RNF10:** La longitud máxima de los campos a almacenar será la siguiente:
	* Nombre: 50 caracteres
	* Apellidos: 50 caracteres
	* DNI: 9 caracteres
	* Email: 50 caracteres
	* Dirección: 100 caracteres
	* Curso más alto matriculado: 1 caracter numérico
	* Fecha de nacimiento: 10 caracteres
	* Equipo: 3 caracteres numéricos
	* Líder: booleano

* **RNF11:** El programa imprimirá las listas solicitadas por línea de comandos o en un fichero HTML.

* **RNF12:** No se permitirá introducir dos alumnos con el mismo DNI, por tanto este se utilizará como identificador principal de los alumnos.

