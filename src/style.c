#include <stdio.h>
#include <stdlib.h>
#include "style.h"
#include "point.h"

Style_t *create_style(void)
{

    //Allocation de la memoire
    Style_t *style = malloc(sizeof(Style_t));
    if (style == NULL) return NULL; // Sécurité si malloc echoue

    // création de la couleur de remplissage
    printf("Creation de la couleur de remplissage\n");
    style->fill = new_color(255,255,255); // Couleur par defaut (blanc)

    printf("--- Creation de la couleur des contours ---\n");
    style->outline = new_color(255,255,255); // Couleur par defaut blanc

    printf("--- TRANSLATION --- \n");
    style->translate = create_point(); // Demande les coordonnée X, Y
    
    printf("--- ROTATION ---\n ");
    style->rotate = rotate_angle(); // Demande l'angle de rotation
    return style;
}

void modify_style(Style_t *style)
{
    if (style == NULL) return; // securité si style n'existe pas 

    printf("--- Modification de la couleur de remplissage ---\n");
    modify_color(style->fill);

    printf("--- Modification de la couleur de contour ---\n");
    modify_color(style->outline);

    printf("--- Modification de la translation ---\n");
    modify_point(style->translate);

    printf("--- Modification de la rotation ---\n");
    modify_angle(style->rotate);
}

// Fonction pour afficher les paramètres du style 
void print_style(Style_t *style)
{
    if (style == NULL) return;

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

void delete_style(Style_t *style)
{
    if (style != NULL)
    {
        // Libération de la couleur de remplissage
        if (style->fill != NULL) delete_color(style->fill);

        // Libération de la couleur de contour
        if (style->outline != NULL) delete_color(style->outline);

        // Libération de la translation 
        if (style->translate != NULL) free(style->translate);

        // Libération de la rotation
        if (style->rotate != NULL) delete_angle(style->rotate);

        // Libération de la structure 
        free(style);
    }
}