#include <stdio.h>
#include <stdint.h>
#include "rotate.h"
#include "ask_integer_range.h"
#include "ask_navigation.h"

int rotate_angle(char *message)
{
    ask_navigation("Menu : 1. Angle\n 2. FlipX\n 3. FlipY\n", 1, 3); // On affiche le menu de rotation.
    
    Rotate_t *r = malloc(sizeof(Rotate_t));
    r->rotate_angle = ask_integer_range("Quel angle voulez vous ?\n", -360, 360); // On demande la rotation souhaité.
    // On applique la rotation.
    return rotate_angle;
}

int modify_angle(char *message, Rotate_t rotate) // On modifie la rotation de la forme.
{
    printf("Ancienne angle : %d\n", rotate);
    rotate.rotate_angle = ask_integer_range("Nouvelle angle : \n", -360, 360);
}

int print_angle(Rotate_t *rotate) // Affiche le nouvel angle.
{
    printf("L'angle est de : %d °\n", rotate->rotate_angle);
}

void delete_angle(Rotate_t *rotate)
{
    free(rotate);
}