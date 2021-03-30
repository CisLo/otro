#pragma once 
#include <stdbool.h>

#define MAX 100

/* Definicion del tipo fecha */
typedef struct
{
    int dia;
    int mes;
    int any;
} data_t;

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
    data_t data_naixement;
    int sexe;

} alumne_t;

/* Definicion del tipo nodo */
typedef struct node
{
    alumne_t alumne;
    struct node *salto;
} node_t;



/* Cabeceras de los procedimientos a usar por el programa principal */
bool abrir_fichero(node_t **lista);
bool guardar_fichero(node_t *lista);
bool afegir_node_final(node_t *lista, alumne_t alumno);

bool afegir_alumne(node_t *lista);
int buscar_nif();
int buscar_nom();
int ultim_buscado();
void eliminar_ultim_buscado();