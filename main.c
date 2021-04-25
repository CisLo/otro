#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf(); */
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /* Libreria booleano, bool */

/* Incluimos la libreria donde estan los procedimientos */
#include "headers/tipos.h"
#include "headers/funciones.h"

/** Programa principal **/
int main() {

	/* Declaracion de la Estructura */
	nodo_t *lista;
	nodo_t *alumno_buscado = NULL; /* Guarda direccion del nodo al buscar un alumno */
	alumno_t *alumno;

	/* Declaracion de variables */
	int opcion = 0, valido_dni = 0, opcion_aux = 0;
	bool salir = false; /* Booleano para salir del programa principal, y repetir el menu */
	bool fit_cargado = false, fit_guardado = false; /* Por defecto el fichero no esta guardado ni cargado */
	bool alumno_guardado = false;

	/* Iniciamos la lista enlazada */
	iniciar_lista(&lista);

	/* Bucle del Menu y los procedimientos */
	while (!salir)
	{
		/* Menú principal */
		printf("\nMENU:\n");
		printf("[1] - Agregar alumno\n");
		printf("[2] - Buscar por DNI\n");
		printf("[3] - Buscar por nombre\n");
		printf("[4] - Ver ultimo alumno buscado\n");
		printf("[5] - Eliminar ultimo alumno buscado\n");
		printf("[6] - Guardar lista de alumnos en Fichero\n");
		printf("[7] - Recuperar lista de alumnos del Fichero\n");
		printf("[8] - Ver la lista\n");	/* Extra */
		printf("[0] - Salir\n");
		scanf(" %d", &opcion);
		
		switch (opcion)
		{
			case 0: /* Salimos del programa */
				if (!fit_guardado) {
					printf ("La lista no está guardada. Seguro que quieres salir? [1: (SI) / Otro numero: (NO)]");
					scanf("%d ", &opcion_aux);
						if (opcion_aux = 1)
							salir = true;
							printf("Gracias por utilizar el programa\n");
				}
				else {
					salir = true;
					printf("Gracias por utilizar el programa\n");
				}
				break;
				

			/*================================*/
			case 1: /* Agregar alumno */
				alumno_guardado = agregar_alumno(&lista);
				break;


			/*=== Funciones Buscar Alumno ===*/
			case 2: /* Buscar alumno por DNI */
				do { /* Se ejecuta al menos una vez */
					valido_dni	= buscar_dni(lista, 0 , 0, &alumno_buscado);
					if (valido_dni)
					{
						printf("El DNI introducido coincide con: %s %s", alumno_buscado->alumno.nombre, alumno_buscado->alumno.apellido);
					}
					else
					{
						printf("El DNI no coincide con ningun alumno en la lista");
					}
					printf("Desea volver a buscar? [1: (SI) / Otro numero: (NO)]");
					scanf("%d ", &opcion_aux);
				} while (opcion_aux == 1); 
				
				 
				break;
				
			case 3: /* Buscar por nombre */
				do { /* Se ejecuta al menos una vez */
					buscar_nombre(lista, &alumno_buscado);

					printf("Desea volver a buscar? [1: (SI) / Otro numero: (NO)]");
					scanf("%d ", &opcion_aux);
				} while (opcion_aux == 1); 
				break;


			/*=== Funciones Ultimo Alumno Buscado ===*/
			case 4: /* Ver el ultimo alumno buscado */
				ver_alumno(alumno_buscado);
				break;
				
			case 5: /* Eliminar el ultimo alumno buscado */
				if (ver_alumno(alumno_buscado))
				{
					/* Pedimos Confirmación */
					printf("Quieres borrar este alumno? [1: (SI) / Otro numero: (NO)]");
					scanf("%d", &opcion_aux); 
					if (opcion_aux == 1)
						eliminar_alumno (&lista, &alumno_buscado);
						printf ("Se ha borrado el alumno");
				}
				break;


			/*=== Funciones Trabajar Ficheros ===*/
			case 6: /* Guardar fichero */
				fit_guardado = guardar_fichero(lista);
				
				if (fit_guardado)
					printf("Se ha guardado la lista de alumnos\n");
				else
					printf ("No se ha podido guardar el fichero");

				printf("Gracias por utilizar el programa\n");
				break;
			
			case 7: /* Cargar fichero */
				fit_cargado = abrir_fichero(&lista); /* Leemos el fichero */
				if (fit_cargado)
					printf("\nSe ha cargado la lista de alumnos\n");
				else 
					printf("\nLa lista esta vacia, se creara una nueva\n");
				break;
				


			case 8: /* Ver la lista completa de los alumnos */
				break;

			/*===================================*/
			default: /* Mensaje por defecto */
				printf("Introduzca una opcion valida [0-8]");
				break;
		}
	}
	return 0; /* Finaliza el programa */
} 