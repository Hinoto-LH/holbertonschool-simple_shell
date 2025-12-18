#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        /* Affiche le prompt */
        printf("$ ");
        fflush(stdout); /* fflush force l’écriture immédiate des données mises en tampon (buffer) vers leur destination (terminal, fichier, pipe…).*/

        /* Lecture de la ligne */
        nread = getline(&line, &len, stdin);

        /* Vérification EOF ou erreur (voir man getline, RETURN VALUE) */
        if (nread == -1)
        {
            /* EOF (Ctrl+D) ou erreur */
            printf("\n");
            break;
        }

        /* Affiche la commande saisie */
        printf("%s", line);
    }

    free(line);
    return 0;

}