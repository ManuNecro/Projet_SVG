#include <stdio.h>
/**
 * @brief This function clears the input buffer to prevent infinite loops and errors after using scanf.
 * It reads and discards characters from the input buffer until a newline character or EOF is encountered
 */
void clear_buffer(void) // On force le curseur a bouger dans le terminal et ne pas rester bloquer sur la gauche
{
    char c = 'a';
    while (c != '\n' && c != EOF) // tant que c n'est pas \n retour a la ligne ou , EOF end of file donc fin de fichier
    {
        c = getc(stdin);
    }
}
