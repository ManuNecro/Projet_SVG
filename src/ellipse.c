#include "ellipse.h"
#include "ask_integer.h"
#include "ask_integer_range.h"
#include "style.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function creates a new ellipse or a circle by prompting the user for its center point and radii.
 * @return A pointer to the newly created Ellipse_t structure.
 */
Ellipse_t *create_ellipse(void)
{

    Ellipse_t *ellipse = malloc(sizeof(Ellipse_t));
    if (ellipse == NULL)
    {
        return NULL;
    }

    printf("Creation of the center point : ");
    ellipse->center = create_point();

    ellipse->rx = ask_integer("radius X : ");

    ellipse->ry = ask_integer("radius Y : ");

    return ellipse;
}
void style_ellipse(Style_t *ellipse)
{
    if (ellipse == NULL)
        return;

    ellipse->fill = new_color(ask_integer_range("Red color", 0, 255), ask_integer_range("Green color", 0, 255), ask_integer_range("Blue color", 0, 255));

    ellipse->outline = new_color(ask_integer_range("Red color", 0, 255), ask_integer_range("Green color", 0, 255), ask_integer_range("Blue color", 0, 255));

    modify_point(ellipse->translate);

    ellipse->rotate = rotate_angle();
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
