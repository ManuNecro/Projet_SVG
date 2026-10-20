#include "export_svg.h"
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"
#include "style.h"
#include "svg.h"
#include <stdio.h>

/**
 * @brief This function exports an entire SVG scene to a file, including all shapes and their associated styles.
 * @param filename The name of the file to which the SVG scene will be exported.
 * @param svg A pointer to the SVG_t structure representing the SVG scene to be exported.
 * @param width The width of the SVG canvas.
 * @param height The height of the SVG canvas.
 */
void export_scene_svg(const char *filename, SVG_t *svg, int width, int height)
{
    if (svg == NULL)
        return;

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier %s\n", filename);
        return;
    }
    // Write the SVG header with the specified width and height
    fprintf(file, "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\">\n", width, height);

    // Iterate through the shapes in the SVG scene and export each one
    for (int i = 0; i < svg->count; i++)
    {
        Forme_t formes = *svg->formes[i];
        // Export each shape based on its type
        switch (formes.type)
        {
        case FORME_RECTANGLE:
            export_svg_rectangle(file, formes.forme.rectangle, formes.style);
            break;
        case FORME_ELLIPSE:
            export_svg_ellipse(file, formes.forme.ellipse, formes.style);
            break;
        case FORME_LINE:
            export_svg_line(file, formes.forme.line, formes.style);
            break;
        }
    }

    // Close the SVG tag and the file
    fprintf(file, "</svg>\n");
    fclose(file);

    printf("Fichier %s genere avec succes !\n", filename);
}

/**
 * @brief This function exports a rectangle to an SVG file with the specified style.
 * @param file A pointer to the FILE object representing the SVG file.
 * @param rect A pointer to the Rectangle_t structure representing the rectangle to be exported.
 * @param style A pointer to the Style_t structure representing the style to be applied to the rectangle/square.
 */
void export_svg_rectangle(FILE *file, Rectangle_t *rect, Style_t *style)
{
    if (file == NULL || rect == NULL || style == NULL)
        return;

    fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" transform=\"translate(%d,%d) rotate(%d)\" />\n",
            rect->origin->x, rect->origin->y, rect->width, rect->height,
            style->fill->r, style->fill->g, style->fill->b,
            style->outline->r, style->outline->g, style->outline->b,
            style->translate->x, style->translate->y,
            style->rotate->rotate_angle);
}

/**
 * @brief This function exports an ellipse to an SVG file with the specified style.
 * @param file A pointer to the FILE object representing the SVG file.
 * @param ellipse A pointer to the Ellipse_t structure representing the ellipse to be exported.
 * @param style A pointer to the Style_t structure representing the style to be applied to the ellipse/Circle.
 */
void export_svg_ellipse(FILE *file, Ellipse_t *ellipse, Style_t *style)
{
    if (file == NULL || ellipse == NULL || style == NULL)
        return;

    fprintf(file, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" transform=\"translate(%d,%d) rotate(%d)\" />\n",
            ellipse->center->x, ellipse->center->y, ellipse->rx, ellipse->ry,
            style->fill->r, style->fill->g, style->fill->b,
            style->outline->r, style->outline->g, style->outline->b,
            style->translate->x, style->translate->y,
            style->rotate->rotate_angle);
}

/**
 * @brief This function exports a line to an SVG file with the specified style.
 * @param file A pointer to the FILE object representing the SVG file.
 * @param ligne A pointer to the Ligne_t structure representing the line to be exported.
 * @param style A pointer to the Style_t structure representing the style to be applied to the line.
 */
void export_svg_line(FILE *file, Line_t *ligne, Style_t *style)
{
    if (file == NULL || ligne == NULL || style == NULL)
        return;

    fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"rgb(%d,%d,%d)\" transform=\"translate(%d,%d) rotate(%d)\" />\n",
            ligne->p1->x, ligne->p1->y, ligne->p2->x, ligne->p2->y,
            style->outline->r, style->outline->g, style->outline->b,
            style->translate->x, style->translate->y,
            style->rotate->rotate_angle);
}
