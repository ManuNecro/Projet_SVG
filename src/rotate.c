#include "ask_integer_range.h"
#include "ask_navigation.h"
#include <stdio.h>
#include <stdint.h>
#include "rotate.h"
#include <stdlib.h>
/**
 * @brief This function prompts the user to select a rotation option (angle, flipX, or flipY) and creates a new Rotate_t structure with the specified rotation angle.
 * @return A pointer to the newly created Rotate_t structure.
 */
Rotate_t* rotate_angle()
{
    ask_navigation("Menu : 1. Angle\n 2. FlipX\n 3. FlipY\n", 1, 3); // On affiche le menu de rotation.
    
    Rotate_t *r = malloc(sizeof(Rotate_t));
    r->rotate_angle = ask_integer_range("Quel angle voulez vous ?\n", -360, 360); // On demande la rotation souhaité.
    // On applique la rotation.
    return r;
}
/**
 * @brief This function modifies the rotation angle of an existing Rotate_t structure by prompting the user for a new angle within the range of -360 to 360 degrees.
 * @param rotate A pointer to the Rotate_t structure whose angle will be modified.
 * @return A pointer to the modified Rotate_t structure.
 */
Rotate_t* modify_angle(Rotate_t *rotate) 
{
    printf("Ancien angle : %d\n", rotate->rotate_angle);
    rotate->rotate_angle = ask_integer_range("Nouvelle angle : \n", -360, 360);
    return rotate;
}
/**
 * @brief This function prints the rotation angle of a given Rotate_t structure.
 * @param rotate A pointer to the Rotate_t structure whose angle will be printed.
 */
void print_angle(Rotate_t *rotate) 
{
    printf("L'angle est de : %d °\n", rotate->rotate_angle);
}
/**
 * @brief This function deletes a Rotate_t structure and frees the allocated memory.
 * @param rotate A pointer to the Rotate_t structure to be deleted.
 */
void delete_angle(Rotate_t *rotate)
{
    free(rotate);
}