#include "ask_integer_range.h"
#include "ask_integer.h"
#include "clear_buffer.h"
#include <stdio.h>

/**
 * @brief This function asks the user for an integer value within a specified range. It will keep prompting the user until a valid integer is provided.
 * @param message The message to display to the user when asking for input.
 * @param min The minimum acceptable value (inclusive).
 * @param max The maximum acceptable value (inclusive).
 * @return The valid integer input provided by the user within the specified range.
 */
int ask_integer_range(char *message, int min, int max)
{
    int input_number;

    do
    {
        input_number = ask_integer(message);

        if (input_number < min || input_number > max)
        {
            printf("Error the value must be in the range : %d and %d.\n", min, max);
        }

    } while (input_number < min || input_number > max);

    return input_number;
}