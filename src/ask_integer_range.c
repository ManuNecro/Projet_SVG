#include <stdio.h>
#include "ask_integer_range.h"
#include "ask_integer.h"
#include "clear_buffer.h"

int ask_integer_range(char* message, int min, int max)
{
    int input_number;

    do
    {
        input_number = ask_integer(message); // On appel la fonction pour demander un entier.

        // On vérifie que la valeur n'est pas en dehors
        if (input_number < min || input_number > max)
        {
            printf("Error the value must be in the range : %d and %d.\n", min, max);
        }

    } while (input_number < min || input_number > max); // On recommence tant que c'est invalide

    return input_number;
}