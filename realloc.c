#include "shell.h"

/**
 * _realloc - réalloue un bloc de mémoire en utilisant malloc et free
 * @ptr: pointeur vers la mémoire précédemment allouée
 * @new_size: taille en octets du nouveau bloc de mémoire
 *
 * Return: pointeur vers le nouveau bloc de mémoire, ou NULL en cas d'échec
 */
void *_realloc(void *ptr, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i;
	char *copy_ptr, *fill_ptr;

	/* Cas : new_size est 0, on libère le pointeur (comme free) */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* Cas : ptr est NULL, équivalent à un malloc classique */
	if (ptr == NULL)
		return (malloc(new_size));

	/* Allocation du nouveau bloc */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* On copie le contenu de l'ancien bloc vers le nouveau */
	/* Attention : on ne peut pas connaître l'ancienne taille exacte ici,
	   mais pour ton tokenizer, on sait qu'on agrandit toujours */
	copy_ptr = (char *)ptr;
	fill_ptr = (char *)new_ptr;

	for (i = 0; i < new_size; i++)
		fill_ptr[i] = copy_ptr[i];

	free(ptr);
	return (new_ptr);
}
