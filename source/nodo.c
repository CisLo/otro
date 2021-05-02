#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"

/** Inicializar la lista enlazada **/
void iniciar_lista (nodo_t **lista) 
{
  *lista = NULL;
}

/** Comprobar si la lista està vacía **/
bool comprobar_lista (nodo_t *lista) 
{
	return lista == NULL;
}

/** Creacion e inicialización de un nuevo nodo a crear **/
nodo_t *nuevo_nodo (alumno_t alumno, nodo_t *salto) 
{

	/* Crea nuevo nodo */
	nodo_t *p_nuevo_nodo = (nodo_t *)malloc(sizeof(nodo_t));

	/* Inicializa el nuevo nodo, asigna los datos y el salto pasado por parametro al nuevo nodo */
	p_nuevo_nodo->alumno = alumno;
	p_nuevo_nodo->salto = salto;

  /* Retorna el nuevo nodo, con los datos y el salto pasado por parametro */
	return p_nuevo_nodo;
}


/** Agregar nodo al principio de la lista **/
void agregar_nodo_principio (nodo_t **lista_p, alumno_t alumno)
{
  nodo_t *nodo;
  nodo = nuevo_nodo(alumno, *lista_p); /* Reservamos en memoria */

  /* Crear el salto del nuevo nodo */
  nodo->salto = (*lista_p);

  /* Asignar al puntero el nuevo nodo */
  (*lista_p) = nodo;
}


/** Agregar nodo dentro de la lista, no se pone un doble puntero a "lista", ya que la lista no esta vacía **/
void agregar_nodo_entre (nodo_t *nodo_anterior, alumno_t alumno)
{

  /* Asignar el nuevo nodo */
  nodo_t *nodo =  nuevo_nodo(alumno, nodo_anterior->salto);

  /* Apuntar al siguiente nodo del "nodo_anterior" el nuevo */
  nodo_anterior->salto = nodo;
}


/** Agregar nodo al final de la lista **/
void agregar_nodo_final(nodo_t **lista, alumno_t alumno_datos)
{
  /* Creamos variables */
  nodo_t *lista_p_aux = *lista; /* Variable que recorre la lista hasta el ultimo nodo */

  /* Reservamos el nodo en la memoria, y añadimos los datos */
  nodo_t *nodo_p = nuevo_nodo(alumno_datos, NULL); /* NULL porque el nodo estara al final de la lista */

  while (lista_p_aux->salto != NULL) /* Recorremos la lista hasta el ultimo nodo */
  {
    /* Guarda el salto del utlimo nodo de la lista */
    lista_p_aux = lista_p_aux->salto;
  }
  lista_p_aux->salto = nodo_p; /* El ultimo nodo apunta al nuevo, poniendo al nuevo nodo al final de la lista */
}
