#include <stdio.h>
#include "point.h"
#include "clear_buffer.h"
#include "modify_point.h"

int print_point(Point_t *point)
{
    printf("La coordonnée du point x est : %d", (point->x)); // On affiche la valeur de X
    printf("La coordonnée du point y est : %d", (point->y)); // On affiche la valeur de Y
}

