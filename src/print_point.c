#include "point.h"
#include "clear_buffer.h"
#include "point.h"  
#include <stdio.h>
/**
 * @brief This function prints the x and y coordinates of a given point.
 * @param point A pointer to the Point_t structure whose coordinates will be printed.
 */
void print_point(Point_t *point)
{
    printf("La coordonnée du point x est : %d", (point->x)); // On affiche la valeur de X
    printf("La coordonnée du point y est : %d", (point->y)); // On affiche la valeur de Y
}

