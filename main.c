#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf(); */
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /* Libreria booleano, bool */

/* Incluimos la libreria donde estan los procedimientos */
#include "headers/tipos.h"
#include "headers/funciones.h"

/** Programa principal **/
int main() 
{
	/* Declaracion de la Estructura */
	nodo_t *lista;
	nodo_t *alumno_buscado = NULL; /* Guarda direccion del nodo al buscar un alumno */
	
	/* Declaracion de variables */
	int numero, opcion = 0, valido_dni = 0, opcion_aux;
	char letra;
	bool salir; /* Booleano para salir del programa principal, y repetir el menu */
	bool no_cambios, fit_guardado = false; /* Por defecto el fichero no esta guardado ni cargado */

	/* Iniciamos la lista enlazada */
	iniciar_lista(&lista);

	/* Bucle del Menu y los procedimientos */
	while (!salir)
	{
		/* Menú principal */
		do
		{
			printf("\n MENU:\n");
			printf(" [1] - Agregar alumno\n");
			printf(" [2] - Recuperar lista de alumnos del Fichero\n");
			/* Comprobar si la lista no es nula, muestra las siguientes opciones: */
			if (!comprobar_lista(lista))
			{
				printf(" [3] - Buscar por DNI\n");
				printf(" [4] - Buscar por nombre\n");
				printf(" [5] - Ver ultimo alumno buscado\n");
				printf(" [6] - Eliminar ultimo alumno buscado\n");
				printf(" [7] - Guardar lista de alumnos en Fichero\n");
				printf(" [8] - Ver la lista\n");	/* Extra */
			}
			printf(" [0] - Salir\n\n");
			printf (" Escribe tu eleccion (el numero entre corchetes): ");
			scanf("%d", &opcion);
			printf("\n------------------------------------\n");
		} while ((!comprobar_lista(lista) && opcion < 0 && opcion > 2) || (comprobar_lista(lista) && opcion < 0 && opcion > 8));
		
		switch (opcion)
		{
			/*=== Salir ===*/
			case 0: /* Salimos del programa */
				if (!fit_guardado) {
					printf (" La lista no esta guardada. Seguro que quieres salir? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux);
						if (opcion_aux == 1) 
						{
							salir = true;
							printf(" Gracias por utilizar el programa\n");
						}
				}
				else {
					salir = true;
					printf(" Gracias por utilizar el programa\n");
				}
				printf("\n------------------------------------\n");
				break;
				

			/*=== Función para añadir alumno ===*/
			case 1: /* Agregar alumno */
				no_cambios = agregar_alumno(&lista);
				if (fit_guardado) /* Actualizamos si se ha guardado los cambios en caso de que se */
				{
					fit_guardado = no_cambios;
				}
				printf("\n------------------------------------\n");
				break;


			/*=== Funcion para cargar los datos de los alumnos a la lista enlazada ===*/
			case 2: /* Cargar fichero */
				abrir_fichero(&lista); /* Se crea la lista */
				printf("\n------------------------------------\n");
				break;
				
			case 3: /* Buscar alumno por DNI */
				do { /* Se ejecuta al menos una vez */
					valido_dni	= buscar_dni(lista, &numero, &letra, &alumno_buscado); /* Comprobamos DNI */
					if (valido_dni)
					{
						printf(" El DNI introducido coincide con: %s %s \n", alumno_buscado->alumno.nombre, alumno_buscado->alumno.apellido);
					}
					else
					{
						printf(" El DNI no coincide con ningun alumno en la lista \n");
					}
					printf(" Desea volver a buscar? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux);
				} while (opcion_aux == 1); 
				printf("\n------------------------------------\n");
				break;


			/*=== Función para buscar el alumno en la lista enlazada, por nombre ===*/
			case 4: /* Buscar por nombre */
				do { /* Se ejecuta al menos una vez */
					buscar_nombre(lista, &alumno_buscado);

					printf(" Desea volver a buscar? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux);
				} while (opcion_aux == 1); 
				printf("\n------------------------------------\n");
				break;
			
			/*=== Función para ver el ultimo alumno buscado ===*/
			case 5:  /* Ver el ultimo alumno buscado */
				ver_alumno(alumno_buscado);
				printf("\n------------------------------------\n");
				break;


			/*=== Función para eliminar al ultimo alumno buscado ===*/
			case 6: /* Eliminar el ultimo alumno buscado */
				if (ver_alumno(alumno_buscado))
				{
					/* Pedimos Confirmación */
					printf(" Quieres borrar este alumno? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux); 
					if (opcion_aux == 1) 
					{
						eliminar_alumno (&lista, &alumno_buscado);
						printf (" Se ha borrado el alumno \n");
					}
					printf("\n------------------------------------\n");
				}
				break;
			
			/*=== Guardar/añadir la lista enlazada con los datos de los alumnos al fichero ===*/
			case 7:/* Guardar fichero */
				fit_guardado = guardar_fichero(lista);
				printf("\n------------------------------------\n");
				break;
			
			/*=== Printar la lista enlazada con los datos de los alumnos añadidos ===*/
			case 8: /* Ver la lista completa de los alumnos */
				ver_lista(&lista);
				break;
		}
	}
	return 0; /* Finaliza el programa */
} 