#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/

/* Incluimos la libreria "alumnos.h" */
#include "../headers/tipos.h"
#include "../headers/funciones.h"


/** Función ver el ultimo alumno buscado **/
bool ver_alumno (nodo_t *p_ultimo_alum)
{
  /* Declaración variable */
  bool check_alumno_buscado;

  if (p_ultimo_alum == NULL) /* Comprobamos que se haya buscado un alumno */
  {
    printf("\n No se ha buscado ningun alumno o este ya ha sido borrado\n");
    check_alumno_buscado = false; /* No hay alumno buscado */
  }
  else
  {
    check_alumno_buscado = true; /* Hay alumno buscado */

    /* Imprimimos por pantalla los datos del alumno */
    printf("\n ALUMNO: %s %s\n", p_ultimo_alum->alumno.nombre, p_ultimo_alum->alumno.apellido); 
    printf(" E-MAIL: %s\n", p_ultimo_alum->alumno.email);
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

    case 2: printf(" SEXO: No quiero decirlo \n\n");
      break;
    }
  }
  return check_alumno_buscado;
}


/** Mostrar la lista de alumnos **/
void ver_lista (nodo_t *lista) {
  nodo_t *p_lista;
  int contador = 1;

  printf (" LISTA: \n");
  /* Bucle para hacer el salto de un nodo a otro, para mostrar los datos de los alumnos */
  for (p_lista = lista; p_lista != NULL; p_lista = p_lista->salto)
  {
    printf("  Alumno n.%d) %d-%c, %s %s\n", contador++, p_lista->alumno.dni.numero, p_lista->alumno.dni.letra, p_lista->alumno.nombre, p_lista->alumno.apellido);
  }

  printf("\n Numero total de alumnos: %d\n",contador-1);
}


/** Mostrar estadisticas **/
void mostrar_estadisticas (nodo_t *lista) {
  nodo_t *p_lista;
  int contador = 0, contador_aprobado = 0;
  float media, nota_alta = 0.0, porcentaje;

  /* Bucle para hacer el salto de un nodo a otro, para mostrar los datos de los alumnos */
  for (p_lista = lista; p_lista != NULL; p_lista = p_lista->salto)
  {
    /* Guardar la nota más alta de la lista de alumnos */
    if (nota_alta < p_lista->alumno.nota) {
      nota_alta = p_lista->alumno.nota;
    }

    /*Contamos los aprobados */
    if (p_lista->alumno.nota >= 5.0) {
      contador_aprobado++;
    }

    /* Guarda la suma total */
    media += p_lista->alumno.nota;
    contador++;
  }

  /* Ponemos la nota más alta*/
  printf("\n La nota mas alta es: %.2f\n", nota_alta);

  /* Imprimimos la nota media*/
  if (contador != 0) {
    media /= contador;
    printf(" La nota media de todos los alumnos es: %.2f\n", media);
  }

  /* Calculamos porcentaje aprobados */
  porcentaje = (contador_aprobado/contador) * 100;
  printf(" Porcentaje de alumnos aprobados: %.2f%%\n", porcentaje);
  /* Calculamos porcentaje suspensos */
  porcentaje = (contador-contador_aprobado)/contador *100;
  printf(" Porcentaje de alumnos suspensos: %.2f%%\n", porcentaje);
}

/** Editar nota alumno **/
void editar_alumno (nodo_t *ultimo_alum)
{
  int opcion; /* Variable de opción */

  /* Cambiamos la nota */
  printf("\n Introduce la nueva nota: ");
  scanf("%f", ultimo_alum->alumno.nota);

}

/** Función buscar nodo **/
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
void eliminar_alumno (nodo_t **p_lista, nodo_t **p_ultimo_alum) /* pasamos por referencia ultimo_alum, porque lo modificamos */
{
  /* Declaracion variables locales*/
  nodo_t *nodo_previo;

  /* CASO 1: alumno buscado es tanto el primero como el ultimo de la lista:  (*p_lista == p_ultimo_alum && p_ultimo_alum->salto == NULL)*/
  /* CASO 2: alumno buscado es el primero de la lista                        (*p_lista == p_ultimo_alum && p_ultimo_alum->salto != NULL)*/
  /* CASO 3: alumno buscado es el ultimo de la lista                         (*p_lista != p_ultimo_alum && p_ultimo_alum->salto == NULL)*/
  /* CASO 4: alumno buscado esta entre alumnos de la lista                   (*p_lista != p_ultimo_alum && p_ultimo_alum->salto != NULL) */

  /* Buscamos el nodo previo */
  buscar_nodo (*p_lista, *p_ultimo_alum, &nodo_previo);

  /* CASO 1 y CASO 2 */
  if (*p_lista == *p_ultimo_alum)
  {
    *p_lista = (*p_ultimo_alum)->salto; /* La cabeza de la lista apunta al siguiente despues del alumno */
    free(*p_ultimo_alum); /* Liberamos el nodo */
  }   
  else /* CASO 3 y CASO 4 */
  {
    nodo_previo->salto = (*p_ultimo_alum)->salto; /* El nodo apunta al siguiente despues del alumno */
    free(*p_ultimo_alum); /* Liberamos el nodo */
  }
  *p_ultimo_alum = NULL; /* Evitamos que el puntero apunte a un nodo que ya se ha eliminado*/
  printf (" Se ha borrado el alumno \n");
}


/** Función Eliminar la lista **/
void buscar_nodo_ult (nodo_t *lista, nodo_t **nodo_eliminar, nodo_t **nodo_previo)
{
    /* Variables */
    nodo_t *temp = NULL, *p = lista; /* Inicializamos la variable para recorrer la lista */

    /* Recorrido lista */
    while (p->salto != NULL)
    {
        temp = p;
        p = p->salto;
    }
    *nodo_previo = temp;
    *nodo_eliminar = p;
}
void eliminar_lista (nodo_t **lista)
{
    nodo_t *nodo_eliminar, *nodo_previo;

    buscar_nodo_ult (*lista, &nodo_eliminar, &nodo_previo); /* Buscamos ultimo nodo */
    while (*lista != nodo_eliminar) 
    {
        nodo_previo->salto = NULL; /* El nodo previo apunta al final */
        free(nodo_eliminar); /* Liberamos el ultimo nodo */
        buscar_nodo_ult (*lista, &nodo_eliminar, &nodo_previo); /* Buscamos ultimo nodo */
    }
    free(nodo_eliminar); /* Liberamos el ultimo nodo */
    *lista = NULL;
    printf (" Se ha borrado la lista\n");
}