#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"
/**
 * @brief This structure represents a rectangle or square, including its origin point, width, and height.
 */
typedef struct Rectangle_s
{
    Point_t *origin;
    int width;
    int height;
} Rectangle_t;

Rectangle_t *create_rectangle(void);

void delete_rectangle(Rectangle_t *rectangle);

#endif