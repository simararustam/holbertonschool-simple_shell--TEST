#include <errno.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
  * custom_getline - Custom getline function
  * Return: Returns string from buffer
  */

char *custom_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int pos = 0;
	static int bytes_read = 0;
	char *line = NULL;
	int line_size = 0;

	while (1)
	{
		if (pos >= bytes_read)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			pos = 0;
			if (bytes_read <= 0)
				return (NULL);
		}

		while (pos < bytes_read)
		{
			if (buffer[pos] == '\n')
			{
				line = (char *)malloc(line_size + 1);
				if (line == NULL)
					return (NULL);
				
				int i;
				
				for (i = 0; i < line_size; i++)
					line[i] = buffer[pos - line_size + i];
				line[i] = '\0';
				pos++;
				return (line);
			}
			line_size++;
			pos++;
		}
	}
}


/**
  * arg_counter - counts number of arguments
  * @buf: user input
  * @size: size of user input
  * Return: number of argumnets
  */
int arg_counter(char *buf, int size)
{
	int count = 0, i;

	for (i = 1; i < size; i++)
		count += ((buf[i - 1] == ' ' &&
					(buf[i] != ' ' && buf[i] != '\n')) ||
				(i == 1 &&
				 buf[i - 1] != ' '));
	return (count);
}
/**
  * get_command - format command line arguments
  * @buf: buffer for storing user input
  * Return: memory address where arguments are stored
  */
char **get_command(char **buf)
{
	char **array;
	size_t n = 1, k, i, l = 0, count;

	*buf = custom_getline();
	if (*buf == NULL) 
	{
		return (NULL);
	}

	k = strlen(*buf);
	count = arg_counter(*buf, k);
	if (!count) 
	{
		array = malloc(sizeof(char *));
		array[0] = strdup(" ");
		return (array);
	}
	array = malloc(sizeof(char *) * (count + 1));
	if (array == NULL) 
	{
		free(*buf);
		return (NULL);
	}
	for (i = 1; i < k; i++) 
	{
		if ((*buf)[i - 1] == ' ' || (*buf)[i - 1] == '\t' || (*buf)[i - 1] == '\n')
			(*buf)[i - 1] = '\0';
		else if ((*buf)[i - 1] == '\0')
			continue;
		else 
		{
			array[l] = *buf + i - 1;
			while ((*buf)[i] != ' ' && (*buf)[i] != '\t' && (*buf)[i] != '\n')
				i++;
			(*buf)[i] = '\0';
			l++;
		}
	}
	array[l] = NULL;
	return (array);
}
