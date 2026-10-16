#include <stdio.h>
#include "ask_integer_range.h"
#include "ask_navigation.h"
#include "clear_buffer.h"

int ask_navigation(char* menu, int min, int max)
{
    return ask_integer_range(menu, min,max);
}