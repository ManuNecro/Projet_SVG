#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "point.h"

typedef struct Ellipse_s
{
    Point_t *center;
    int rx;
    int ry;

} Ellipse_t;

Ellipse_t *create_ellipse(void);

void delete_ellipse(Ellipse_t *ellipse);
#endif