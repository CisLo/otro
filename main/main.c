#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf(); */
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); */
#include <stdbool.h> /* Libreria booleano, bool */

/* Incluimos la librería donde estan los procedimientos */
#include "alumnos.h"

/** Programa principal **/
int main() {

	/** Declaración de la Estructura **/
	node_t *list;
	data_t data;
	nif_t nif;
	alumne_t alumne;

	/** Declaración de variables **/
	int opcion = 0;
	bool sortir = false;
	bool fit_cargado = false; /* Comprobamos que se abra bien el fichero */

	/** Cargar fichero **/
	while (!fit_cargado){
		fit_cargado = abrir_fichero();
	}
	

	/** Bucle del Menu y los procedimientos **/
	while (!sortir) {
		
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
				break;
			case 1: /* Añadir alumno */
				afegir_alumne(nif, alumne, data);
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