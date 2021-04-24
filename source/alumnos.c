#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/
#include <string.h> /* Libreria para poder usar strcpy() */

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/*----;;AGREGAR ALUMNO;;-----------------------------------------------------------------------------*/

/** Función para añadir un alumno **/
bool agregar_alumno (alumno_t *alumno, nodo_t **lista)
{
  bool alumno_valido, fecha_valido; 
  alumno_t alumno_aux;
  int salida_dni = 0, longitud = 0;

  /* Introducir datos del alumno a agregar */
  
  do { /* Comprobar nombre del alumno */
    printf("Nombre del alumno: "); /* Pedimos el nombre */
    scanf(" %s",alumno_aux.nombre);
  } while (alumno_aux.nombre<65 || alumno_aux.nombre>122 || (alumno_aux.nombre>90 && alumno_aux.nombre<97)); /* Comprueba si el nombre tiene numeros, mayusculas, o caracteres especiales */
  
  do { /* Comprobar apellido del alumno */
    printf("Apellido: "); /* Pedimos el apellido */
    scanf(" %c",alumno_aux.apellido);
  } while (alumno_aux.apellido<65 || alumno_aux.apellido>122 || (alumno_aux.apellido>90 && alumno_aux.apellido<97)); /* Comprueba si el nombre tiene numeros, mayusculas, o caracteres especiales */

  do { /* Comprobar DNI del alumno */
    printf("DNI (numeros + letra): "); /* Pedimos el DNI */
    printf("Numeros: ");
    scanf(" %d",alumno_aux.dni.numero);
    printf("Lletra: ");
    scanf(" %c",alumno_aux.dni.letra);

    //salida_dni = buscar_dni (lista, alumno_aux.dni.numero, alumno_aux.dni.letra/*, nodo_t **ultimo_alumno*/);

/*
    1: Si existe
    0: No existe
    -1: Esta mal escrito o no es valido
  */

  } while (salida_dni == 1 || salida_dni == -1);

  printf("Correo electronico: ");
  scanf(" %c",alumno_aux.email);

  do { /* Comprobar nota del alumno */
    printf("Nota del alumno (por ejemplo, 6.8): ");
    scanf(" %f",alumno_aux.nota);
  } while (alumno_aux.nota<0 || alumno_aux.nota>10);
  
  do {
    printf("Fecha de nacimiento: (dia, mes y año): ");
    printf("Dia: ");
    scanf("%d ",alumno_aux.fecha_nacimiento.dia);
    printf("Mes: ");
    scanf("%d ",alumno_aux.fecha_nacimiento.mes);
    printf("Año: ");
    scanf("%d ",alumno_aux.fecha_nacimiento.any);

    if (alumno_aux.fecha_nacimiento.mes==2) {
      if (((alumno_aux.fecha_nacimiento.any%4==0) && (alumno_aux.fecha_nacimiento.any%100==0) && (alumno_aux.fecha_nacimiento.any%400==0)) && alumno_aux.fecha_nacimiento.dia<=28) {
        fecha_valido = true;
      }
      longitud++;
    }

  } while (!fecha_valido);
  
  do { /* Comprobar sexo del alumno */
    printf("Sexo (hombre [0], mujer [1] o no quiero decirlo [2]): ");
    scanf("%d ",alumno_aux.sexo);
  } while (alumno_aux.sexo<0 || alumno_aux.sexo>2);

  /* Llamamos a la función "ordenar alumno", para que agrege al alumno introducido */
  alumno_valido = ordenar_alumno(lista, alumno_aux,alumno);    

  return alumno_valido;
  
}

/** Función para ordenar el alumno introducido en "agregar_alumno" **/
bool ordenar_alumno (nodo_t **p_lista, alumno_t alumno_aux, alumno_t *alumno)
{
  nodo_t *lista = *p_lista;
  
  /* Declaración de variables locales */
  bool sortir;
  
  /* Comprobar si la lista esta vacía, en caso afirmativo se llama a la función "..." para añadir el nodo al principio */
  if (comprobar_lista(p_lista)) {
		agregar_nodo_principio(&p_lista, alumno_aux);
	} else {
    
    nodo_t *nodo_anterior = lista;
    int aux;

    /* Recorre la lista enlazada, para comprobar en que posición de la lista a de añadir el alumno */
    while (lista->salto != NULL && !sortir) {
      
      /* Comparación del numero del DNI para ordenar la lista */
      if (alumno_aux.dni.numero > lista->alumno.dni.numero) {

        aux = alumno_aux.dni.numero;

        alumno_aux.dni.numero = lista->alumno.dni.numero;

        lista->alumno.dni.numero = aux;
        
      }

      
      lista = lista->salto;

    }

    //lista = lista->salto;
  }

  /*
  node_t *list = *p_list;	

	if (list_empty(list)) {
		printf("Attempt to remove first element from empty list.\n");
		exit(EXIT_FAILURE);
	}
  */

}

void agregar_nodo (nodo_t *lista/*,datos*/) 
{
  if (lista == NULL)
  {
    printf("No hay datos del alumno");
    //exit...
  }

  /* Tamaño del nuevo nodo a crear: */
  nodo_t *nodo_agregar = (nodo_t *)malloc(sizeof(nodo_t));

  /* Para  */
  //nodo_agregar->/*datos*/ = nodo_agregar;

  //nodo_agregar->/*salto*/ = lista->/* salto */;

  //lista->/*salto*/ = nodo_agregar;

}
/*---------;;FIN AGREGAR ALUMNO;;-------------------------------------------------------------------------------------------*/

