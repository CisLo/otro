#include <stdlib.h>
#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdbool.h> /*Libreria booleano, bool*/
#include <string.h> /* Libreria para poder usar strcpy() para el nombre y email */

/** Incluimos la libreria "alumnos.h" **/
#include "alumnos.h"

/** Inicializar la lista enlazada **/
void iniciar_node(node_t **lista) {
  *lista = NULL;
}

/** Funcion afegir_node_final **/
void afegir_node_final(node_t **lista_pp, alumne_t alumno)
{
  /* Creamos variables */
  node_t *lista_p_aux = *lista_pp; 
  node_t *nd_p = (node_t *)malloc(sizeof(node_t)); /* Asignamos el nodo a la memoria */
  node_t *p_final /* Variable que recorre la lista hasta el ultimo nodo */

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

    /* Pasamos los datos del alumno al nuevo nodo */
    strcpy(nd_p->alumne.nom, alumno.nom); /* Copiamos los datos de una cadena de caracteres al nuevo nodo del final de la lista */
    strcpy(nd_p->alumne.cognom, alumno.cognom);
    strcpy(nd_p->alumne.email, alumno.email);
    nd_p->alumne.dni.numeros = alumno.dni.numeros; /* Copiamos los datos al nuevo nodo del final de la lista */
    nd_p->alumne.dni.letra = alumno.dni.letra;
	  nd_p->alumne.nota = alumno.nota; 
	  nd_p->alumne.sexe = alumno.sexe;
    nd_p->alumne.data_naixement.dia = alumno.data_naixement.dia;
    nd_p->alumne.data_naixement.mes = alumno.data_naixement.mes;
    nd_p->alumne.data_naixement.any = alumno.data_naixement.any;
	  nd_p->salto = NULL; /* Asignamos al puntero del nodo "NULL", porque es el ultimo nodo */
  }
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
    printf ("La lista esta vacia"); /* Si el usuario da el fichero hay que avisar y si no entonces hay que crear un nuevo fichero */
    cargado_check = false; /* No existe fichero */
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

      afegir_node_final(lista_pp, alum_aux); /* Agregamos los alumnos leidos a la lista */
      fread (&alumne, sizeof(data_t), 1, fit_llist); /* Leemos los datos de los alumnos */
    }
    cargado_check = true; /* Cargado correctamente */
    fclose (fit_llist); /* Cerramos el fichero */
  }
  return cargado_check;
}

/** Funcion guardar fichero **/
bool guardar_fichero(node_t *lista_p)
{
  /* Variables locales de la funcion */
  FILE *fit_llist;
  bool guardado_check; /* Si se ha guardado correctamente el fichero*/
  alumno_t *alumno_p; /* Variable que guarda el valor alumno_t de cada nodo */

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
bool afegir_alumne (alumne_t *alumne, node_t *lista)
{
  bool alumno_valido,fecha_valido;

  /* Pata la creaciOn del nuevo nodo:
  Creación del nodo local de la funcion: 
  node_t nodo_alumne;
  nodo_alumne = malloc(sizeof(node_t));
  */

  int salida_dni=0, numeros_dni_aux=0, sexe_aux, anyo_aux, mes_aux, dia_aux;
  float nota_aux=0.0;
  char nombre_aux, apellido_aux, letra_dni_aux, email_aux;

  /* Introducir datos del alumno a añadir */
  
  do { /* Comprobar nombre del alumno */
    printf("Nombre del alumno: ");
    scanf(" %c", &nombre_aux);
  } while (nombre_aux<65 || nombre_aux>122 || (nombre_aux>90 && nombre_aux<97));
   
  do { /* Comprobar apellido del alumno */
    printf("Apellido: ");
    scanf(" %c", &apellido_aux);
  } while (apellido_aux<65 || apellido_aux>122 || (apellido_aux>90 && apellido_aux<97));

  do { /* Comprobar DNI del alumno */
  printf("DNI (numeros + letra): ");
  printf("Numeros: ");
  scanf(" %d",&numeros_dni_aux);
  printf("Lletra: ");
  scanf(" %c",&letra_dni_aux);
  
  salida_dni = buscar_dni(numeros_dni_aux,letra_dni_aux,lista);

  } while (salida_dni == 1 || salida_dni == -1);

  printf("Correo electronico: ");
  scanf(" %c", &email_aux);

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
    printf("Any:");
    scanf("%d ",&anyo_aux);

    if (mes_aux==2) {
      if (((anyo_aux%4==0) && (anyo_aux%100==0) && (anyo_aux%400==0)) && dia_aux<=28) {
        fecha_valido = true;
      }
      longitud++;
    }

  } while (!fecha_valido);
  
  do { /* Comprobar sexo del alumno */
  printf("Sexe (home [0], dona [1] o no vull dir-ho [2]): ");
  scanf("%d ",&sexe_aux);
  } while (sexe_aux<0 || sexe_aux>2);
      node_t *p;

  /** AQUI AGREGAR NODO A LA LISTA **/

  return alumno_valido;

  /*
  while (p_final->salto != NULL) { //Recorremos la lista hasta el ultimo nodo 
      
        p_final = p_final->salto; 
      }
  */
}

/** Función buscar por DNI **/
int buscar_dni (int numeros, char lletra,node_t *lista)
{
  int salida=0, longitud=0;

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
      printf("El DNI escrito no es valido");
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