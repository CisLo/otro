#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/
#include <string.h> /* Libreria para poder usar strcpy() */

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/** Función para comprobar la fecha introducido en la función "agregar_alumno()" **/
bool comprobar_fecha (fecha_t fecha) {

  bool fecha_valido = true;

  switch (fecha.mes)
  {
  case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    //Enero, marzo, mayo, julio, agosto, octubre y diciembre. --> 31 días
    if (fecha.dia > 31 || fecha.dia<0) {
      fecha_valido = false;
    }
    break;
  case 4: case 6: case 9: case 11: //Abril, junio, septiembre y noviembre. --> 30 días
    if (fecha.dia > 30 || fecha.dia<0) {
      fecha_valido = false;
    }
    break;
  case 2: //Frebrero. --> 28/29 días
      if (fecha.dia > 29 || fecha.dia<0) {
        fecha_valido = false;
      } else {
        if (fecha.dia==29 && (fecha.any%400==0 ||(fecha.any%4==0 && fecha.any%100!=0))) {
        } else {
          fecha_valido = false;
        }
      }
    break;
  
  default:
    printf("La fecha no es valido\n");
    break;
  }

  return fecha_valido;
}

/** Función para añadir un alumno **/
bool agregar_alumno (nodo_t **lista)
{
  bool alumno_valido, fecha_valido;
  alumno_t alumno_aux;
  nodo_t *alumno_dni_rep; /* Almacena el alumno con un dni igual al que se quiere agregar */
  fecha_t fecha_nacimiento_alumno;
  bool salida_dni;

  /* Introducir datos del alumno a agregar */
  
  printf("Nombre del alumno: "); /* Pedimos el nombre */
  scanf(" %s", alumno_aux.nombre);

  printf("Apellido: "); /* Pedimos el apellido */
  scanf(" %c", alumno_aux.apellido);

  do { /* Comprobar DNI del alumno */
    salida_dni = buscar_dni (*lista, &alumno_aux.dni.numero, &alumno_aux.dni.letra, &alumno_dni_rep);
    if (salida_dni)
    {
      printf ("Ya existe un alumno con ese DNI en la lista: %s %s \n", alumno_dni_rep->alumno.nombre, alumno_dni_rep->alumno.apellido);
      printf("Introduce un DNI distinto \n");
    }
    else
    {
      printf("El DNI se ha guardado correctamente \n");
    }
  } while (salida_dni);

  printf("Correo electronico: ");
  scanf(" %s", alumno_aux.email);

  do { /* Comprobar nota del alumno */
    printf("Nota del alumno (por ejemplo, 6.8): ");
    scanf(" %f", &alumno_aux.nota);
  } while (alumno_aux.nota<0 || alumno_aux.nota>10);
  
  do {
    printf("Fecha de nacimiento: (dia, mes y año): \n");
    printf("Dia: ");
    scanf("%d ", &fecha_nacimiento_alumno.dia);
    printf("Mes: ");
    scanf("%d ", &fecha_nacimiento_alumno.mes);
    printf("Año: ");
    scanf("%d ", &fecha_nacimiento_alumno.any);

    fecha_valido = comprobar_fecha(fecha_nacimiento_alumno);

  } while (!fecha_valido);
  
  do { /* Comprobar sexo del alumno */
    printf("Sexo (hombre [0], mujer [1] o no quiero decirlo [2]): ");
    scanf("%d ", &alumno_aux.sexo);
  } while (alumno_aux.sexo<0 || alumno_aux.sexo>2);

  /* Llamamos a la función "ordenar alumno", para que agrege al alumno introducido */
  ordenar_alumno(lista, alumno_aux);    
  
  return alumno_valido;
  
}


/** Función para ordenar el alumno introducido en "agregar_alumno"

CASO 1: Lista vacía--> Llamar a "agregar_nodo_principio()"
CASO 2: Si el numero del DNI es más grande al primer nodo--> Llamar a "agregar_nodo_principio()"
CASO 3: Si el numero del DNI es más grande al nodo 'actual', se guarda el nodo 'actual' y en caso del nodo que le siga no es igual a NULL-->  Llamar a "agregar_nodo_entre()"
CASO 4: Si el numero del DNI es más grande al nodo 'actual', se guarda el nodo 'actual' y en caso del nodo que le siga es igual a NULL-->  Llamar a "agregar_nodo_final()"
**/
void ordenar_alumno (nodo_t **lista_p, alumno_t alumno_aux)
{
  /* Declaración de variables locales */
  /* Creación de nodos, para almacenar los datos al ordenar */
  nodo_t *nodo = *lista_p, *temp = NULL;
  bool salir;
  
  /* CASO 1 o CASO 2 */
  if (comprobar_lista(*lista_p) || (alumno_aux.dni.numero < nodo->alumno.dni.numero)) {
		agregar_nodo_principio(lista_p, alumno_aux);
	}
  else 
  {
    /* Recorre la lista enlazada, para comprobar en que posición de la lista a de añadir el alumno */
    while (nodo != NULL && !salir) 
    {
      if (alumno_aux.dni.numero > nodo->alumno.dni.numero)
      {
        if (nodo->salto == NULL)
        {
          agregar_nodo_final(lista_p, alumno_aux);
          temp = nodo;
          nodo = nodo->salto;
        }
      }
      else
      { // (alumno_aux.dni.numero < nodo->alumno.dni.numero)
        agregar_nodo_entre(temp, alumno_aux); //(alumno_t alumno, nodo_t *nodo_anterior)
        salir = true;
      }
    
  }

}
