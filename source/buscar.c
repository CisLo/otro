#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/** Comprobar si la letra introducida es la correcta **/ 
int comprobar_letra (int numero_dni, char letra_dni)
{
  int i;
  int comprobacion;
  char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE"; /* */

  i = numero_dni % 23; /* Se asigna la letra del DNI */
  if (letra[i] == letra_dni)
  {
    comprobacion = 0; // Esta bien
  }
  else
  {
    comprobacion = -1; // Error
  }
  return comprobacion;
}

/** Funcion buscar por DNI **/
int buscar_dni (nodo_t *lista, int *numero_dni, char *letra_dni, nodo_t **ultimo_alumno)
{
  /* Declaracion de variables */
  int salida;
  nodo_t *p;

  /* DNI a buscar en la lista*/
  printf(" Introduce el numero del DNI: ");
  scanf(" %d", numero_dni);
  printf(" Introduce la letra del DNI: ");
  scanf(" %c", letra_dni);
  printf("\n");

  /* Realizamos las comprobaciones */
  salida = comprobar_letra(*numero_dni, *letra_dni);
  if (salida == -1){
    printf(" El DNI es incorrecto (no corresponde la letra con el numero) \n");
  }
  else{
    if ((*numero_dni >= 0) && (*numero_dni <= 99999999)) /* Comprobamos que se encuentre en el rango de un dni */
    {
      for (p = lista; p != NULL; p = p->salto)
      {
        if (p->alumno.dni.numero == *numero_dni) /* Si coincide el DNI */
        {
          salida = 1;
          *ultimo_alumno = p; /* Asignamos la dirección del nodo buscado */
        }
      }
    }
    else {
      salida = -1;
      printf(" El DNI es incorrecto (fuera de rango) \n");
    }
  }
  /*
    SALIDAS:
    1: Si existe
    0: No existe
    -1: Erroneo
  */
  return salida;
}



/** Función para ignorar en la busqueda del alumno, si es mayuscula o minuscula **/
bool comparar_letra (char a, char b)
{
  /* Variable de cambio mayuscula a minuscula  */
  int dif = 'a'-'A'; 

  /* Comparación */
  return (a == b || a == (b + dif) || a == (b - dif));
}


/** Función para comparar el nombre y apellido, introducido en la función"buscar_nombre()" **/
bool comparar_strings (char string_buscado[], char string_nodo[]) /*Comparamos dos strings */
{
  /* Variable de control bucle */
  int i = 0; 
  bool coincide = true; /* Para comprobar letras **/

  while (string_buscado[i] != '\0' && coincide) /* Comparamos la misma letra en mayuscula y minuscula hasta que no se termine la cadena buscada o no coincida */
  {
    if (comparar_letra(string_buscado[i], string_nodo[i]))
      coincide = true;
    else {coincide = false;}

    i++;
  }
  return coincide;
}


/** Función para buscar por nombre **/
void buscar_nombre (nodo_t *lista, nodo_t **alumno_buscado)
{
  /* Declaración de variables locales */
  nodo_t *nodo_actual;
  char string[MAX];
  int n = 0; /* Cuenta el numero de coincidencias */

  /* Preguntamos Nombre */
  printf(" Introduce el nombre o apellido a buscar: ");
  scanf("%s", string); /* Guardamos el nombre */

  /* Comprobar el nombre del alumno en toda la lista */
  printf("\n Coincidencias: \n");
  nodo_actual = lista;
  while (nodo_actual != NULL) /* Recorrido lista */
  {
    /* Comparar dos cadenas, para saber si un alumno tiene el mismo nombre o apellido */
    if (comparar_strings(string, nodo_actual->alumno.nombre) || comparar_strings(string, nodo_actual->alumno.apellido)) /* Comparamos todos los nombres y apellidos de la lista */
    {
      if (n == 0)
      {
        *alumno_buscado = nodo_actual; /* Actualizamos y guardamos el ultimo alumno buscado */
        printf("   1) %s %s\n", nodo_actual->alumno.nombre, nodo_actual->alumno.apellido); /* Se imprime por pantalla la coincidencia */
        printf(" \t%d-%c\n\n", nodo_actual->alumno.dni.numero, nodo_actual->alumno.dni.letra);
      }
      n++;
    }
    nodo_actual = nodo_actual->salto; /* Siguiente nodo */
  }

  if (n==0){
    printf(" No existen coincidencias en la lista\n");
  }
  else {
    printf(" Hay: %d coincidencias\n", n); /* Imprimimos numero de coincidencias */
  }
}
