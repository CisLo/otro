#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/** Funcion ABRIR fichero **/
bool abrir_fichero(nodo_t **lista_p)
{
  /* Variables locales de la funcion */
  FILE *fit_lista;
  bool cargado_check; /* si se ha podido cargar correctamente */

  alumno_t alumno; /* Variable almacena alumno */
  alumno_t alum_aux; /* Variable auxiliar del alumno */
  
  /* Leemos el fichero */
  fit_lista = fopen ("lista_alumnos.out", "rb"); /* Se abre el fichero en modo lectura */
  if (fit_lista == NULL)
  {
    cargado_check = false; /* No existe fichero */
  }
  else
  {
    fread(&alumno, sizeof(alumno_t), 1, fit_lista); /* Leemos los datos de los alumnos */
    while (!feof(fit_lista))
    {
      /* Pasamos los valores a la variable auxiliar */
      alum_aux = alumno;

      agregar_nodo_final(lista_p, alum_aux); /* Agregamos los alumnos leidos a la lista */
      fread (&alumno, sizeof(fecha_t), 1, fit_lista); /* Leemos los datos de los alumnos */
    }
    cargado_check = true; /* Cargado correctamente */
    fclose (fit_lista); /* Cerramos el fichero */
  }
  return cargado_check;
}


/** Funcion GUARDAR fichero **/
bool guardar_fichero(nodo_t *lista_p)
{
  /* Variables locales de la funcion */
  FILE *fit_lista;
  bool guardado_check; /* Si se ha guardado correctamente el fichero */
  alumno_t *alumno_p; /* Variable que guarda el valor alumno_t de cada nodo */
  nodo_t *nd_p; /* Variable de control que se desplaza por la lista a guardar */

  /* Guardamos el fichero */
  fit_lista = fopen ("lista_alumnos.out", "wb");
  if (fit_lista == NULL)
  {
    guardado_check = false;
  }
  else
  {
    /* Guardamos en el fichero los datos de los alumnos */
    for (nd_p = lista_p; nd_p != NULL; nd_p = nd_p->salto) 
    {
      *alumno_p = nd_p->alumno; 
      fwrite(alumno_p, sizeof(alumno_t), 1, fit_lista); /* Guardamos los datos de los alumnos en binario */
    }
    fclose (fit_lista); /* Cerramos el fichero */
    guardado_check = true;
  }
  return guardado_check;
}
