#include <stdio.h>
// Fonction qui permet de vider  le terminal après le scanf pour eviter les erreurs et les boucles infinis.
void clear_buffer(void) // On force le curseur a bouger dans le terminal et ne pas rester bloquer sur la gauche
{
    char c = 'a';
    while (c != '\n' && c != EOF) // tant que c n'est pas \n retour a la ligne ou , EOF end of file donc fin de fichier
    {
        c = getc(stdin);
    }
}
