#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "point.h"


typedef struct Rectangle_s
{
    Point_t *origin; // Coin superieur gauche (X, Y)
    int widght;
    int height;
}Rectangle_t;

// Crer un rectangle/carré

Rectangle_t *create_rectangle(void);

// Supprimer un rectangle/carré
void delete_rectancle(Rectangle_t *rectangle);

#endif