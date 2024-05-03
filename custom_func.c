#include <stddef.h>
#include <stdlib.h>

/* Custom implementation of strdup */
char *custom_strdup(const char *src)
{
    size_t len;
    size_t i;
    
    if (src == NULL)
        return (NULL);
    
    len = 0;
    while (src[len] != '\0')
    {
        len++;
    }
    
    char *dst = (char *)malloc((len + 1) * sizeof(char));
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
