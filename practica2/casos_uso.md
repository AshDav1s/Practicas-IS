# CASOS DE USO

### Introducir alumno

**ID:** 001
**Breve descripción**: El usuario introduce los datos de un alumno.

**Actores principales:** Usuario.
**Actores secundarios:** Alumno.

**Precondiciones:**

1. El usuario no puede existir anteriormente en el sistema.
2. Tanto DNI como email no pueden coincidir con los de otros alumnos.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita introducir un alumno.
2. El sistema pregunta de forma secuencial los posibles datos del alumno.
3. El alumno se almacena en la base de datos.

**Postcondiciones:**

* El alumno está introducido en el sistema.

**Flujos alternativos:**

2.a. Si el alumno introducido es líder del grupo, se preguntará si se desea sobreescribir el anterior líder en caso de que este exista.
3.a. Si ya existe un alumno con el DNI introducido para el nuevo alumno, el sistema muestra un mensaje de error y el alumno no se introduce.
3.b. Si el valor de alguno de los campos del alumno no es válido, el sistema muestra un mensaje de error y el alumno no se introduce.




### Buscar alumno

**ID:** 002
**Breve descripción**: El sistema busca los datos de un alumno.

**Actores principales:** Ninguno.
**Actores secundarios:** Alumno.

**Precondiciones:** 

1. El alumno debe existir en el sistema.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita buscar un alumno.
2. El sistema busca al alumno según los parámetros escogidos.

**Postcondiciones:**

* El sistema recoge los datos del alumno.

**Flujos alternativos:**

2.a. Si no existe el alumno, el sistema muestra un mensaje de error.




### Listar alumnos

**ID:** 003
**Breve descripción**: El sistema muestra una lista con todos los alumnos.

**Actores principales:** Usuario.
**Actores secundarios:** Alumno,

**Precondiciones:**

1. Debe existir algún alumno en el sistema.

**Flujo principal:**

1. El caso de uso comienza cuando el sistema necesita mostrar la lista de alumnos.
2. El sistema pregunta si la lista debe ser mostrada de forma simple o completa.
3. El sistema pregunta si la lista quiere ser ordenada con respecto a algún parámetro.
4. El sistema recoge los datos de todos los alumnos.

**Postcondiciones:**

* Se muestra por pantalla la lista de alumnos.

**Flujos alternativos:**

4.a. Si el sistema no contiene los datos de ningún alumno, muestra un mensaje de error.





### Mostrar alumno

**ID:** 004
**Breve descripción**: El sistema muestra los datos de un alumno concreto.

**Actores principales:** Usuario.
**Actores secundarios:** Alumno.

**Precondiciones:** 

1. El alumno debe existir en el sistema.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita buscar un alumno.
2. El sistema pregunta el dato a introducir para buscar el alumno: DNI, apellidos o email.
3. El sistema pregunta el valor del dato a introducir.
4. El sistema busca al alumno correspondiente (CU 002).

**Postcondiciones:**

* Se muestran por pantalla los datos del alumno.

**Flujos alternativos:**

4.a. Si existen varios alumnos con el mismo email o apellidos, el sistema recogerá los datos de ambos.





### Editar alumno

**ID:** 005
**Breve descripción**: El usuario edita los datos de un alumno.

**Actores principales:** Usuario.
**Actores secundarios:** Alumno.

**Precondiciones:** 

1. El alumno debe existir en el sistema.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita editar un alumno.
2. El sistema busca el alumno (CU 002).
3. El sistema pregunta por el parámetro a editar.

**Postcondiciones:**

* Los nuevos datos del alumno son iguales a los introducidos por el usuario.

**Flujos alternativos:**

3.a. Si el valor del parámetro no es válido, el sistema muestra un mensaje de error.
3.b. Si el parametro a editar es el de Líder, en caso afirmativo, se preguntará si se desea sobreescribir el anterior.




### Borrar alumno

**ID:** 006
**Breve descripción**: El usuario borra los datos de un alumno.

**Actores principales:** Usuario.
**Actores secundarios:** Alumno.

**Precondiciones:** 

1. El alumno debe existir en el sistema.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita borrar un alumno.
2. El sistema busca el alumno por su DNI o por su email.

**Postcondiciones:**

* El alumno seleccionado no existe dentro del sistema.

**Flujos alternativos:** 

2.a Si no existe el alumno buscado, el sistema mostrará mensaje de error.


### Cargar fichero

**ID:** 007
**Breve descripción**: El usuario carga un fichero binario.

**Actores principales:** Usuario.
**Actores secundarios:** Ninguno.

**Precondiciones:** 

1. El fichero debe existir.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita cargar un fichero.
2. El sistema pregunta por el nombre del fichero a cargar.

**Postcondiciones:**

* El fichero debe estar cargado en el sistema

**Flujos alternativos:**

2.a. Si el fichero no existe, el sistema muestra un mensaje de error.
2.b. Si ya existen datos de alumnos en el sistema, éste pregunta si se desea sobreescribir dichos datos.




### Guardar fichero

**ID:** 008
**Breve descripción**: El usuario guarda un fichero binario con todos los alumnos.

**Actores principales:** Usuario.
**Actores secundarios:** Ninguno.

**Precondiciones:** Ninguna.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita guardar un fichero.
2. El sistema pregunta por el nombre del fichero a guardar.

**Postcondiciones:**

* Debe existir un fichero con los datos de todos los alumnos.

**Flujos alternativos:**

2.a. Si el fichero a guardar ya existe, el sistema pregunta si se desea sobreescribir el archivo.




### Guardar copia de seguridad

**ID:** 009
**Breve descripcion:** El usuario, si es Coordinador, podrá guardar una copia de seguridad.

**Actores principales:** Usuario Coordinador.
**Actores secundarios:** Ninguno.

**Precondiciones:** 

1. Que el usuario sea Coordinador.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita guardar una copia de seguridad.
2. El sistema pregunta por el nombre del fichero a guardar.

**Postcondiciones:**

* Debe existir un fichero copia de seguridad con los datos de todos los alumnos.

**Flujos alternativos:**

2.a. Si el fichero a guardar ya existe, el sistema pregunta si se desea sobreescribir el archivo.




### Cargar copia de seguridad

**ID:** 010
**Breve descripcion:** El usuario, si es Coordinador, podrá cargar una copia de seguridad.

**Actores principales:** Usuario Coordinador.
**Actores secundarios:** Ninguno.

**Precondiciones:** 

1. Que el usuario sea Coordinador.
2. Debe existir un fichero copia de seguridad con los datos de todos los alumnos.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema necesita cargar una copia de seguridad.
2. El sistema pregunta por el nombre del fichero a cargar.

**Postcondiciones:**

* El fichero copia de seguridad está cargado en el sistema.

**Flujos alternativos:**

2.a. Si el fichero a cargar no existe, el sistema muestra un mensaje de error.

 


### Iniciar sesión

**ID:** 011
**Breve descripcion:** El usuario iniciara sesión en el programa con su login y contraseña.

**Actores principales:** Usuario.
**Actores secundarios:** Ninguno.

**Precondiciones:** 

1. Que el usuario esté introducido en el fichero de login.

**Flujo principal:** 

1. El caso de uso comienza cuando el sistema requiere de un usuario y contraseña para iniciar sesión.

**Postcondiciones:**

* Debe iniciarse el programa con la sesion personal del usuario.

**Flujos alternativos:**

1. Si el login o la contraseña introducidos no están dentro del fichero de login, el sistema muestra un mensaje de error.
