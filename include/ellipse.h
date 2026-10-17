#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "point.h"

typedef struct Ellipse_s
{
    Point_t *center; //Pointeur vers le point central du cercle ou Ellipse (X, Y)
    int rx; // Rayon sur l'axe X
    int ry; // Rayon sur l'axe Y

}Ellipse_t;

Ellipse_t *create_ellipse(void); // Créer une ellipse

void delete_ellipse(Ellipse_t *ellipse); // Supprimer une ellipse
#endif