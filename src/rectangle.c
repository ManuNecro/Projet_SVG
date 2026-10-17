#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"
#include "ask_integer.h"

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
    rectangle->widght = ask_integer("Quel largeur de forme ? ");
    rectangle->height = ask_integer("Quel hauteur de forme ? ");

    return rectangle;
}

void delete_rectangle(Rectangle_t* rectangle)
{
    if (rectangle != NULL)
    {
        if (rectangle->origin != NULL) // On libere d'abord le point créer dans la structure
        free (rectangle->origin);
    }
    free (rectangle); // On libere la structure
}