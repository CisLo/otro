#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/
#include <string.h> /* Libreria para poder usar strcpy() */

/** Incluimos la libreria "alumnos.h" **/
#include "alumnos.h"

/* Declaración de màximo de la lista de letras del DNI */
#define N 23

/** Inicializar la lista enlazada **/
void iniciar_nodo(nodo_t **lista) 
{
  *lista = NULL;
}

/** Funcion afegir_node_final **/
void agregar_nodo_final(nodo_t **lista_pp, alumno_t alumno_crg)
{
  /* Creamos variables */
  nodo_t *lista_p_aux = *lista_pp; 
  nodo_t* nd_p = (nodo_t *) malloc(sizeof(nodo_t)); /* Reservamos el nodo en la mjeemoria */
  nodo_t *p_final; /* Variable que recorre la lista hasta el ultimo nodo */

  /* Comprobamos que haya memoria para el nuevo nodo */
	if (nd_p == NULL)
  {
		printf ("No hay suficiente memoria para agregar el alumno a la lista");
    exit(-1); /* Se sale del programa */
	}
  else
  {
    /* Comprobamos si la lista esta vacia */
	  if (lista_p_aux == NULL)
    {
		  *lista_pp = nd_p; /* La lista apunta al nuevo nodo como el primero */
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

    nd_p->alumno = alumno_crg; /* Pasamos los datos del alumno cargado al nuevo nodo */
	  nd_p->salto = NULL; /* Asignamos al puntero del nodo "NULL", porque es el ultimo nodo */
  }
}

/** Funcion abrir fichero **/
bool abrir_fichero(nodo_t **lista_pp)
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

      agregar_nodo_final(lista_pp, alum_aux); /* Agregamos los alumnos leidos a la lista */
      fread (&alumno, sizeof(fecha_t), 1, fit_lista); /* Leemos los datos de los alumnos */
    }
    cargado_check = true; /* Cargado correctamente */
    fclose (fit_lista); /* Cerramos el fichero */
  }
  return cargado_check;
}

/** Funcion guardar fichero **/
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


/** Función para añadir un alumno **/
bool agregar_alumno (alumno_t *alumno, nodo_t *lista)
{
  bool alumno_valido, fecha_valido;

  /* Pata la creacion del nuevo nodo:
  Creacion del nodo local de la funcion: 
  node_t nodo_alumno;
  nodo_alumno = malloc(sizeof(node_t));
  */

  int salida_dni=0,numeros_dni_aux=0,sexe_aux,anyo_aux,mes_aux,dia_aux,longitud=0;
  float nota_aux=0.0;
  char nombre_aux,apellido_aux,letra_dni_aux,email_aux;

  /* Introducir datos del alumno a agregar */
  
  do { /* Comprobar nombre del alumno */
    printf("Nombre del alumno: ");
    scanf(" %s",nombre_aux);
  } while (nombre_aux<65 || nombre_aux>122 || (nombre_aux>90 && nombre_aux<97));
  
  
  do { /* Comprobar apellido del alumno */
    printf("Apellido: ");
    scanf(" %c",apellido_aux);
  } while (apellido_aux<65 || apellido_aux>122 || (apellido_aux>90 && apellido_aux<97));

  do { /* Comprobar DNI del alumno */
  printf("DNI (numeros + letra): ");
  printf("Numeros: ");
  scanf(" %d",numeros_dni_aux);
  printf("Lletra: ");
  scanf(" %c",&letra_dni_aux);
  
  salida_dni = buscar_dni(lista);

  } while (salida_dni == 1 || salida_dni == -1);

  printf("Correo electronico: ");
  scanf(" %c",email_aux);

  do { /* Comprobar nota del alumno */
  printf("Nota (por ejemplo, 6.8): ");
  scanf("%f ",&nota_aux);
  } while (nota_aux<0 || nota_aux>10);
  
  do {
    printf("Fecha de nacimiento: (dia, mes y año): ");
    printf("Dia:");
    scanf("%d ",&dia_aux);
    printf("Mes:");
    scanf("%d ",&mes_aux);
    printf("Año:");
    scanf("%d ",&anyo_aux);

    if (mes_aux==2) {
      if (((anyo_aux%4==0) && (anyo_aux%100==0) && (anyo_aux%400==0)) && dia_aux<=28) {
        fecha_valido = true;
      }
      longitud++;
    }

  } while (!fecha_valido);
  
  do { /* Comprobar sexo del alumno */
  printf("Sexo (hombre [0], mujer [1] o no quiero decirlo [2]): ");
  scanf("%d ",&sexe_aux);
  } while (sexe_aux<0 || sexe_aux>2);
      nodo_t *p;

  /** AQUI AGREGAR NODO A LA LISTA **/

  return alumno_valido;

  /*
  while (p_final->salto != NULL) { //Recorremos la lista hasta el ultimo nodo 
      
        p_final = p_final->salto; 
      }
  */
}

