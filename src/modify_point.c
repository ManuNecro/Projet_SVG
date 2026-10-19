#include "ask_integer.h"
#include "point.h"
#include <stdio.h>

/**
 * @brief This function modifies the x and y coordinates of an existing point by prompting the user for new values.
 * @param modify_point A pointer to the Point_t structure to be modified.
 */
void modify_point(Point_t *modify_point)
{
    printf("Anciennes valeurs de x - y : %d - %d\n",modify_point->x , modify_point->y);
    modify_point->x = ask_integer("Rentrer la valeur de x a modifier.\n"); // On modifie la valeur de X.
    modify_point->y = ask_integer("Rentrer la valeur de y a modifier.\n"); // On modifie la valeur de Y.
    printf("Les nouvelles valeurs de x - y sont : %d - %d\n",modify_point->x, modify_point->y); // On affiche les nouvelles valeurs.
}
