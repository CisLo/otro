#pragma once

/** Cabeceras de los procedimientos usados por el programa **/
/*--------------------------------------------------------------------*/

/** Funciones NODO **/
void iniciar_lista(nodo_t **lista);
bool comprobar_lista (nodo_t *lista);
nodo_t *nuevo_nodo (alumno_t alumno, nodo_t *salto);
void agregar_nodo_principio (nodo_t **lista,alumno_t alumno);
void agregar_nodo_entre (nodo_t *nodo_anterior, alumno_t alumno);
void agregar_nodo_final(nodo_t **lista, alumno_t alumno_datos);


/** Funciones FICHEROS **/
void abrir_fichero(nodo_t **lista);
bool guardar_fichero(nodo_t *lista);


/** Funcion AGREGAR_ALUMNOS **/
bool comprobar_fecha (fecha_t fecha);
bool agregar_alumno (nodo_t **lista);
void ordenar_alumno (nodo_t **lista, alumno_t alumno_aux);


/** Funciones BUSCAR **/
int comprobar_letra (int numero_dni, char letra_dni);
int buscar_dni (nodo_t *lista, int *numero_dni, char *letra_dni, nodo_t **ultimo_alumno);
// --------------------------------------
bool comparar_letra (char a, char b);
bool comparar_strings (char string_buscado[], char string_nodo[]);
void buscar_nombre (nodo_t *lista, nodo_t **alumno_buscado);


/** Funciones VER_ELIMINAR **/
bool ver_alumno(nodo_t *ultimo_alum);
//----------------------------------------
void ver_lista (nodo_t *lista); /* EXTRA */
void ver_estadisticas (nodo_t *lista); /* EXTRA */
void editar_nota (nodo_t *ultimo_alum); /* EXTRA */
//----------------------------------------
void buscar_nodo (nodo_t *lista, nodo_t *nodo_buscar, nodo_t **nodo_previo);
void eliminar_alumno(nodo_t **lista, nodo_t **ultimo_alum);
//----------------------------------------/* EXTRA: eliminar lista */
void buscar_nodo_ult (nodo_t *lista, nodo_t **nodo_eliminar, nodo_t **nodo_previo);
void eliminar_lista (nodo_t **lista); 
