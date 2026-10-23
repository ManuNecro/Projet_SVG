#include "ask_integer.h"
#include "clear_buffer.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function creates a new point by prompting the user for its x and y coordinates.
 * @return A pointer to the newly created Point_t structure.
 */
Point_t *create_point()
{
    Point_t *create_point = malloc(sizeof(Point_t));
    create_point->x = ask_integer("enter the x value ");
    create_point->y = ask_integer("enter the y value ");
    return create_point;
}

void delete_point(Point_t *point)
{
    free(point);
}
