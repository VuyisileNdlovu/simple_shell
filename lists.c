#include "shell.h"
#include <stdlib.h>

/**
 * add_node - adds a node to the start of the list
 * @head: pointer to pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to new node
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    if (!head)
        return NULL;

    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;

    new_node->str = str ? _strdup(str) : NULL;
    new_node->num = num;
    new_node->next = *head;

    *head = new_node;

    return new_node;
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: pointer to pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to new node
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    if (!head)
        return NULL;

    list_t *new_node = malloc(sizeof(list_t));
    if (!new_node)
        return NULL;

    new_node->str = str ? _strdup(str) : NULL;
    new_node->num = num;
    new_node->next = NULL;

    if (*head == NULL)
        *head = new_node;
    else
    {
        list_t *current = *head;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }

    return new_node;
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
    size_t count = 0;
    while (h)
    {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        count++;
    }
    return count;
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: pointer to pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    if (!head || !*head)
        return 0;

    list_t *node_to_delete;
    if (index == 0)
    {
        node_to_delete = *head;
        *head = (*head)->next;
    }
    else
    {
        list_t *current = *head;
        for (unsigned int i = 0; i < index - 1 && current->next != NULL; i++)
            current = current->next;

        if (current->next == NULL)
            return 0;

        node_to_delete = current->next;
        current->next = node_to_delete->next;
    }

    free(node_to_delete->str);
    free(node_to_delete);

    return 1;
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
