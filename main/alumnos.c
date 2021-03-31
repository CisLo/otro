#include <stdlib.h>
#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdbool.h> /*Libreria booleano, bool*/
#include <string.h> /* Libreria para poder usar strcpy() para el nombre y email */

/** Incluimos la librería "alumnos.h" **/
#include "alumnos.h"

/** Inicializar la lista enlazada **/
void iniciar_node(node_t **lista) {
  *lista = NULL;
}

/** Funcion afegir_node_final **/
bool afegir_node_final(node_t **lista_pp, alumne_t alumno)
{
  /* Creamos variables */
  node_t *lista_aux_p = *lista_pp; 
  node_t *nd_p = (node_t *)malloc(sizeof(node_t)); /* Asignamos el nodo a la memoria */
  bool nuevo_nodo_check; /* Variable para saber si se ha podido agregar el nodo al final de la lista */

  /* Comprobamos que haya memoria para el nuevo nodo */
	if (nd_p == NULL) {
		nuevo_nodo_check = false;
	}
  else
  {
    /* Comprobamos si la lista esta vacia */
	  if (lista_aux_p == NULL)
    {
		  *lista_pp = nd_p; /* La lista apunta al nuevo nodo como el primero */
    }
    else 
    {
		  node_t *last_p = lista_aux_p;
		  while (last_p->salto != NULL)
			  last_p = last_p->salto;
		  last_p->salto = nd_p;
	  }

    /* Pasamos los datos */
    strcpy(nd_p->alumne.nom, alumno.nom); /* Copiamos los datos de una cadena de caracteres al nuevo nodo del final de la lista */
    strcpy(nd_p->alumne.cognom, alumno.cognom);
    strcpy(nd_p->alumne.email, alumno.email);
    nd_p->alumne.dni = alumno.dni; /* Copiamos los datos al nuevo nodo del final de la lista */
	  nd_p->alumne.nota = alumno.nota; 
	  nd_p->alumne.sexe = alumno.sexe;
    nd_p->alumne.data_naixement = alumno.data_naixement;
	  nd_p->salto = NULL; /* Asignamos al puntero del nodo "NULL", porque es el ultimo nodo */

    /* Se ha agregado con exito el alumno a la lista */
    nuevo_nodo_check = true;
  }
  return nuevo_nodo_check;
}

/** Funcion abrir fichero **/
bool abrir_fichero(node_t **lista_pp)
{
  /* Variables locales de la funcion */
  FILE *fit_llist;
  bool cargado_check; /* si se ha podido cargar correctamente */

  alumno_t alumne; /* Variable almacena alumno */
  alumno_t alum_aux; /* Variable auxiliar del alumno */
  
  /* Leemos el fichero */
  fit_llist = fopen ("lista_alumnos.out", "rb"); /* Se abre el fichero en modo lectura */
  if (fit_llist == NULL)
  {
    printf ("La lista está vacia"); /* Si el usuario da el fichero hay que avisar y si no entonces hay que crear un nuevo fichero */
    cargado_check = false;
  }
  else
  {
    fread(&alumne, sizeof(alumne_t), 1, fit_llist); /* Leemos los datos de los alumnos */
    while (!feof(fit_llist))
    {
      /* Pasamos los valores a la variable auxiliar */
      alum_aux.nom = alumne.nom;
      alum_aux.cognom = alumne.cognom;
      alum_aux.email = alumne.email;
      alum_aux.dni = alumne.dni;
      alum_aux.nota = alumne.nota;
      alum_aux.data_naixement = alumne.data_naixement;
      alum_aux.sexe = alumne.sexe;

      afegir_node_final(lista_pp, alum_aux);
      
      fread (&alumne, sizeof(data_t), 1, fit_llist); /* Leemos los datos de los alumnos */
    }
    fclose (fit_llist); /* Cerramos el fichero */
    cargado_check = true;
  }
  return cargado_check;
}

