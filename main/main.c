#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf(); */
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); */
#include <stdbool.h> /* Libreria booleano, bool */

/* Incluimos la librería donde estan los procedimientos */
#include "alumnos.h"

/* Programa principal */
int main() {

	/* Declaración de la Estructura */
	node_t *lista;
	nif_t nif;
	alumne_t alumne;

	/* Declaración de variables */
	int opcion = 0;
	bool sortir = false; /* Booleano para salir del programa principal, y repetir el menu */
	bool fit_guardado = false; /* Por defecto el fichero no esta guardado */
	bool alumne_guardado = false;

	/* Iniciamos la lista enlazada */
	iniciar_node(&lista);

	/* Cargar fichero */
	fit_cargado = abrir_fichero(&lista); /* Leemos el fichero */
	if (fit_cargado)
	{
		printf("\nS'ha carregat la llista d'alumnes guardada\n");
	}
	else {printf("La lista está vacia, se creará una nueva");}
	

	/* Bucle del Menu y los procedimientos */
	while (!sortir) 
	{
		do {
        /* Menú principal */
        printf("\nMENU:\n");
        printf("[1] - Afegir alumne\n");
        printf("[2] - Buscar per NIF\n");
        printf("[3] - Buscar per nom\n");
				printf("[4] - Veure últim alumne bsucat\n")
        printf("[5] - Eliminar últim alumne buscat\n");
				printf("[0] - Sortir\n");
        scanf("%d", &opcion);
				 
    } while (opcion < 6 || opcion >= 0 );
		
		switch (opcion)
		{
			case 0: /* Salimos del programa */
				sortir = true;
				while (!fit_guardado) 
				{
					fit_guardado = guardar_fichero(lista);
				}
				printf("S'ha guardat la llista d'alumnes\n");
				printf("Gràcies per utilitzar el nostre programa\n");
				break;
			case 1: /* Añadir alumno */
				while (!alumne_guardado)
				{
					alumne_guardado = afegir_alumne(lista);
				}

				break;
			case 2: /* Buscar alumno por NIF */
				break;
			case 3: /* Buscar por nombre */
				break;
			case 4: /* Ver el último alumno buscado */
				break;
			case 5: /* Eliminar el último alumno bsucado */
				break;

			default: /* Mensaje por defecto */
				break;
		}

	}
	return 0; /* Finaliza el programa */
} 