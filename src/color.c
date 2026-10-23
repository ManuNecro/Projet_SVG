#include "create_color.h"
#include "ask_integer_range.h"
#include "point.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/**
 * @brief This function creates a new color with the specified red, green, and blue values.
 * @param red The red component of the color (0-255).
 * @param green The green component of the color (0-255).
 * @param blue The blue component of the color (0-255).
 * @return A pointer to the newly created Color_t structure.
 */

Color_t *new_color(uint8_t red, uint8_t green, uint8_t blue)
{
   Color_t *color = malloc(sizeof(Color_t));
   color->r = red;   // Red (0,255)
   color->g = green; // Green (0,255)
   color->b = blue;  // Blue (0, 255)
   return color;
}

// Exemple de création d'une couleur Color_t mycolor = new_color(255, 128, 0);
/**
 * @brief This function modifies the RGB values of an existing color by prompting the user for new values within the range of 0 to 255.
 * @param color A pointer to the Color_t structure to be modified.
 */
void modify_color(Color_t *color)
{
   printf("previous color : Red : %d - Green : %d - Blue : %d ", color->r, color->g, color->b);
   color->r = ask_integer_range("Red color", 0, 255);
   color->g = ask_integer_range("Green color", 0, 255);
   color->b = ask_integer_range("Blue color", 0, 255);
}
/**
 * @brief This function prints the RGB values of a given color.
 * @param color A pointer to the Color_t structure whose RGB values will be printed.
 */

void print_color(Color_t *color) // Affichage des couleurs
{
   printf("red color : %d\n", color->r);
   printf("green color : %d\n", color->g);
   printf("blue color : %d\n", color->b);
}
/**
 * @brief This function deletes a Color_t structure and frees the allocated memory.
 * @param color A pointer to the Color_t structure to be deleted.
 */
void delete_color(Color_t *color)
{
   free(color);
}
