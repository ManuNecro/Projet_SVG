#ifndef LIGNE_H
#define LIGNE_H


typedef struct Ligne_s
{
    // Il faut 2 points pour creer une ligne
    int a;
    int b;

}Ligne_t;

Ligne_t* create_ligne();
#endif