#ifndef POINT_H
#define POINT_H
/**
 * @brief This structure represents a point in 2D space with x and y coordinates.
 */
typedef struct Point_s
{
    int x;
    int y;
} Point_t;

Point_t *create_point(void);

void modify_point(Point_t *point);

void print_point(Point_t *point);

void delete_point(Point_t *point);

#endif