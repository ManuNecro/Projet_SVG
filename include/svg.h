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
    TypeForme_e type;  // Indique quelle forme est stockée dans l'union
    DataForme_u forme; // Le pointeur vers la forme réelle
    Style_t *style;    // Le style appliqué à la forme
} Forme_t;


#endif