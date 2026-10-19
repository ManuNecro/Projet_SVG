#include "ask_integer_range.h"
#include "ask_navigation.h"
#include "clear_buffer.h"
#include <stdio.h>

/**
 * @brief This function displays a navigation menu to the user and prompts for a selection within a specified range.
 * @param menu A string containing the menu options to display.
 * @param min The minimum acceptable selection value (inclusive).
 * @param max The maximum acceptable selection value (inclusive).
 * @return The valid integer input provided by the user within the specified range.
 */
int ask_navigation(char* menu, int min, int max)
{
    return ask_integer_range(menu, min,max);
}