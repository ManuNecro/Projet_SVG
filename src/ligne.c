#include <stdio.h>
#include <stdint.h>
#include "point.h"
#include "ligne.h"
#include <stdlib.h>

Ligne_t* create_ligne()
{
    Ligne_t *l = malloc(sizeof(Ligne_t));
        if (l == NULL) return NULL;
    Point_t *pta = create_point();
    Point_t *ptb = create_point();
    l->a = pta->x;
    l->b = ptb->x;
    printf("a : %d -- b: %d\n",l->a,l->b);
    return l;
}
 