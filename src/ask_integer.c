#include "ask_integer.h"
#include "clear_buffer.h"
#include <stdio.h>

/**
 * @brief This function asks the user for an integer value. It will keep prompting the user until a valid integer is provided.
 * @param message The message to display to the user when asking for input.
 * @return The valid integer input provided by the user.
 */
// Fonction qui demande un entier.
int ask_integer(char *message)
{
    int input_number;
    int result_input;

    do
    {
        printf("%s\n", message);
        result_input = scanf("%d", &input_number);
        clear_buffer();

        if (result_input != 1)
        {
            printf("Error, please enter a valid integer number");
        }
    } while (result_input != 1);
    return input_number;
}