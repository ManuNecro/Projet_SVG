#include "export_svg.h"
#include "rectangle.h"
#include "ellipse.h"
#include "ligne.h"
#include "style.h"
#include <stdio.h>

void export_svg_rectangle(FILE *file, Rectangle_t *rect,Style_t *style)
{


    if (file == NULL || rect == NULL) return; 

    fprintf(file ,"<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" />\n",
    rect->origin->x, rect->origin->y,rect->widght,rect->height,style->fill->r,style->fill->g,style->fill->b,
    style->outline->r,style->outline->g,style->outline->b);

}