#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

/* Custom implementation of strdup */
char *custom_strdup(const char *src)
{
    size_t len;
    size_t i;
    char *dst;
    
    if (src == NULL)
        return (NULL);
    
    len = 0;
    while (src[len] != '\0')
    {
        len++;
    }
    
    dst = (char *)malloc((len + 1) * sizeof(char));
    if (dst == NULL)
        return (NULL);
    
    for (i = 0; i <= len; i++)
    {
        dst[i] = src[i];
    }
    
    return (dst);
}

/* Custom implementation of strcmp */
int custom_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

/* Custom implementation of strlen */
size_t custom_strlen(const char *s)
{
    size_t len;

    len = 0;

    while (s[len] != '\0')
    {
        len++;
    }
    return (len);
}

#include <stdio.h>

int custom_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }

    for (; str[i] != '\0'; ++i)
    {
        result = result * 10 + str[i] - '0';
    }

    return (sign * result);
}

long custom_strtol(const char *str)
{
	long result = 0;
	bool is_negative = false;
	int i = 0;

	if (str[0] == '-')
    {
		is_negative = true;
		i++;
	}

	for (; str[i] != '\0'; ++i)
    {
		if (str[i] >= '0' && str[i] <= '9')
        {
			result = result * 10 + (str[i] - '0');
		}
        
        else
        {
			return (0);
		}
	}

	if (is_negative)
    {
		result = -result;
	}

	return (result);
}
