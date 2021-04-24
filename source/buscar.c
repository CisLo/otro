#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/** Comprobar si la letra introducida es la correcta **/ 
bool comprobar_letra (int numero_dni, char letra_dni)
{
  int i;
  bool comprobacion;
  char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE"; /* */

    i = numero_dni % 23; /* Se asigna la letra del DNI */
    if (letra[i] == letra_dni)
    {
      comprobacion = true; 
    }
    else
    {
      comprobacion = false;
    }
    return comprobacion;
}

/** Funcion buscar por DNI **/
bool buscar_dni (nodo_t *lista, int *numero_dni, char *letra_dni, nodo_t **ultimo_alumno)
{
  /* Declaracion de variables */
  int salida=0, ultimo_alumno;
  char letra_dni;
  bool check;
  nodo_t *p;

  /* DNI a buscar en la lista*/
  do {
    printf("Introduce el número del DNI");
    scanf("%d", &numero_dni);
    printf("Introduce la letra del DNI");
    scanf("%c", &letra_dni);
    check = comprobar_letra(numero_dni, letra_dni);
    if (!check)
      printf("El DNI es incorrecto, vuelve a escribirlo");  
  } while (!check);
  
  if ((numero_dni >= 0) && (numero_dni <= 99999999)) /* Comprobamos que se encuentre en el rango de un dni */
  {
    for (p = lista; p != NULL; p = p->salto)
    {
      if (p->alumno.dni.numero == numero_dni) /* Si coincide el DNI */
      {
        salida = 1;
        *ultimo_alumno = p; /* Asignamos la dirección del nodo buscado */
      }
    }
  }
  
  /*
    1/true: Si existe
    0/false: No existe
  */
  return salida;
}

/** Función comparar alumno por DNI **/
bool comparar_dni (nodo_t *lista, int numero_dni, char letra_dni, nodo_t **ultimo_alumno)
{
  bool salida;
  nodo_t *p = lista; /* Inicializamos la variable para recorrer la lista */

  if ((numero_dni >= 0) && (numero_dni <= 99999999)) /* Comprobamos que se encuentre en el rango de un dni */
  {
    while (p != NULL && !salida)
    {
      if (p->alumno.dni.numero == numero_dni) /*Si coincide el DNI*/
        salida = true;
    }
    /*
    1: Existe
    0: No existe
    */
  }
  return salida;
}


/** Funcion buscar por nombre **/
bool comparar_nombre (char nombre_buscado[], char nombre_nodo[]) /*Comparamos dos nombres */
{
  /* Variables */


  /* 
  while ()
  {

  }*/
  return ;
}

int buscar_nombre (nodo_t *lista, nodo_t **alumno_buscada)
{
  /* Declaración de variables locales */
  nodo_t *nodo_actual;
  char nombre[MAX];
  bool coincide = false;

  /* Preguntamos Nombre */
  printf("Introduce el nombre a buscar: ");
  scanf("%s", nombre); /* Guardamos el nombre */

  /* Comprobar el nombre del alumno en toda la lista */
  nodo_actual = lista;
  while (nodo_actual->salto == NULL)
  {
    comparar_nombre(nombre[MAX], nodo_actual->alumno.nombre);
  }
  return ;
}
