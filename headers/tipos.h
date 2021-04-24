#pragma once 
#include <stdbool.h>

#define MAX 100

/* Definicion del tipo FECHA */
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

/* Definicion del tipo ALUMNO */
typedef struct
{
    char nombre[MAX], apellido[MAX], email[MAX];
    dni_t dni;
    float nota;
    fecha_t fecha_nacimiento;
    int sexo;

} alumno_t;

/* Definicion del tipo NODO */
typedef struct nodo
{
    alumno_t alumno; // Datos del alumno
    struct nodo *salto; // Salto al siguiente nodo

} nodo_t;
