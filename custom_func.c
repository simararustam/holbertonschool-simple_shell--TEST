/* custom_strdup: Custom implementation of strdup */
char *custom_strdup(const char *src)
{
    if (src == NULL)return NULL;
    size_t len = 0;
    while (src[len] != '\0') len++;
    char *dst = malloc(len + 1);
    if (dst == NULL) return NULL;
    for (size_t i = 0; i <= len; i++) dst[i] = src[i];
    return dst;
}

/* custom_strcmp: Custom implementation of strcmp */
int custom_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (unsigned char)(*s1) - (unsigned char)(*s2);
}

/* custom_strlen: Custom implementation of strlen */
size_t custom_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0') len++;
    return len;
}
