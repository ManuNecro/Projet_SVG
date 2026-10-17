#ifndef LIGNE_H
#define LIGNE_H
#include "point.h"

typedef struct Ligne_s
{
    // Il faut 2 points pour creer une ligne
    Point_t *p1;
    Point_t *p2;

}Ligne_t;

Ligne_t* create_ligne();
void delete_ligne(Ligne_t *l);
#endif