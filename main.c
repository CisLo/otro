/********************************************************************************
*                        PRACTICA 1 - LISTA DE ALUMNOS                          *
* POR CRISTIAN FERNANDEZ LOPEZ, DANIEL CLAVERO LAHERA, MASSIN LAAOUAJ MADROUNI  *
*                                    FPII                                       *
********************************************************************************/

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
			printf(" [1] - Introducir nuevo alumno\n");
			printf(" [2] - Recuperar lista de alumnos del Fichero\n");
			/* Comprobar si la lista no es nula, muestra las siguientes opciones: */
			if (!comprobar_lista(lista))
			{
				printf(" [3] - Guardar lista de alumnos en Fichero\n");
				printf(" [4] - Buscar por DNI\n");
				printf(" [5] - Buscar por nombre\n");
				printf(" [6] - Ver ultimo alumno buscado\n");
				printf(" [7] - Eliminar ultimo alumno buscado\n");

				printf(" [8] - Ver la lista\n");	/* Extra 1 */
				printf(" [9] - Eliminar la lista\n");	/* Extra 2 */
				printf(" [10]- Estadisticas de los alumnos\n");	/* Extra 3 */
				printf(" [11]- Editar nota del ultimo alumno buscado \n"); /* Extra 4 */
			}
			printf(" [0] - Salir\n\n");
			printf (" Escribe tu eleccion (el numero entre corchetes): ");
			scanf("%d", &opcion);
			printf("\n------------------------------------\n");
		} while ((comprobar_lista(lista) && (opcion < 0 || opcion > 2)) || (!comprobar_lista(lista) && (opcion < 0 || opcion > 11)));
		
		switch (opcion)
		{
			
			case 0: /*=== Salir ===*/
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
				
			
			case 1: /*=== Función para añadir alumno ===*/
				no_cambios = agregar_alumno(&lista);
				if (fit_guardado) /* Actualizamos si se ha guardado los cambios en caso de que se */
				{
					fit_guardado = no_cambios;
				}
				printf("\n------------------------------------\n");
				break;

			
			case 2: /*=== Funcion para cargar los datos de los alumnos a la lista enlazada ===*/
				if (lista != NULL)
				{
					printf(" Hay una lista abierta, se perderan los datos no guardados.\n Quieres continuar? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux);
					if (opcion_aux == 1)
					{
						eliminar_lista(&lista); /* Se elimina la lista */
						abrir_fichero(&lista); /* Se abre el fichero guardado */
					} 
				}
				else{abrir_fichero(&lista); /* Se crea la lista */}
				printf("\n------------------------------------\n");
				break;
			
			case 3: /*=== Guardar/añadir la lista enlazada con los datos de los alumnos al fichero ===*/
				fit_guardado = guardar_fichero(lista);
				printf("\n------------------------------------\n");
				break;

			
			case 4: /*=== Función para buscar el alumno en la lista enlazada, por DNI ===*/
				do { /* Se ejecuta al menos una vez */
					valido_dni	= buscar_dni(lista, &numero, &letra, &alumno_buscado); /* Comprobamos DNI */
					if (valido_dni == 1)
					{
						printf(" El DNI introducido coincide con: %s %s \n", alumno_buscado->alumno.nombre, alumno_buscado->alumno.apellido);
					}
					else
					{
						printf(" El DNI no coincide con ningun alumno en la lista\n");
					}
					printf(" Desea volver a buscar? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux);
				} while (opcion_aux == 1); 
				printf("\n------------------------------------\n");
				break;
			
			case 5: /*=== Función para buscar el alumno en la lista enlazada, por nombre ===*/
				do { /* Se ejecuta al menos una vez */
					buscar_nombre(lista, &alumno_buscado);

					printf(" Desea volver a buscar? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux);
				} while (opcion_aux == 1); 
				printf("\n------------------------------------\n");
				break;


			
			case 6: /*===  Ver el ultimo alumno buscado ===*/
				ver_alumno(alumno_buscado);
				printf("\n------------------------------------\n");
				break;
			
			case 7: /*=== Función para eliminar al ultimo alumno buscado ===*/
				if (ver_alumno(alumno_buscado))
				{
					/* Pedimos Confirmación */
					printf(" Quieres borrar este alumno? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux); 
					if (opcion_aux == 1) 
					{
						eliminar_alumno (&lista, &alumno_buscado);
					}
				}
				printf("\n------------------------------------\n");
				break;
			
			
			case 8: /*=== Printar la lista con los nombres y dni de los alumnos añadidos ===*/
				ver_lista(lista);
				printf("\n------------------------------------\n");
				break;
			
			case 9: /*=== Eliminar la lista enlazada y liberar el espacio reservado en memoria ===*/
                /* Pedimos Confirmación */
                printf(" Quieres eliminar la lista? [1: (SI) / Otro numero: (NO)]: ");
                scanf("%d", &opcion_aux);
                if (opcion_aux == 1)
                {
                    eliminar_lista(&lista);
                }
				printf("\n------------------------------------\n");
                break;
			
			case 10: /*=== Ver estadisticas de la lista de alumnos ===*/
			
				mostrar_estadisticas(lista);
				printf("\n------------------------------------\n");
				break;

			case 11: /*=== Editar nota del ultimo alumno buscado ===*/
				if (ver_alumno(alumno_buscado))
				{
					/* Pedimos Confirmación */
					printf(" Quieres editar la nota de este alumno? [1: (SI) / Otro numero: (NO)]: ");
					scanf("%d", &opcion_aux); 
					if (opcion_aux == 1) 
					{
						editar_alumno(alumno_buscado);
					}
				}
				printf("\n------------------------------------\n");
				break;
		}
	}
	return 0; /* Finaliza el programa */
} 