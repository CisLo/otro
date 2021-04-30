#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/** Funcion ABRIR fichero **/
void abrir_fichero(nodo_t **lista_p)
{
  /* Variables locales de la funcion */
  FILE *fit_lista;
  alumno_t alumno; /* Variable almacena alumno */
  
  /* Leemos el fichero */
  fit_lista = fopen ("lista_alumnos.out", "rb"); /* Se abre el fichero en modo lectura */
  if (fit_lista == NULL)
  {
    printf("\n La lista esta vacia, se creara una nueva\n");
  }
  else
  {
    fread(&alumno, sizeof(alumno_t), 1, fit_lista); /* Leemos los datos del primer alumno */
    while (!feof(fit_lista))
    {
      agregar_nodo_final(lista_p, alumno); /* Agregamos los alumnos leídos a la lista */
      fread(&alumno, sizeof(alumno_t), 1, fit_lista); /* Leemos los datos de los alumnos */
    }
    printf("\n Se ha cargado la lista de alumnos\n");
    fclose (fit_lista); /* Cerramos el fichero */
  }
}


/** Funcion GUARDAR fichero **/
bool guardar_fichero(nodo_t *lista_p)
{
  /* Variables locales de la funcion */
  FILE *fit_lista;
  bool guardado_check; /* Si se ha guardado correctamente el fichero */
  alumno_t alumno_p; /* Variable que guarda el valor alumno_t de cada nodo */
  nodo_t *nd_actual; /* Variable de control que se desplaza por la lista a guardar */

  /* Guardamos el fichero */
  fit_lista = fopen ("lista_alumnos.out", "wb");
  if (fit_lista == NULL)
  {
    guardado_check = false;
    printf ("\n No se ha podido guardar el fichero \n");
  }
  else
  {
    /* Guardamos en el fichero los datos de los alumnos */
    for (nd_actual = lista_p; nd_actual != NULL; nd_actual = nd_actual->salto) 
    {
      alumno_p = nd_actual->alumno; 
      fwrite(&alumno_p, sizeof(alumno_t), 1, fit_lista); /* Guardamos los datos de los alumnos en binario */
    }
    fclose (fit_lista); /* Cerramos el fichero */
    guardado_check = true;
    printf("\n Se ha guardado la lista de alumnos \n");
  }
  return guardado_check;
}
