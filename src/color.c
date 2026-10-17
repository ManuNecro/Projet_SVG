#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "create_color.h"
#include "ask_integer_range.h"
#include "point.h"

Color_t* new_color(uint8_t red, uint8_t green, uint8_t blue)
{
   Color_t *color = malloc(sizeof(Color_t));
   color->r = red;   // Red (0,255)
   color->g = green; // Green (0,255)
   color->b = blue;  // Blue (0, 255)
   return color;
}

// Exemple de création d'une couleur Color_t mycolor = new_color(255, 128, 0);

void modify_color(Color_t *color) // Modification des couleurs
{
   printf("Ancienne couleur : Red : %d - Green : %d - Blue : %d ", color->r, color->g, color->b);
   color->r = ask_integer_range("Red color", 0, 255);
   color->g = ask_integer_range("Green color", 0, 255);
   color->b = ask_integer_range("Blue color", 0, 255);
}

void print_color(Color_t *color) // Affichage des couleurs
{
   printf("La couleur rouge est : %d\n", color->r);
   printf("La couleur verte est : %d\n", color->g);
   printf("La couleur bleue est : %d\n", color->b);
}

void delete_color(Color_t *color)
{
   free(color);
}