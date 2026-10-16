#include <stdio.h>
#include <ask_integer.h>
#include <ask_integer_range.h>
#include "point.h"
int main(void) 
{
    Point_t point;
    point.x = ask_integer("Rentrer la valeur de x ");
    point.y = ask_integer("Rentrer la valeur de y");

}
