#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/** Incluimos la libreria "alumnos.h" **/
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/** Función ver el ultimo alumno buscado **/
bool ver_alumno(nodo_t *p_ultimo_alum)
{
  /* Declaración variable */
  bool check_alumno_buscado;

  if (p_ultimo_alum == NULL) /* Comprobamos que se haya buscado un alumno */
  {
    printf(" No se ha buscado ningun alumno o este ya ha sido borrado\n");
    check_alumno_buscado = false; /* No hay alumno buscado */
  }
  else
  {
    check_alumno_buscado = true; /* Hay alumno buscado */

    /* Imprimimos por pantalla los datos del alumno */
    printf("\n ALUMNO: %s %s\n", p_ultimo_alum->alumno.nombre, p_ultimo_alum->alumno.apellido); 
    printf("------------------------------------\n");
    printf(" eMAIL: %s\n", p_ultimo_alum->alumno.email);
    printf(" DNI: %d %c\n",  p_ultimo_alum->alumno.dni.numero, p_ultimo_alum->alumno.dni.letra);
    printf(" NOTA: %.2f\n", p_ultimo_alum->alumno.nota);
    printf(" FECHA NACIMIENTO: %d/%d/%d\n", p_ultimo_alum->alumno.fecha_nacimiento.dia, p_ultimo_alum->alumno.fecha_nacimiento.mes, p_ultimo_alum->alumno.fecha_nacimiento.any);
    /* Pasamos el sexo de un numero a su significado */
    switch (p_ultimo_alum->alumno.sexo) 
    {
    case 0: printf(" SEXO: Hombre \n");
      break;

    case 1: printf(" SEXO: Mujer \n");
      break;

    case 2: printf(" SEXO: No quiero decirlo \n");
      break;
    }
  }
  return check_alumno_buscado;
}


/* Función buscar nodo */
void buscar_nodo (nodo_t *lista, nodo_t *nodo_buscar, nodo_t **nodo_previo)
{
  /* Variables */
  nodo_t *temp = NULL, *p = lista; /* Inicializamos la variable para recorrer la lista */
  bool encontrado = false;

  /* Recorrido lista */
  while (p != NULL && !encontrado)
  {
    if (p == nodo_buscar)
    {
      *nodo_previo = temp;
      encontrado = true;
    }
    temp = p;
    p = p->salto;
  }
}


/** Eliminar ultimo alumno  **/
void eliminar_alumno(nodo_t **p_lista, nodo_t **p_ultimo_alum) /* pasamos por referencia ultimo_alum, porque lo modificamos */
{
  /* Declaracion variables locales*/
  int borrar_alumno = 0;
  nodo_t *nodo_previo;

  /* CASO 1: alumno buscado es tanto el primero como el ultimo de la lista:  (*p_lista == p_ultimo_alum && p_ultimo_alum->salto == NULL)*/
  /* CASO 2: alumno buscado es el primero de la lista                        (*p_lista == p_ultimo_alum && p_ultimo_alum->salto != NULL)*/
  /* CASO 3: alumno buscado es el ultimo de la lista                         (*p_lista != p_ultimo_alum && p_ultimo_alum->salto == NULL)*/
  /* CASO 4: alumno buscado esta entre alumnos de la lista                   (*p_lista != p_ultimo_alum && p_ultimo_alum->salto != NULL) */

  /* Pedimos Confirmación */
	printf(" Quieres borrar este alumno? [1: (SI) / Otro numero: (NO)]");
	scanf("%d", &borrar_alumno);

  if (borrar_alumno)
  {
    /* Buscamos el nodo previo */
    buscar_nodo (*p_lista, *p_ultimo_alum, &nodo_previo);

    /* CASO 1 y CASO 2 */
    if (*p_lista == *p_ultimo_alum)
    {
      *p_lista = (*p_ultimo_alum)->salto; /* La cabeza de la lista apunta al siguiente despues del alumno */
      free(p_ultimo_alum); /* Liberamos el nodo */
    }   
    else /* CASO 3 y CASO 4 */
    {
      nodo_previo->salto = (*p_ultimo_alum)->salto; /* El nodo apunta al siguiente despues del alumno */
      free(p_ultimo_alum); /* Liberamos el nodo */
    }
    p_ultimo_alum = NULL; /* Evitamos que el puntero apunte a un nodo que ya se ha eliminado*/
    printf (" Se ha borrado el alumno \n");
  } 
}
