#include "ellipse.h"
#include "ask_integer.h"
#include <stdio.h>
#include <stdlib.h>


// Fonction pour créer un cercle ou une ellipse
/**
 * @brief This function creates a new ellipse or a circle by prompting the user for its center point and radii.
 * @return A pointer to the newly created Ellipse_t structure.
 */
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

/**
 * @brief This function deletes an ellipse and frees the allocated memory for its center point and the ellipse structure itself.
 * @param ellipse A pointer to the Ellipse_t structure to be deleted.
 */
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
