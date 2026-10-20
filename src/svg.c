#include "svg.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief This function creates a new SVG scene with the specified capacity for shapes.
 * @param capacity The maximum number of shapes that can be stored in the SVG scene.
 * @return A pointer to the newly created SVG_t structure, or NULL if memory allocation fails
 */
SVG_t *create_svg(int capacity)
{
    SVG_t *svg = malloc(sizeof(SVG_t));
    if (svg == NULL)
        return NULL;

    svg->formes = malloc(sizeof(Forme_t) * capacity);
    if (svg->formes == NULL)
    {
        free(svg);
        return NULL;
    }
    return svg;
}

/**
 * @brief This function adds a shape (Forme_t) to the SVG scene, if there is enough capacity.
 * @param svg A pointer to the SVG_t structure representing the SVG scene.
 * @param shape The Forme_t structure representing the shape to be added.
 */
void add_shape_to_svg(SVG_t *svg, Forme_t *shape)
{
    if (svg == NULL || svg->count >= svg->capacity)
    {
        printf("Erreur : Impossible d'ajouter la forme (tableau plein ou inexistant).\n");
        return;
    }
    // On ajoute la forme au tableau de formes et on incrémente le compteur
    svg->formes[svg->count] = shape;
    svg->count++;
}

/**
 * @brief This function deletes an entire SVG scene, freeing all allocated memory for shapes and their associated styles.
 * @param svg A pointer to the SVG_t structure representing the SVG scene to be deleted.
 */

void delete_svg(SVG_t *svg)
{
    if (svg == NULL)
        return;

    if (svg->formes == NULL)
    {
        free(svg);
        return;
    }

    for (int i = 0; i < svg->count; i++)
    {
        if (svg->formes[i] == NULL)
            continue;

        if (svg->formes[i]->style != NULL)
            delete_style(svg->formes[i]->style);

        switch (svg->formes[i]->type)
        {
        case FORME_RECTANGLE:
            delete_rectangle(svg->formes[i]->forme.rectangle);
            break;
        case FORME_ELLIPSE:
            delete_ellipse(svg->formes[i]->forme.ellipse);
            break;
        case FORME_LINE:
            delete_line(svg->formes[i]->forme.line);
            break;
        }
    }
    free(svg->formes);
    free(svg);
}
/**
 * @brief This function deletes a specific shape from the SVG scene at the given index, freeing its associated style and shape data.
 * @param svg A pointer to the SVG_t structure representing the SVG scene.
 * @param index The index of the shape to be deleted in the SVG scene.
 */
void delete_shape_svg(SVG_t *svg, int index)
{

    if (svg == NULL || index < 0 || index >= svg->count)
        printf("Error : Invalid index or SVG is NULL.\n");
    return;

    if (svg->formes[index] == NULL)
        return;
    if (svg->formes[index]->style != NULL)
        delete_style(svg->formes[index]->style);

    switch (svg->formes[index]->type)
    {
    case FORME_RECTANGLE:
        delete_rectangle(svg->formes[index]->forme.rectangle);
        break;
    case FORME_ELLIPSE:
        delete_ellipse(svg->formes[index]->forme.ellipse);
        break;
    case FORME_LINE:
        delete_line(svg->formes[index]->forme.line);
    }
}
/**
 * @brief This function modifies the style of a specific shape in the SVG scene at the given index.
 * @param svg A pointer to the SVG_t structure representing the SVG scene.
 * @param index The index of the shape whose style is to be modified in the SVG scene.
 */
void modify_shape_svg(SVG_t *svg, int index)
{
    if (svg == NULL || index < 0 || index >= svg->count)
        printf("Error : invalid index or SVG is NULL.\n");
    return;

    if (svg->formes[index]->style != NULL)
    {
        modify_style(svg->formes[index]->style);
    }
}