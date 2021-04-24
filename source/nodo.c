#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"

/** Inicializar la lista enlazada **/
void iniciar_lista (nodo_t **lista) {
  *lista = NULL;
}

/** Comprobar si la lista està vacía **/
bool comprobar_lista (nodo_t *lista) {
	return lista == NULL;
}


/** Agregar nodo al principio de la lista **/
void agregar_nodo_principio (nodo_t **lista,alumno_t alumno)
{
  /* Reservamos en memoria */
  nodo_t *nodo_agregar = (nodo_t *)malloc(sizeof(nodo_t));

  /* Asignar los datos del alumno al nuevo nodo  */
  nodo_agregar->alumno = alumno;

  /* Crear el salto del nuevo nodo. */
  nodo_agregar->salto = (*lista);

  /* Asignar al puntero el nuevo nodo. */
  (*lista) = nodo_agregar;
}


/** Agregar nodo dentro de la lista **/
void agregar_nodo_entre (nodo_t *lista, alumno_t alumno/*, nodo_anterior*/)
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


/** Agregar nodo al final de la lista **/
void agregar_nodo_final(nodo_t **lista_p, alumno_t alumno_datos)
{
  /* Creamos variables */
  nodo_t *lista_p_aux = *lista_p; 
  nodo_t *nd_p = (nodo_t *) malloc(sizeof(nodo_t)); /* Reservamos el nodo en la memoria */
  nodo_t *p_final; /* Variable que recorre la lista hasta el ultimo nodo */

  /* Comprobamos que haya memoria para el nuevo nodo */
	if (nd_p == NULL)
    {
		printf ("No hay suficiente memoria para agregar el alumno a la lista");
        exit(-1); /* Se sale del programa */
	}
  else
  {
	  if (comprobar_lista(lista_p_aux)) /* Comprobamos si la lista esta vacia */
    {
		  *lista_p = nd_p; /* La lista apunta al nuevo nodo como el primero */
    }
    else 
    {
		  p_final = lista_p_aux; 
		  while (p_final->salto != NULL) /* Recorremos la lista hasta el ultimo nodo */
      {
        p_final = p_final->salto; 
      }
		  p_final->salto = nd_p; /* El ultimo nodo apunta al nuevo, poniendo al nuevo nodo al final de la lista */
	  }

    nd_p->alumno = alumno_datos; /* Pasamos los datos del alumno cargado al nuevo nodo */
	  nd_p->salto = NULL; /* Asignamos al puntero del nodo "NULL", porque es el ultimo nodo */
  }
}
