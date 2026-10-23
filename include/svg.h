#ifndef SVG_H
#define SVG_H
#include "style.h"
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"

typedef enum
{
    FORME_RECTANGLE,
    FORME_ELLIPSE,
    FORME_LINE,
} TypeForme_e;
/**
 * @brief This union allows storing a pointer to one of the shape types (rectangle, ellipse, or line) in the Forme_t structure.
 */
typedef union
{
    Rectangle_t *rectangle;
    Ellipse_t *ellipse;
    Line_t *line;
} DataForme_u;
/**
 * @brief This structure represents a shape (Forme_t) that can be either a rectangle, an ellipse, or a line, along with its associated style.
 */
typedef struct Forme_s
{
    TypeForme_e type;
    DataForme_u forme;
    Style_t *style;
} Forme_t;

/**
 * @brief This structure represents an SVG scene that can contain multiple shapes (Forme_t) with their associated styles.
 */
typedef struct SVG_s
{
    Forme_t **formes;
    int capacity;
} SVG_t;

SVG_t *create_svg(int capacity);

void add_shape_to_svg(SVG_t *svg, Forme_t *shape);

void delete_shape_svg(SVG_t *svg, int index);

void modify_shape_svg(SVG_t *svg, int index);

void delete_svg(SVG_t *svg);

#endif