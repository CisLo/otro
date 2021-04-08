#pragma once 
#include <stdbool.h>

#define MAX 100

/* Definicion del tipo fecha */
typedef struct
{
    int dia;
    int mes;
    int any;
} fecha_t;

/* Definicion del tipo DNI */
typedef struct
{
    int numero;
    char letra;
} dni_t;

/* Definicion del tipo alumno */
typedef struct
{
    char nombre[MAX], apellido[MAX], email[MAX];
    dni_t dni;
    float nota;
    fecha_t fecha_nacimiento;
    int sexo;

} alumno_t;

/* Definicion del tipo nodo */
typedef struct nodo
{
    alumno_t alumno; //Data--> Datos del alumno
    struct nodo *salto; //Next--> Salto al siguiente nodo
} nodo_t;



/* Cabeceras de los procedimientos a usar por el programa principal */
void iniciar_nodo(nodo_t **lista);

void agregar_nodo_final(nodo_t **lista, alumno_t alumno);
bool abrir_fichero(nodo_t **lista);
bool guardar_fichero(nodo_t *lista);

bool agregar_alumno(alumno_t *alumno, nodo_t *lista);
int buscar_dni(int numero, nodo_t *lista);
int buscar_nombre();
int ultim_buscado();
void eliminar_ultim_buscado();