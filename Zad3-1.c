#include <stdio.h>

// 1. strlen - vraća dužinu stringa
int my_strlen(const char *s)
{
    int len = 0;
    while(s[len] != '\0')
        len++;
    return len;
}

// 2. strcpy - kopira string
void my_strcpy(char *dest, const char *src)
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// 3. strcat - dodaje jedan string na kraj drugog
void my_strcat(char *dest, const char *src)
{
    int i = 0;
    while(dest[i] != '\0') // idemo do kraja prvog stringa
        i++;
    int j = 0;
    while(src[j] != '\0') // dodajemo src
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

// 4. strcmp - poredi stringove
int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i]; // pokriva i slučaj različitih dužina
}

// 5. strchr - prvi nastup karaktera u stringu
char* my_strchr(char *s, char c)
{
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == c)
            return &s[i];
        i++;
    }
    return NULL; // nije pronađen
}

// 6. strstr - traži substring
char* my_strstr(char *haystack, char *needle)
{
    if(needle[0] == '\0') return haystack; // prazni string
    int i = 0;
    while(haystack[i] != '\0')
    {
        int j = 0;
        while(needle[j] != '\0' && haystack[i+j] == needle[j])
            j++;
        if(needle[j] == '\0')
            return &haystack[i]; // našli match
        i++;
    }
    return NULL; // nema
}
