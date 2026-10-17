#include <stdio.h>
#include <stdlib.h>
#include "ellipse.h"
#include "ask_integer.h"

// Fonction pour créer un cercle ou une ellipse

Ellipse_t *create_ellipse(void)
{
    // Allocation de la mémoire pour la structure Ellipse
    Ellipse_t *ellipse = malloc(sizeof(Ellipse_t));
    if (ellipse == NULL)
    {
        return NULL; // Sécurité si malloc echoue
    }

    printf("Création du point centrale ");
    ellipse->center = create_point();

    ellipse->rx = ask_integer("Longueur du rayon X : ");

    ellipse->ry = ask_integer("Longueur du rayon Y : ");

    return ellipse;
}

// Fonction pour liberé la mémoire
void delete_ellipse(Ellipse_t *ellipse)
{
    if (ellipse != NULL)
    {
        if (ellipse->center != NULL)
             // on libere d'abord le point a l'interieur de la structure
        free(ellipse->center);
    }
    free(ellipse); // Puis on libere la structure
}
