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
    printf("The x coordinate of the point is: %d", (point->x));
    printf("The y coordinate of the point is: %d", (point->y));
}
