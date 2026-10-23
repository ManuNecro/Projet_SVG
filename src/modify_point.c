#include "ask_integer.h"
#include "point.h"
#include <stdio.h>

/**
 * @brief This function modifies the x and y coordinates of an existing point by prompting the user for new values.
 * @param modify_point A pointer to the Point_t structure to be modified.
 */
void modify_point(Point_t *modify_point)
{
    printf("Previous values : (x - y) : %d - %d\n", modify_point->x, modify_point->y);
    modify_point->x = ask_integer("Enter the new value for x : \n");
    modify_point->y = ask_integer("Enter the new value for y : \n");
    printf("New values (x - y) : %d - %d\n", modify_point->x, modify_point->y);
}
