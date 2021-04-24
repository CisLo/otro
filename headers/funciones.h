#pragma once 
#include <stdbool.h>

/** Cabeceras de los procedimientos a usar por el programa principal **/
/*--------------------------------------------------------------------*/
void iniciar_nodo(nodo_t **lista);

/* Funciones Nodo */
void agregar_nodo_final(nodo_t **lista, alumno_t alumno);

/*Funciones Trabajar Ficheros*/
bool abrir_fichero(nodo_t **lista);
bool guardar_fichero(nodo_t *lista);

/* Funcion Agregar Alumno */
bool agregar_alumno(alumno_t *alumno, nodo_t *lista);
void agregar_nodo (nodo_t *lista/*,datos*/);

/* Funciones Buscar Alumno */
bool buscar_dni(nodo_t *lista, nodo_t **p_ultimo_alum);
bool comprobar_letra();
bool comparar_nombre ();
int buscar_nombre(nodo_t *lista, nodo_t **alumno_buscada);

/* Funciones Ultimo Alumno Buscado */
bool ver_alumno(nodo_t *p_ultimo_alum);
void buscar_nodo (nodo_t **nodo_previo);
void eliminar_alumno(nodo_t **p_lista, nodo_t **p_ultimo_alum);