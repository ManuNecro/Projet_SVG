#ifndef EXPORT_SVG_H
#define EXPORT_SVG_H

#include "rectangle.h"
#include "ligne.h"
#include "ellipse.h"
#include "style.h"
#include <stdio.h>

/**
 * @brief This function exports a rectangle to an SVG file with the specified style.
 * @param file A pointer to the FILE object representing the SVG file.
 * @param rect A pointer to the Rectangle_t structure representing the rectangle to be exported.
 * @param style A pointer to the Style_t structure representing the style to be applied to the rectangle/square.
 */
void export_svg_rectangle(FILE *file, Rectangle_t *rect, Style_t *style);
/**
 * @brief This function exports an ellipse to an SVG file with the specified style.
 * @param file A pointer to the FILE object representing the SVG file.
 * @param ellipse A pointer to the Ellipse_t structure representing the ellipse to be exported.
 * @param style A pointer to the Style_t structure representing the style to be applied to the ellipse/Circle.
 */
void export_svg_ellipse(FILE *file, Ellipse_t *ellipse, Style_t *style);
/**
 * @brief This function exports a line to an SVG file with the specified style.
 * @param file A pointer to the FILE object representing the SVG file.
 * @param ligne A pointer to the Ligne_t structure representing the line to be exported.
 * @param style A pointer to the Style_t structure representing the style to be applied to the line.
 */
void export_svg_line(FILE *file, Ligne_t *ligne, Style_t *style);

#endif

