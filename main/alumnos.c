#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /*Libreria booleano, bool*/
#include <string.h> /* Libreria para poder usar strcpy() */

/** Incluimos la libreria "alumnos.h" **/
#include "alumnos.h"

/** Inicializar la lista enlazada **/
void iniciar_lista (nodo_t **lista) {
  *lista = NULL;
}

/** Comprobar si la lista està vacía **/
bool comprobar_lista (nodo_t *lista) {
	return lista == NULL;
}


/** Comprobar si la letra introducid es la correcta **/ 
bool comprobar_letra (int numero_dni, char letra_dni)
{
  int i;
  bool comprobacion;
  char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

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


/** Agregar nodo al principio de la lista **/
void agregar_nodo_principio (nodo_t **lista,alumno_t alumno)
{
  nodo_t *nodo_agregar = (nodo_t *)malloc(sizeof(nodo_t));

  /* Asignar los datos del alumno al nuevo nodo  */
  nodo_agregar->alumno = alumno;

  /* Crear el salto del nuevo nodo. */
  nodo_agregar->salto = (*lista);

  /* Asignar al puntero el nuevo nodo. */
  (*lista) = nodo_agregar;
}

/** Agregar nodo dentro de la lista **/
void agregar_nodo_entre (nodo_t *lista/*,datos*/) 
{
  if (lista == NULL)
  {
    printf("No hay datos del alumno");
    //exit...
  }

  /* Tamaño del nuevo nodo a crear: */
  nodo_t *nodo_agregar = (nodo_t *)malloc(sizeof(nodo_t));

  /* Para  */
  //nodo_agregar->/*datos*/ = nodo_agregar;

  //nodo_agregar->/*salto*/ = lista->/* salto */;

  //lista->/*salto*/ = nodo_agregar;

}

/** Agregar nodo al final de la lista **/
void agregar_nodo_final(nodo_t **lista_p, alumno_t alumno_crg)
{
  /* Creamos variables */
  nodo_t *lista_p_aux = *lista_p; 
  nodo_t* nd_p = (nodo_t *) malloc(sizeof(nodo_t)); /* Reservamos el nodo en la memoria */
  nodo_t *p_final; /* Variable que recorre la lista hasta el ultimo nodo */

  /* Comprobamos que haya memoria para el nuevo nodo */
	if (nd_p == NULL)
  {
		printf ("No hay suficiente memoria para agregar el alumno a la lista");
    exit(-1); /* Se sale del programa */
	}
  else
  {
	  if (comprobar_lista(lista_p_aux)) /* Comprobamos si la lista esta vacia */
    {
		  *lista_p = nd_p; /* La lista apunta al nuevo nodo como el primero */
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



/*----;;AGREGAR ALUMNO;;-----------------------------------------------------------------------------*/

/** Función para añadir un alumno **/
bool agregar_alumno (alumno_t *alumno, nodo_t *lista)
{
  bool alumno_valido, fecha_valido; 
  alumno_t alumno_aux;
  int salida_dni = 0, longitud = 0;

  /* Introducir datos del alumno a agregar */
  
  do { /* Comprobar nombre del alumno */
    printf("Nombre del alumno: ");
    scanf(" %s",alumno_aux.nombre);
  } while (alumno_aux.nombre<65 || alumno_aux.nombre>122 || (alumno_aux.nombre>90 && alumno_aux.nombre<97)); /* Comprueba si el nombre tiene numeros, mayusculas, o caracteres especiales */
    
  do { /* Comprobar apellido del alumno */
    printf("Apellido: ");
    scanf(" %c",alumno_aux.apellido);
  } while (alumno_aux.apellido<65 || alumno_aux.apellido>122 || (alumno_aux.apellido>90 && alumno_aux.apellido<97)); /* Comprueba si el nombre tiene numeros, mayusculas, o caracteres especiales */

  do { /* Comprobar DNI del alumno */
    printf("DNI (numeros + letra): ");
    printf("Numeros: ");
    scanf(" %d",alumno_aux.dni.numero);
    printf("Lletra: ");
    scanf(" %c",alumno_aux.dni.letra);
  
    //salida_dni = buscar_dni(alumno_aux.dni.letra);
    //int buscar_dni (nodo_t *lista, nodo_t **p_ultimo_alum, nodo_t **nodo_previo)
  /*
    1: Si existe
    0: No existe
    -1: Esta mal escrito o no es valido
  */

  } while (salida_dni == 1 || salida_dni == -1);

  printf("Correo electronico: ");
  scanf(" %c",alumno_aux.email);

  do { /* Comprobar nota del alumno */
    printf("Nota del alumno (por ejemplo, 6.8): ");
    scanf(" %f",alumno_aux.nota);
  } while (alumno_aux.nota<0 || alumno_aux.nota>10);
  
  do {
    printf("Fecha de nacimiento: (dia, mes y año): ");
    printf("Dia: ");
    scanf("%d ",alumno_aux.fecha_nacimiento.dia);
    printf("Mes: ");
    scanf("%d ",alumno_aux.fecha_nacimiento.mes);
    printf("Año: ");
    scanf("%d ",alumno_aux.fecha_nacimiento.any);

    if (alumno_aux.fecha_nacimiento.mes==2) {
      if (((alumno_aux.fecha_nacimiento.any%4==0) && (alumno_aux.fecha_nacimiento.any%100==0) && (alumno_aux.fecha_nacimiento.any%400==0)) && alumno_aux.fecha_nacimiento.dia<=28) {
        fecha_valido = true;
      }
      longitud++;
    }

  } while (!fecha_valido);
  
  do { /* Comprobar sexo del alumno */
    printf("Sexo (hombre [0], mujer [1] o no quiero decirlo [2]): ");
    scanf("%d ",alumno_aux.sexo);
  } while (alumno_aux.sexo<0 || alumno_aux.sexo>2);

  /* Llamamos a la función "ordenar alumno", para que agrege al alumno introducido */
  alumno_valido = ordenar_alumno(&lista,alumno_aux);    

  return alumno_valido;
  
}

/** Función para ordenar el alumno introducido en "agregar_alumno" **/
bool ordenar_alumno (nodo_t **p_lista, alumno_t alumno_aux)
{
  /* Declaración de variables locales */
  bool sortir;
  nodo_t *lista = *p_lista;

  /* Comprobar si la lista esta vacía, en caso afirmativo se llama a la función "..." para añadir el nodo al principio */
  if (comprobar_lista(p_lista)) {
		agregar_nodo_principio(p_lista,alumno_aux);
	} else {
    
    /* Recorre la lista enlazada, para comprobar en que posición de la lista a de añadir el alumno */
    while (lista->salto != NULL) {
      
    }

  }

 /*
 public void ordenar (ACT1_Marcarllibres[] llibres) {
		
		ACT1_Marcarllibres aux;
		int e=1;
		boolean boolea=false;
		
		while (e<llibres.length && !boolea) {
			
			boolea=true;
		
			for (int i = 0; i < llibres.length-e; i++) {
	
				//El compareto compara dos valores si es igual dara 0, si es positivo dara numero positivo, si es negativo dara numero negativo
				if (llibres[i].getIsbn().compareTo(llibres[i+1].getIsbn()) > 0) {
					
					aux=llibres[i];
					
					llibres[i] = llibres[i+1];
					
					llibres[i+1] = aux;
					
					boolea=false;
				}
			}
		}
	}
 */

/* Check if list is EMPTY 
  bool list_empty(node_t *list) {
    return list == NULL;
  }
  */

  /*
  node_t *list = *p_list;	

	if (list_empty(list)) {
		printf("Attempt to remove first element from empty list.\n");
		exit(EXIT_FAILURE);
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
  //nodo_agregar->/*datos*/ = nodo_agregar;

  //nodo_agregar->/*salto*/ = lista->/* salto */;

  //lista->/*salto*/ = nodo_agregar;

}



/*---------;;FIN AGREGAR ALUMNO;;-------------------------------------------------------------------------------------------*/



/** Funcion buscar por DNI **/
int buscar_dni (nodo_t *lista, nodo_t **p_ultimo_alum, nodo_t **nodo_previo)
{
  /* Declaracion de variables */
  int salida=0, longitud=0, numero_dni;
  char letra_dni;
  bool check;

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
    nodo_t *p, *p_anterior = NULL;

    for (p = lista; p != NULL; p = p->salto)
    {
      if (p->alumno.dni.numero == numero_dni) /* Si coincide el DNI */
      {
        salida = 1;
        p_ultimo_alum = p; /* Asignamos la dirección del nodo buscado */
        nodo_previo = p_anterior; /* Asignamos la dirección del nodo anterior */
      }
      p_anterior = p; /* Guardamos la dirección del nodo anterior */
    }
  }
  
  /*
    1: Si existe
    0: No existe
  */
  return salida;
}


/** Funcion buscar por nombre **/
bool comparar_nombre (char nombre_buscado[], char nombre_nodo[]) /*Comparamos dos nombres */
{
  /* */
  while ()
}

int buscar_nombre (nodo_t *lista, nodo_t **alumno_buscada, nodo_t **nodo_previo)
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
  
}


/** Función ver el ultimo alumno buscado **/
bool ver_alumno(nodo_t *p_ultimo_alum)
{
  /* Declaración variable */
  bool check_alumno_buscado;

  if (p_ultimo_alum == NULL) /* Comprobamos que se haya buscado un alumno */
  {
    printf("No se ha buscado ningun alumno o este ya ha sido borrado\n");
    check_alumno_buscado = false; /* No hay alumno buscado */
  }
  else
  {
    check_alumno_buscado = true; /* Hay alumno buscado */

    /* Imprimimos por pantalla los datos del alumno */
    printf("\nALUMNO: %s %s\n", p_ultimo_alum->alumno.nombre, p_ultimo_alum->alumno.apellido); 
    printf("------------------------------------\n");
    printf("eMAIL: %s\n", p_ultimo_alum->alumno.email);
    printf("DNI: %d %c\n",  p_ultimo_alum->alumno.dni.numero, p_ultimo_alum->alumno.dni.letra);
    printf("NOTA: %d\n", p_ultimo_alum->alumno.nota);
    printf("FECHA NACIMIENTO: %d/%d/%d\n", p_ultimo_alum->alumno.fecha_nacimiento.dia, p_ultimo_alum->alumno.fecha_nacimiento.mes, p_ultimo_alum->alumno.fecha_nacimiento.any);
    switch (p_ultimo_alum->alumno.sexo) /* Pasamos el sexo de un numero a su significado */
    {
    case 0: printf("SEXO: Hombre");
      break;

    case 1: printf("SEXO: Mujer");
      break;

    case 2: printf("SEXO: No quiero decirlo");
      break;
    }
  }
  return check_alumno_buscado;
}

/** Eliminar ultimo alumno  **/
void eliminar_alumno(nodo_t **p_lista, nodo_t **p_ultimo_alum, nodo_t *nodo_previo) /* pasamos por referencia ultimo_alum, porque lo modificamos */
{
  /* Declaracion variables locales*/
  int borrar_alumno = 0;

  /* CASO 1: alumno buscado es tanto el primero como el ultimo de la lista:  (*p_lista == p_ultimo_alum && p_ultimo_alum->salto == NULL)*/
  /* CASO 2: alumno buscado es el primero de la lista                        (*p_lista == p_ultimo_alum && p_ultimo_alum->salto != NULL)*/
  /* CASO 3: alumno buscado es el ultimo de la lista                         (*p_lista != p_ultimo_alum && p_ultimo_alum->salto == NULL)*/
  /* CASO 4: alumno buscado esta entre alumnos de la lista                   (*p_lista != p_ultimo_alum && p_ultimo_alum->salto != NULL) */


    /* Pedimos Confirmación */
		printf("Quieres borrar este alumno? [1: (SI) / Otro numero: (NO)]");
		scanf("%d", &borrar_alumno);

  if (borrar_alumno)
  {
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
    printf ("Se ha borrado el alumno");
  } 
}
