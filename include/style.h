#ifndef STYLE_H
#define STYLE_H
#include "create_color.h"
#include "point.h"
#include "rotate.h"

typedef struct Style_s
{
    Color_t *fill; // Pointeur vers la couleur de remplissage
    Color_t *outline; // Pointeur vers la couleur de contour
    Point_t *translate; // Pointeur vers la translation (decalage X , Y)
    Rotate_t *rotate; // Pointeur vers la rotation (angle)

} Style_t;

// Créer un style 
Style_t* create_style(void);

// Modifier un style 
void modify_style(Style_t *style);

// Afficher les informations de style
void print_style(Style_t *style);

// Libérer toute la mémoire du style
void delete_style(Style_t *style);

#endif