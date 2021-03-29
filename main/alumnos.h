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

/* Definicion del tipo NIE */
typedef struct
{
    int numeros;
    char lletra;
} nif_t;

/* Definicion del tipo alumno */
typedef struct
{
    char nom[MAX], cognom[MAX], email[MAX];
    nif_t nif;
    float nota;
    fecha_t data_naixement;
    int sexe;

} alumne_t;

/* Definicion del tipo nodo */
typedef struct nodo
{
    alumne_t alumne;
    struct nodo *salto;
} nodo_t;



/* Cabeceras de los procedimientos a usar por el programa principal */
bool abrir_fichero(int **lista);
bool guardar_fichero(int *lista);

int afegir_alumne(nodo_t *lista);
int buscar_nif();
int buscar_nom();
int ultim_buscado();
void eliminar_ultim_buscado();