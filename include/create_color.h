#ifndef CREATE_COLOR_H
#define CREATE_COLOR_H
#include <stdint.h>

typedef struct Color_s
{
    uint8_t r; // Rouge (0 à 255)
    uint8_t g; // Vert (0 à 255)
    uint8_t b; // Bleu (0 à 255)

} Color_t;


Color_t* new_color(uint8_t red, uint8_t green, uint8_t blue);

void modify_color(Color_t *color);
void print_color(Color_t *color);
void delete_color(Color_t *color);

#endif