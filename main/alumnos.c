#include <stdlib.h>
#include <stdio.h> /*Libreria para escribir y leer, printf(); - scanf();*/
#include <stdbool.h> /*Libreria booleano, bool*/

/* Incluimos la librería "alumnos.h" */
#include "alumnos.h"

/* Función para añadir un alumno */
int afegir_alumne (nif, alumne, data)
{
  
  printf("Nom de l'alumne: ");
  scanf("%c ",&alumne.nom);
  printf("Cognom: ");
  scanf("%c ",&alumne.cognom);
  printf("NIF (numeros + lletra): ");
  printf("Numeros: ");
  scanf("%d ",&nif_t.numeros);
  printf("Lletra: ");
  scanf("%c ",&nif_t.lletra);
  printf("Correu elèctronic: ");
  scanf("%c ",&alumne.email);
  printf("Nota (per exemple, 6.8): ");
  scanf("%f ",&alumne.nota);
  printf("Data de naixement: (dia, mes i any): ");
  printf("Dia:");
  scanf("%d ",&fecha_t.dia);
  printf("Mes:");
  scanf("%d ",&fecha_t.mes);
  printf("Any:");
  scanf("%d ",&fecha_t.any);
  printf("Sexe (home [0], dona [1] o no vull dir-ho [2]): ");
  scanf("%d ",&alumne.sexe);

  return
}