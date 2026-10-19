#include "point.h"
#include "ligne.h"
#include "style.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/**
 * @brief This function creates a new line by prompting the user for its two endpoints.
 * @return A pointer to the newly created Ligne_t structure.
 */
Ligne_t *create_ligne()
{

    // Allocation mémoire pour la ligne
    Ligne_t *l = malloc(sizeof(Ligne_t));
    if (l == NULL)
        return NULL; // Echec d'allocation
    printf("--- Point de depart ---\n");
    l->p1 = create_point(); // Saisi du premier point
    printf("--- Point d'arrivee ---\n");
    l->p2 = create_point(); // Saisi du second point
    return l;
}
/**
 * @brief This function applies a style to a line by prompting the user for fill and outline colors.
 * @param l A pointer to the Ligne_t structure to which the style will be applied.
 */
void style_ligne(Style_t *l)
{
    if (l == NULL)
        return; // Sécurité si la ligne n'existe pas
}
/**
 * @brief This function deletes a line and frees the allocated memory for its endpoints and the line structure itself.
 * @param l A pointer to the Ligne_t structure to be deleted.
 *
 */
void delete_ligne(Ligne_t *l)
{
    if (l != NULL) // Nettoyage de la mémoire
        if (l->p1)
            free(l->p1);
    if (l->p2)
        free(l->p2);
    free(l);
}
