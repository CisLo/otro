#pragma once 
#include <stdbool.h>

#include "alumnos.h"

void agregar_nodo_final(nodo_t **lista, alumno_t alumno);
bool abrir_fichero(nodo_t **lista);
bool guardar_fichero(nodo_t *lista);