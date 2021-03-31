#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf(); */
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); */
#include <stdbool.h> /* Libreria booleano, bool */
#include <string.h> /* Libreria para poder usar strcpy() para el nombre y email */

/* Incluimos la librería donde estan los procedimientos */
#include "alumnos.h"

/* Programa principal */
int main() {

	/* Declaración de la Estructura */
	node_t *lista;
	dni_t dni;
	alumne_t alumne;

	/* Declaración de variables */
	int opcion = 0,valid_dni=0,numeros_dni=0,opcion_dni=0;
	bool sortir = false; /* Booleano para salir del programa principal, y repetir el menu */
	bool fit_guardado = false; /* Por defecto el fichero no esta guardado */
	bool alumne_guardado = false;
	char letra_dni;

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
		/* Menú principal */
		printf("\nMENU:\n");
		printf("[1] - Afegir alumne\n");
		printf("[2] - Buscar per DNI\n");
		printf("[3] - Buscar per nom\n");
		printf("[4] - Veure últim alumne buscat\n")
		printf("[5] - Eliminar últim alumne buscat\n");
		printf("[0] - Sortir\n");
		scanf("%d", &opcion);
		
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
				alumne_guardado = afegir_alumne(lista);
				break;
			case 2: /* Buscar alumno por DNI */
				while (!valid_dni) {
					printf("Escriba el DNI que quiere buscar");
					printf("Primero el número");
					scanf("%d ",&numeros_dni);
					printf("Ahora la letra (en mayúscula)");
					scanf("%c ",&letra_dni);

					valid_dni	= buscar_dni(numeros_dni,letra_dni,lista);

					if ()
					printf("Desea volver a buscar? [0(SI)/Altre(NO)]");
					scanf("%d ",&opcion_dni);
						if (opcion_dni != 0)
						{
							valid_dni=true;
						}
				}
				
				break;
			case 3: /* Buscar por nombre */
				break;
			case 4: /* Ver el último alumno buscado */
				break;
			case 5: /* Eliminar el último alumno bsucado */
				break;

			default: /* Mensaje por defecto */
				printf("Introdueix una opció valida [0-5]");
				break;
		}

	return 0; /* Finaliza el programa */
} 
