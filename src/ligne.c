#include <stdio.h>
#include <stdint.h>
#include "point.h"
#include "ligne.h"
#include <stdlib.h>

Ligne_t* create_ligne()
{

    // Allocation mémoire pour la ligne
    Ligne_t *l = malloc(sizeof(Ligne_t));
        if (l == NULL) return NULL; // Echec d'allocation
    printf("--- Point de depart ---\n");
    l->p1 = create_point(); // Saisi du premier point 
    printf("--- Point d'arrivee ---\n");
    l->p2 = create_point(); // Saisi du second point
    return l;

}

void delete_ligne(Ligne_t *l)
    {
    if (l != NULL)  // Nettoyage de la mémoire 
        if (l->p1) free(l->p1);
        if (l->p2) free(l->p2);
        free(l);
    }
 