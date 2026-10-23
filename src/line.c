#include "point.h"
#include "line.h"
#include "style.h"
#include "ask_integer_range.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/**
 * @brief This function creates a new line by prompting the user for its two endpoints.
 * @return A pointer to the newly created Ligne_t structure.
 */
Line_t *create_line()
{

    Line_t *l = malloc(sizeof(Line_t));
    if (l == NULL)
        return NULL;
    printf("--- Point de depart ---\n");
    l->p1 = create_point();
    printf("--- Point d'arrivee ---\n");
    l->p2 = create_point();
    return l;
}
/**
 *
 * @brief This function applies a style to a given line by prompting the user for fill and outline colors, translation point, and rotation angle.
 * @param l A pointer to the Style_t structure to be applied to the line.
 */
void style_line(Style_t *l)
{
    if (l == NULL)
        return;

    l->fill = new_color(ask_integer_range("Red color", 0, 255), ask_integer_range("Green color", 0, 255), ask_integer_range("Blue color", 0, 255));

    l->outline = new_color(ask_integer_range("Red color", 0, 255), ask_integer_range("Green color", 0, 255), ask_integer_range("Blue color", 0, 255));

    modify_point(l->translate);

    l->rotate = rotate_angle();
}
/**
 * @brief This function deletes a line and frees the allocated memory for its endpoints and the line structure itself.
 * @param l A pointer to the Ligne_t structure to be deleted.
 *
 */
void delete_line(Line_t *l)
{
    if (l != NULL)
        if (l->p1)
            free(l->p1);
    if (l->p2)
        free(l->p2);
    free(l);
}
