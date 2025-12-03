#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the pointer to the beginning of the list
 * @str: string to duplicate and store in the new node
 * 
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
    list_t *new;
    char *dup;

    if (str == NULL)
        return (NULL);

    dup = strdup(str);
    if (dup == NULL)
        return (NULL);

    new = malloc(sizeof(list_t));
    if (new == NULL)
    {
        free(dup);
        return (NULL);
    }

    new->str = dup;
    new->len = strlen(str);
    new->next = *head;
    *head = new;

    return (new);
}
