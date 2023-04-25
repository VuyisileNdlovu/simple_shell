#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied
 *
 * Return: pointer to the resulting string
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i;
    char *ret = dest;

    for (i = 0; src[i] != '\0' && i < n; i++)
    {
        dest[i] = src[i];
    }
    for (; i < n; i++)
    {
        dest[i] = '\0';
    }

    return (ret);
}

/**
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 *
 * Return: pointer to the resulting string
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *ret = dest;

    for (i = 0; dest[i] != '\0'; i++)
    {
    }
    for (j = 0; src[j] != '\0' && j < n; j++)
    {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';

    return (ret);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 *
 * Return: pointer to the first occurrence of the character in the string
 */
char *_strchr(char *s, char c)
{
    do {
        if (*s == c)
        {
            return (s);
        }
    } while (*s++ != '\0');

    return (NULL);
}

