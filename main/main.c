#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf(); */
#include <stdlib.h> /* Libreria para usar funciones generales como malloc(); */
#include <stdbool.h> /* Libreria booleano, bool */
#include <string.h> /* Libreria para poder usar strcpy() para el nombre y email */

/* Incluimos la libreria donde estan los procedimientos */
#include "alumnos.h"

/* Programa principal */
int main() {

	/* Declaracion de la Estructura */
	node_t *lista;
	dni_t dni;
	alumne_t alumne;

	/* Declaracion de variables */
	int opcion = 0, valido_dni = 0, numeros_dni = 0, opcion_dni = 0;
	bool salir = false; /* Booleano para salir del programa principal, y repetir el menu */
	bool fit_cargado;
	bool fit_guardado = false; /* Por defecto el fichero no esta guardado */
	bool alumno_guardado = false;
	char letra_dni;

	/* Iniciamos la lista enlazada */
	iniciar_node(&lista);

	/* Cargar fichero */
	fit_cargado = abrir_fichero(&lista); /* Leemos el fichero */
	if (fit_cargado)
	{
		printf("\nLa llista esta buida, es creara una nova\n");
	}
	else {printf("\nS'ha carregat la llista d'alumnes guardada\n");}


	/* Bucle del Menu y los procedimientos */
	while (!salir)
	{
		/* Menú principal */
		printf("\nMENU:\n");
		printf("[1] - Afegir alumne\n");
		printf("[2] - Buscar per DNI\n");
		printf("[3] - Buscar per nom\n");
		printf("[4] - Veure ultim alumne buscat\n")
		printf("[5] - Eliminar ultim alumne buscat\n");
		printf("[6] - Veure el llistat\n");
		printf("[0] - Sortir\n");
		scanf("%d", &opcion);
		
		switch (opcion)
		{
			case 0: /* Salimos del programa */
				salir = true;
				fit_guardado = guardar_fichero(lista);
				if (fit_guardado)
				{
					printf("S'ha guardat la llista d'alumnes\n");
				}
				printf("Gracies per utilitzar el nostre programa\n");
				break;
				
			case 1: /* Añadir alumno */
				alumno_guardado = afegir_alumne(lista);
				break;

			case 2: /* Buscar alumno por DNI */
				while (!opcion_dni) {
					printf("Escriba el DNI que quiere buscar");
					printf("Primero el numero");
					scanf("%d ",&numeros_dni);
					printf("Ahora la letra (en mayuscula)");
					scanf("%c ",&letra_dni);

					valido_dni	= buscar_dni(numeros_dni,letra_dni,lista);

					printf("Desea volver a buscar? [0(SI)/Altre(NO)]");
					scanf("%d ",&opcion_dni);
						if (opcion_dni != 0) {
							opcion_dni=true;
						}
				}
				break;
				
			case 3: /* Buscar por nombre */
				break;

			case 4: /* Ver el último alumno buscado */
				break;
				
			case 5: /* Eliminar el último alumno buscado */
				break;

			case 6: /* Ver la lista completa de los alumnos */
				break;

			default: /* Mensaje por defecto */
				printf("Introdueix una opcio valida [0-6]");
				break;
		}

	return 0; /* Finaliza el programa */
} 