#ifndef ROTATE_H
#define ROTATE_H
/**
 * @brief This structure represents the rotation of a shape, including the rotation angle.
 */
typedef struct Rotate_s
{
    int rotate_angle;
} Rotate_t;

Rotate_t *rotate_angle(void);

Rotate_t *modify_angle(Rotate_t *rotate);

void print_angle(Rotate_t *rotate);

void delete_angle(Rotate_t *rotate);

#endif