#include "style.h"
#include "point.h"
#include "rotate.h"
#include "ask_integer_range.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function creates a new style by prompting the user for fill and outline colors, translation point, and rotation angle.
 * @return A pointer to the newly created Style_t structure.
 */

Style_t *create_style(void)
{

    // Allocation de la memoire
    Style_t *style = malloc(sizeof(Style_t));
    if (style == NULL)
        return NULL; // Sécurité si malloc echoue

    // création de la couleur de remplissage
    printf("--- Creation de la couleur de remplissage ---\n");
    uint8_t r = ask_integer_range("Red (0-255) : ", 0, 255);
    uint8_t g = ask_integer_range("Green (0-255) : ", 0, 255);
    uint8_t b = ask_integer_range("Blue (0-255) : ", 0, 255);

    style->fill = new_color(r, g, b);


    printf("--- Creation de la couleur des contours ---\n");
    uint8_t r2 = ask_integer_range("Red (0-255) : ", 0, 255);
    uint8_t g2 = ask_integer_range("Green (0-255) : ", 0, 255);
    uint8_t b2 = ask_integer_range("Blue (0 - 255) : ", 0, 255);
    style->outline = new_color(r2, g2, b2);

    printf("--- TRANSLATION --- \n");
    style->translate = create_point(); // Demande les coordonnée X, Y

    printf("--- ROTATION ---\n ");
    style->rotate = rotate_angle(); // Demande l'angle de rotation
    return style;
}
/**
 * @brief This function modifies an existing style by prompting the user for new fill and outline colors, translation point, and rotation angle.
 * @param style A pointer to the Style_t structure to be modified.
 */
void modify_style(Style_t *style)
{
    if (style == NULL)
        return; // securité si style n'existe pas

    printf("--- Modification de la couleur de remplissage ---\n");
    modify_color(style->fill);

    printf("--- Modification de la couleur de contour ---\n");
    modify_color(style->outline);

    printf("--- Modification de la translation ---\n");
    modify_point(style->translate);

    printf("--- Modification de la rotation ---\n");
    modify_angle(style->rotate);
}
/**
 * @brief This function prints the details of a given style, including fill and outline colors, translation point, and rotation angle.
 * @param style A pointer to the Style_t structure whose details will be printed.
 */
// Fonction pour afficher les paramètres du style
void print_style(Style_t *style)
{
    if (style == NULL)
        return;

    printf("\n--- INFORMATIONS DU STYLE ---\n");
    printf("Couleur de remplissage : ");
    print_color(style->fill);

    printf("Couleur du contour : ");
    print_color(style->outline);

    printf("Translation : ");
    print_point(style->translate);

    printf("Rotation : ");
    print_angle(style->rotate);
}
/**
 * @brief This function deletes a Style_t structure and frees the allocated memory for its components (fill color, outline color, translation point, and rotation angle).
 * @param style A pointer to the Style_t structure to be deleted.
 */
void delete_style(Style_t *style)
{
    if (style != NULL)
    {
        // Libération de la couleur de remplissage
        if (style->fill != NULL)
            delete_color(style->fill);

        // Libération de la couleur de contour
        if (style->outline != NULL)
            delete_color(style->outline);

        // Libération de la translation
        if (style->translate != NULL)
            free(style->translate);

        // Libération de la rotation
        if (style->rotate != NULL)
            delete_angle(style->rotate);

        // Libération de la structure
        free(style);
    }
}