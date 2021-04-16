#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf(); */
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); y free */
#include <stdbool.h> /* Libreria booleano, bool */

/* Incluimos la libreria donde estan los procedimientos */
#include "alumnos.h"
#include "fichero.h"

/** Programa principal **/
int main() {

	/* Declaracion de la Estructura */
	nodo_t *lista;
	nodo_t *alumno_buscado, *nodo_prev; /* Guardan direcciones de nodos al buscar un alumno */
	dni_t dni;
	alumno_t *alumno;

	/* Declaracion de variables */
	int opcion = 0, valido_dni = 0, opcion_dni = 0, borrar_alumno = 0;
	bool salir = false; /* Booleano para salir del programa principal, y repetir el menu */
	bool fit_cargado = false, fit_guardado = false; /* Por defecto el fichero no esta guardado ni cargado */
	bool alumno_guardado = false;

	/* Iniciamos la lista enlazada */
	iniciar_nodo(&lista);

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
		printf("[8] - Ver la lista\n");
		printf("[0] - Salir\n");
		scanf(" %d", &opcion);
		
		switch (opcion)
		{
			case 0: /* Salimos del programa */
				salir = true;
				fit_guardado = guardar_fichero(lista);
				
				
				if (fit_guardado)
					printf("Se ha guardado la lista de alumnos\n");
				else
					printf ("No se ha podido guardar el fichero");

				printf("Gracias por utilizar el programa\n");
				break;
				
			case 1: /* Agregar alumno */
				alumno_guardado = agregar_alumno(alumno, lista);
				break;

			case 2: /* Buscar alumno por DNI */
				while (!opcion_dni) 
				{
					valido_dni	= buscar_dni(lista, &alumno_buscado);

					printf("Desea volver a buscar? [1: (SI) / Otro numero: (NO)]");
					scanf("%d ", &opcion_dni);
						if (opcion_dni != 1)
							opcion_dni = true;
				}
				break;
				
			case 3: /* Buscar por nombre */
				break;

			case 4: /* Ver el ultimo alumno buscado */
				break;
				
			case 5: /* Eliminar el ultimo alumno buscado */
				ver_alumno();
				/* Pedimos Confirmación */
				printf("Quieres borrar este alumno? [1: (SI) / Otro numero: (NO)]");
				scanf("%d", &borrar_alumno); 
				if (borrar_alumno == 1)
					eliminar_alumno (&lista, alumno_buscado, nodo_prev);
					printf ("Se ha borrado el alumno");
				break;

			case 6: 
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

			default: /* Mensaje por defecto */
				printf("Introduzca una opcion valida [0-8]");
				break;
		}
	}
	return 0; /* Finaliza el programa */
} 