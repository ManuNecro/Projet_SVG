#include "svg.h"
#include "ask_integer.h"
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

    svg->formes = malloc(sizeof(Forme_t *) * capacity);
    if (svg->formes == NULL)
    {
        free(svg);
        return NULL;
    }
    // we initialize the array of shapes to NULL to indicate that no shapes have been added yet
    for (int i = 0; i < capacity; i++)
    {
        svg->formes[i] = NULL;
    }

    svg->capacity = capacity;
    return svg;
}

/**
 * @brief This function adds a shape (Forme_t) to the SVG scene, if there is enough capacity.
 * @param svg A pointer to the SVG_t structure representing the SVG scene.
 * @param shape The Forme_t structure representing the shape to be added.
 */
void add_shape_to_svg(SVG_t *svg, Forme_t *shape)
{
    if (svg == NULL || shape == NULL)
    {
        printf("Error : SVG or shape is NULL.\n");
        return;
    }
    // On ajoute la forme au tableau de formes
    for (int i = 0; i < svg->capacity; i++)
    {
        if (svg->formes[i] == NULL)
        {
            svg->formes[i] = shape;
            return;
        }
    }

    printf("Error : SVG is full, cannot add more shapes.\n");
}

/**
 * @brief This function deletes an entire SVG scene, freeing all allocated memory for shapes and their associated styles.
 * @param svg A pointer to the SVG_t structure representing the SVG scene to be deleted.
 */

void delete_svg(SVG_t *svg)
{
    if (svg == NULL)
        return;

    if (svg->formes != NULL)
    {
        for (int i = 0; i < svg->capacity; i++)
        {
            if (svg->formes[i] != NULL)
            {
                delete_shape_svg(svg, i);
            }
        }
        free(svg->formes);
    }
    free(svg);
}

/**
 * @brief This function deletes a specific shape from the SVG scene at the given index, freeing its associated style and shape data.
 * @param svg A pointer to the SVG_t structure representing the SVG scene.
 * @param index The index of the shape to be deleted in the SVG scene.
 */
void delete_shape_svg(SVG_t *svg, int index)
{

    if (svg == NULL || index < 0 || index >= svg->capacity)
    {
        printf("Error : Invalid index or SVG is NULL.\n");
        return;
    }

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
    free(svg->formes[index]);
    svg->formes[index] = NULL;
}
/**
 * @brief This function modifies the style of a specific shape in the SVG scene at the given index.
 * @param svg A pointer to the SVG_t structure representing the SVG scene.
 * @param index The index of the shape whose style is to be modified in the SVG scene.
 */
void modify_shape_svg(SVG_t *svg, int index)
{
    if (svg == NULL || index < 0 || index >= svg->capacity)
        printf("Error : invalid index or SVG is NULL.\n");
    return;
    if (svg->formes[index] == NULL)
        return;

    if (svg->formes[index]->style != NULL)
    {
        modify_style(svg->formes[index]->style);
    }

    switch (svg->formes[index]->type)
    {
    case FORME_RECTANGLE:
        modify_point(svg->formes[index]->forme.rectangle->origin);
        svg->formes[index]->forme.rectangle->width = ask_integer("New width of the rectangle: ");
        svg->formes[index]->forme.rectangle->height = ask_integer("New height of the rectangle: ");
        break;
    case FORME_ELLIPSE:
        modify_point(svg->formes[index]->forme.ellipse->center);
        svg->formes[index]->forme.ellipse->rx = ask_integer("New radius X of the ellipse: ");
        svg->formes[index]->forme.ellipse->ry = ask_integer("New radius Y of the ellipse: ");
        break;
    case FORME_LINE:
        printf("New coordinates for the first point of the line:\n");
        modify_point(svg->formes[index]->forme.line->p1);
        printf("New coordinates for the second point of the line:\n");
        modify_point(svg->formes[index]->forme.line->p2);
        break;
    }
}