#ifndef POINT_H
#define POINT_H

// Structure 
typedef struct Point_s
{
    int x; 
    int y; 
} Point_t;


// Creer un point 
Point_t* create_point(void);

// Modifier les coordonnées d'un point
void modify_point(Point_t *point);

// Afficher les coordonnées d'un point
void print_point(Point_t *point);

// Liberer la mémoire d'un point
void delete_point(Point_t *point);

#endif