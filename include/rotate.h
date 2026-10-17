#ifndef ROTATE_H
#define ROTATE_H

typedef struct Rotate_s
{
    int rotate_angle;
}Rotate_t;

Rotate_t* rotate_angle(void);

// Modifie l'angle d'une rotation existante
Rotate_t* modify_angle(Rotate_t *rotate);

// Affiche l'angle
void print_angle(Rotate_t *rotate);

// Libere la memoire de la structure
void delete_angle(Rotate_t *rotate);

#endif