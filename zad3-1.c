#include <string.h>

// 1. Kopiranje
char *strcpy(char *dest, const char *src);        // Kopira cijeli string
char *strncpy(char *dest, const char *src, size_t n); // Kopira do n karaktera

// 2. Dodavanje / konkatenacija
char *strcat(char *dest, const char *src);       // Dodaje src na kraj dest
char *strncat(char *dest, const char *src, size_t n); // Dodaje do n karaktera

// 3. Upoređivanje
int strcmp(const char *s1, const char *s2);     // Poredi cijele stringove
int strncmp(const char *s1, const char *s2, size_t n); // Poredi do n karaktera

// 4. Traženje
char *strchr(const char *s, int c);             // Prvi nastup karaktera c
char *strrchr(const char *s, int c);            // Posljednji nastup karaktera c
char *strstr(const char *haystack, const char *needle); // Prvi nastup substringa

// 5. Dužina
size_t strlen(const char *s);                   // Broj karaktera prije '\0'

// 6. Traženje prvog karaktera iz seta
char *strpbrk(const char *s, const char *accept); // Prvi karakter iz accept koji se pojavljuje u s

// 7. Traženje posljednjeg dijela stringa iz seta
char *strrchr(const char *s, int c);           // Posljednje pojavljivanje karaktera

// 8. Tokenizacija
char *strtok(char *str, const char *delim);    // Razdvaja string po delimiters

// 9. Formiranje i kopiranje sa sigurnošću
size_t strlcpy(char *dest, const char *src, size_t size); // Sigurnija kopija (nije standard C, BSD)
size_t strlcat(char *dest, const char *src, size_t size); // Sigurna konkatenacija (BSD)

// 10. Memorijska manipulacija
void *memset(void *s, int c, size_t n);        // Postavlja n bajtova na c
void *memcpy(void *dest, const void *src, size_t n); // Kopira n bajtova
void *memmove(void *dest, const void *src, size_t n); // Kopira n bajtova sigurno kod preklapanja
int memcmp(const void *s1, const void *s2, size_t n); // Poredi n bajtova
void *memchr(const void *s, int c, size_t n);  // Prvi nastup c u n bajtova




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
