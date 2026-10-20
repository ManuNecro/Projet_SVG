#include "rectangle.h"
#include "ask_integer.h"
#include "style.h"
#include "ask_integer_range.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief This function creates a new rectangle by prompting the user for its origin point, width, and height.
 * @return A pointer to the newly created Rectangle_t structure.
 */
Rectangle_t *create_rectangle(void)
{
    // Allocation de la memoire 
    Rectangle_t *rectangle = malloc(sizeof(Rectangle_t));
    if (rectangle == NULL)
    {
        return NULL;
    }
    printf("Creation du coin superieur gauche : ");
    rectangle->origin = create_point();
    rectangle->width = ask_integer("Quel largeur de forme ? ");
    rectangle->height = ask_integer("Quel hauteur de forme ? ");

    return rectangle;
}
void style_rect(Style_t *rect)
{
    if (rect == NULL)
        return; // Sécurité si la ligne n'existe pas

    rect->fill = new_color(ask_integer_range("Red color", 0, 255), ask_integer_range("Green color", 0, 255), ask_integer_range("Blue color", 0, 255));

    rect->outline = new_color(ask_integer_range("Red color", 0, 255), ask_integer_range("Green color", 0, 255), ask_integer_range("Blue color", 0, 255));

    modify_point(rect->translate); // Demande les coordonnée X, Y

    rect->rotate = rotate_angle(); // Demande l'angle de rotation
}
/**
 * @brief This function deletes a rectangle and frees the allocated memory for its origin point and the rectangle structure itself.
 * @param rectangle A pointer to the Rectangle_t structure to be deleted.
 */
void delete_rectangle(Rectangle_t* rectangle)
{
    if (rectangle != NULL)
    {
        if (rectangle->origin != NULL) // On libere d'abord le point créer dans la structure
        free (rectangle->origin);
    }
    free (rectangle); // On libere la structure
}