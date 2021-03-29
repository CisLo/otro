#include <stdlib.h>
#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la librería "alumnos.h" **/
#include "alumnos.h"

/** Inicializar la lista enlazada **/
void iniciar_node(node_t **lista) {
  *lista = NULL;
}

/** Funcion abrir fichero **/
bool abrir_fichero(nodo_t **lista)
{
  /* Variables locales de la funcion */
  FILE *fit_llist;
  bool cargado_check; /* si se ha podido cargar correctamente */

  nodo_t *nd; /* Variable de control que se desplaza por la lista a abrir */
  alumno_t *alumno; /* Variable que guarda el valor alumno_t de cada nodo */
  
  /* Leemos el fichero */
  fit_llist = fopen ("lista_alumnos.out", "rb"); /* Se abre el fichero en modo lectura */
  if (fit_llist == NULL)
  {
    printf ("La lista es"); /* Si el usuario da el fichero hay que avisar y si no entonces hay que crear un nuevo fichero */
    cargado_check = false;
  }
  else
  {
    /* fread (num_alumnes, sizeof(int), 1, fit_llist); /* Leemos el numero de alumnos */
    fread(/*Variable donde se guardan*/, sizeof(alumne_t), *num_alumnes, fit_llist); /* Leemos los datos de los alumnos */
    fclose (fit_llist); /* Cerramos el fichero */
    cargado_check = true;
  }
  return cargado_check;
}

/** Funcion guardar fichero **/
bool guardar_fichero(nodo_t *lista)
{
  /* Variables locales de la funcion */
  FILE *fit_lista;
  bool guardado_check; /* Si se ha guardado correctamente el fichero*/

  nodo_t *nd; /* Variable de control que se desplaza por la lista a guardar */
  alumno_t *alumno; /* Variable que guarda el valor alumno_t de cada nodo */

  /* Guardamos el fichero */
  fit_lista = fopen ("lista_alumnos.out", "wb");
  if (fit_lista == NULL)
  {
    printf ("No se ha podido guardar el fichero");
    guardado_check = false;
  }
  else
  {
    /* fwrite (&n_alumnos, sizeof(int), 1, fit_lista); /* Guardamos el numero de alumnos en el fichero */
    for (nd = lista, nd != NULL, nd = nd.salto)
    {
      alumno = nd.alumne;
      fwrite(alumno, sizeof(alumne_t), 1, fit_lista); /* Guardamos los datos de los alumnos */
    }
    fclose (fit_lista); /* Cerramos el fichero */
    guardado_check = true;
  }
  return guardado_check;
}


/** Función para añadir un alumno **/
int afegir_alumne (alumne_t *alumne,nodo_t *lista)
{

  /* Creación del nodo local de la función: */
  nodo_t nodo_alumne;
  nodo_alumne = malloc(sizeof(nodo_t));

  /* Introducir datos del alumno a añadir */

  printf("Nom de l'alumne: ");
  scanf("%c ",&nodo_alumne->nom);
  
  printf("Cognom: ");
  scanf("%c ",&nodo_alumne->cognom);
  printf("NIF (numeros + lletra): ");
  printf("Numeros: ");
  scanf("%d ",&nodo_alumne->numeros);
  printf("Lletra: ");
  scanf("%c ",&nodo_alumne->lletra);
  printf("Correu elèctronic: ");
  scanf("%c ",&nodo_alumne->email);
  printf("Nota (per exemple, 6.8): ");
  scanf("%f ",&nodo_alumne->nota);
  printf("Data de naixement: (dia, mes i any): ");
  printf("Dia:");
  scanf("%d ",&nodo_alumne->dia);
  printf("Mes:");
  scanf("%d ",&nodo_alumne->mes);
  printf("Any:");
  scanf("%d ",&nodo_alumne->any);
  printf("Sexe (home [0], dona [1] o no vull dir-ho [2]): ");
  scanf("%d ",&nodo_alumne->sexe);

  return ;
}

/** Función buscar por NIF **/


/** Función buscar por nombre **/


/** Función ver el último alumno buscado **/


/** Función eliminar el último alumno buscado **/