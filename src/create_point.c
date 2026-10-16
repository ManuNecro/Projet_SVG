#include <stdio.h>
#include "ask_integer.h"
#include "clear_buffer.h"
#include "point.h"

Point_t* create_point()
{
    Point_t *create_point = malloc(sizeof(Point_t)); // On créer la structure pour créer un point .
    create_point->x = ask_integer("Rentrer la valeur de x "); // On assigne la valeur de X 
    create_point->y = ask_integer("Rentrer la valeur de y"); // On assigne la valeur Y
    return create_point;
}


void delete_point(Point_t* point)
{
    free(point);
}


