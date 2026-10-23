#ifndef LINE_H
#define LINE_H
#include "point.h"

typedef struct Line_s
{

    Point_t *p1;
    Point_t *p2;

} Line_t;

Line_t *create_line();

void delete_line(Line_t *l);
#endif