/** Funcion guardar fichero **/
bool guardar_fichero(node_t *lista_p)
{
  /* Variables locales de la funcion */
  FILE *fit_llist;
  bool guardado_check; /* Si se ha guardado correctamente el fichero*/

  node_t *nd_p; /* Variable de control que se desplaza por la lista a guardar */
  alumno_t *alumno_p; /* Variable que guarda el valor alumno_t de cada nodo */

  /* Guardamos el fichero */
  fit_llist = fopen ("lista_alumnos.out", "wb");
  if (fit_llist == NULL)
  {
    printf ("No se ha podido guardar el fichero");
    guardado_check = false;
  }
  else
  {
    for (nd_p = lista_p, nd_p != NULL, nd_p = nd_p->salto)
    {
      *alumno_p = nd_p->alumne;
      fwrite(alumno_p, sizeof(alumne_t), 1, fit_llist); /* Guardamos los datos de los alumnos */
    }
    fclose (fit_llist); /* Cerramos el fichero */
    guardado_check = true;
  }
  return guardado_check;
}


/** Función para añadir un alumno **/
bool afegir_alumne (alumne_t *alumne,node_t *lista)
{
  bool alumne_validat;

  /*
  Creación del nodo local de la función: 
  node_t nodo_alumne;
  nodo_alumne = malloc(sizeof(node_t));
  */

  int salida_dni=0,numeros_dni_aux=0;
  char nombre_aux,apellido_aux,letra_dni_aux;

  /* Introducir datos del alumno a añadir */
  
  do { /* Comprovar nombre del alumno */
    printf("Nom de l'alumne: ");
    scanf("%c ",&nombre_aux);
  } while (nombre_aux<65 || nombre_aux>122 || (nombre_aux>90 && nombre_aux<97));
   
  do { /* Comprovar apellido del alumno */
    printf("Cognom: ");
    scanf("%c ",&apellido_aux);
  } while (apellido_aux<65 || apellido_aux>122 || (apellido_aux>90 && apellido_aux<97));

  printf("DNI (numeros + lletra): ");
  printf("Numeros: ");
  scanf("%d ",&numeros_dni_aux);
  printf("Lletra: ");
  scanf("%c ",&);
  
  printf("Correu elèctronic: ");
  scanf("%c ",&lista->email);
  printf("Nota (per exemple, 6.8): ");
  scanf("%f ",&lista->nota);
  printf("Data de naixement: (dia, mes i any): ");
  printf("Dia:");
  scanf("%d ",&lista->dia);
  printf("Mes:");
  scanf("%d ",&lista->mes);
  printf("Any:");
  scanf("%d ",&lista->any);
  printf("Sexe (home [0], dona [1] o no vull dir-ho [2]): ");
  scanf("%d ",&lista->sexe);

  return alumne_validat;
}

/** Función buscar por DNI **/
int buscar_dni (int numeros, char lletra,node_t *lista)
{
  int salida;
  int longitud=0;

  if ((lletra > 65) && (lletra < 90))
  {
    for (int cont=0; cont<9; cont++) {
    if (numeros == 0) {
      longitud++;
    } else if (numeros > 0) {
      numeros = numeros/10;
      longitud++;
    }
  }

  if (longitud == 8)
  {

    if ((numeros > 0) && (numeros < 99999999))
    {
      node_t *p;

      for (p = lista; p != NULL; p = p->next)
      {
          if ((&lista.numeros == numeros) && (&lista.lletra == lletra)) 
           {
              salida = 1;

            }
      }
    }
    else 
    {
      salida = -1;
      printf("El DNI escrito no es válido");
    }
  }
  }
 }
  /*
    1: Si existe
    0: No existe
    -1: Esta mal escrito, u otro
  */
  return salida;
}


/** Función buscar por nombre **/


/** Función ver el último alumno buscado **/


/** Función eliminar el último alumno **/