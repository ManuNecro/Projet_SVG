#ifndef STYLE_H
#define STYLE_H
#include "create_color.h"
#include "point.h"
#include "rotate.h"
/**
 * @brief This structure represents the style of a shape, including fill color, outline color, translation, and rotation.
 */
typedef struct Style_s
{
    Color_t *fill;
    Color_t *outline;
    Point_t *translate;
    Rotate_t *rotate;

} Style_t;

Style_t *create_style(void);

void modify_style(Style_t *style);

void print_style(Style_t *style);

void delete_style(Style_t *style);

#endif