void agregar_nodo (nodo_t *lista/*,datos*/) 
{
  if (lista == NULL)
  {
    printf("No hay datos del alumno");
    //exit...
  }

  /* Tamaño del nuevo nodo a crear: */
  nodo_t *nodo_agregar = (nodo_t *)malloc(sizeof(nodo_t));

  /* Para  */
  nodo_agregar->/*datos*/ = nodo_agregar;

  nodo_agregar->/*salto*/ = lista->/* salto */;

  lista->/*salto*/ = nodo_agregar;

}

/** Funcion buscar por DNI **/
int buscar_dni (nodo_t *lista, nodo_t **alumno_buscado)
{
  /* Declaracion de variables */
  int salida=0, longitud=0, letra_dni, numero_dni, numero;
  char letra[N] = "TRWAGMYFPDXBNJZSQVHLCKE";

  /* DNI a buscar en la lista*/
  printf("Introduce el DNI, pero SIN la letra");
  scanf("%d", &numero_dni);

  numero = numero_dni;

  for (int cont=0; cont<9; cont++) 
  {
      numero = numero/10;
      longitud++;
  }
  

  if (longitud == 8)
  {
    if ((numero > 0) && (numero < 99999999)) /* Comprobamos que se encuentre en el rango de un dni */
    {
      letra_dni = numero % 23;
      printf("El DNI es: %d - %c\n", numero, letra[letra_dni]);
      nodo_t *p;

      for (p = lista; p != NULL; p = p->salto)
      {
        if (lista->alumno.dni.numero == numero_dni)
        {
          salida = 1;
        }
      }
    }
    else 
    {
      salida = -1;
      printf("El DNI escrito no es valido");
    }
  }
  
  /*
    1: Si existe
    0: No existe
    -1: Esta mal escrito, u otro
  */
  return salida;
}


/** Funcion buscar por nombre **/


/** Función ver el ultimo alumno buscado **/
int ultimo_buscado(nodo_t *p_lista, nodo_t *p_ultimo_alum)
{
  if (p_ultimo_alum == NULL) /* Comprobamos que se haya buscado un alumno */
  {
    printf("No se ha buscado ningun alumno o este ya ha sido borrado\n");
  }
  else
  {
    /* Imprimimos por pantalla los datos del alumno */
    printf("\nALUMNO: %s %s\n", p_ultimo_alum->alumno.nombre, p_ultimo_alum->alumno.apellido);
    printf("------------------------------------\n");
    printf("eMAIL: %s\n", p_ultimo_alum->alumno.nombre);
    printf("DNI: %d %c\n",  p_ultimo_alum->alumno.nombre, p_ultimo_alum->alumno.apellido);
    printf("NOTA: %d\n", p_ultimo_alum->alumno.nota);
    printf("FECHA NACIMIENTO: %d/%d/%d\n", p_ultimo_alum->alumno.fecha_nacimiento.dia, p_ultimo_alum->alumno.fecha_nacimiento.mes, p_ultimo_alum->alumno.fecha_nacimiento.dia);
    switch (p_ultimo_alum->alumno.fecha_nacimiento.dia)
    {
    case 0: printf("SEXO: Hombre");
      break;

    case 1: printf("SEXO: Mujer");
      break;

    case 2: printf("SEXO: No quiero decirlo");
      break;
    }
  }
}


/** Eliminar ultimo alumno  **/
void eliminar_alumno(nodo_t **p_lista, nodo_t *p_ultimo_alum, nodo_t *nodo_prev)
{
  /* Declaracion variables locales*/
  int borrar_alumno = 0;

  /* CASO 1: ultimo alumno es tanto el primero como el ultimo de la lista:  (*p_lista == p_ultimo_alum && p_ultimo_alum->salto == NULL)*/
  /* CASO 2: ultimo alumno es el primero de la lista                        (*p_lista == p_ultimo_alum && p_ultimo_alum->salto != NULL)*/
  /* CASO 3: ultimo alumno es el ultimo de la lista                         (*p_lista != p_ultimo_alum && p_ultimo_alum->salto == NULL)*/
  /* CASO 4: ultimo alumno esta entre alumnos de la lista                   (*p_lista != p_ultimo_alum && p_ultimo_alum->salto != NULL) */

  if (p_ultimo_alum == NULL)
  {
    printf ("No se ha buscado ningun alumno o este ya ha sido borrado\n");
  }
  else
  {
    /* Pedimos Confirmación */
		printf("Quieres borrar este alumno? [1: (SI) / Otro numero: (NO)]");
		scanf("%d", &borrar_alumno);

    if (borrar_alumno)
    {
      /* CASO 1 y CASO 2 */
      if (*p_lista == p_ultimo_alum)
      {
        *p_lista = p_ultimo_alum->salto;
        free(p_ultimo_alum);
      } 
      else /* CASO 3 y CASO 4 */
      {
        nodo_prev->salto = p_ultimo_alum->salto;
        free(p_ultimo_alum);
      }
      p_ultimo_alum = NULL; /* Evitamos que el puntero apunte a un nodo que ya se ha eliminado*/
      printf ("Se ha borrado el alumno");
    }
  }
}
