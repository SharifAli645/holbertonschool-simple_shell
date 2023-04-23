#include "main.h"
/**
 * _atoi - functions that converts a string to an integer
 * @s: the string
 *
 * Return: an integer
 **/
int _atoi(char *s)
{
	char *ptr_ri = s;
	unsigned int integer = 0;
	int ten = 0;
	int less = 0;

	while (*ptr_ri != '\0')
	{
		if (*ptr_ri == 45)
		{
			less++;
		}

		if (*ptr_ri > 47 && *ptr_ri < 58)
		{
			integer = (*ptr_ri - 48) + ((integer) * (10 * ten));

			ptr_ri++;

			if ((*ptr_ri <= 47 || *ptr_ri >= 58) && *ptr_ri != '\0')
			{
				return (integer);
			}

			ptr_ri--;
		}

		ten = 1;
		ptr_ri++;
	}
	if ((less % 2) != 0)
		integer = integer * -1;

	return (integer);
}
/**
 * _strlen - counts characters
 * @s: string
 *
 * Return: the size of the string
 **/
int _strlen(char *s)
{
	int a;

	for (a = 0; *s != '\0'; s++)
	{
		a++;
	}
	return (a);
}
/**
 * _strcmp - function that compares two string
 * @s1: first string
 * @s2: second string
 *
 * Return: an integer
 **/
int _strcmp(char *s1, char *s2)
{
	char *ptr_s1;
	char *ptr_s2;
	int dif_num = 0;

	ptr_s1 = s1;
	ptr_s2 = s2;

	while (*ptr_s1 != '\0')
	{
		if (*ptr_s1 != *ptr_s2)
		{
			dif_num = (*ptr_s1 - *ptr_s2);

			return (dif_num);
		}
		ptr_s1++;
		ptr_s2++;
	}
	return (dif_num);
}
/**
 * _strdup - function that returns a pointer to a
 * newly allocated space in memory
 * @str: string to duplicate
 *
 * Return: a pointer
 **/
char *_strdup(char *str)
{
	char *arr;
	int i;
	int size;

	if (str == NULL)
		return (NULL);
	size = strlen(str);

	arr = malloc(sizeof(char) * (size + 1));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size + 1; i++)
	{
		arr[i] = *str;
		str++;
	}
	return (arr);
}
/**
 * _strcat - function that concatenates two strings
 * @dest: source string
 * @src: destination string
 *
 * Return: always a string
 **/
char *_strcat(char *dest, char *src)
{
	char *dest_ptr;
	char *src_ptr;
	int i;

	dest_ptr = dest;
	src_ptr = src;

	for (i = 0; *dest_ptr != '\0'; i++)
	{
		dest_ptr++;
	}

	for (i = 0; *src_ptr != '\0'; i++)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
	}

	*dest_ptr = '\0';

	return (dest);
}
