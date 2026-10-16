#include <stdio.h>
#include "ask_integer.h"
#include "clear_buffer.h"

// Fonction qui demande un entier.
int ask_integer(char* message)
{
    int input_number;
    int result_input;

    do
    {
        printf("%s\n", message);
        result_input = scanf("%d", &input_number); // On recupere la valeur de l'utilisateur pour la mettre dans la variable de verification.
        clear_buffer();                            // on evite la boucle infini en vidant le terminal

        if (result_input != 1) // La variable de verification -> vérifie si elle contient bien un nombre entier.
        {
            printf("Error, please enter a valid integer number");
        }
    } while (result_input != 1); // Tant que la variable ne contient pas un nombre entier on reboucle.
    return input_number; // On retourne la valeur de l'utilisateur.
}