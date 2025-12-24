int duzina(char *s)
{
  int d = -1;
  while (s[++d]);
  return d;
}

void kopiraj(char *s1, char *s2)
{
  while (*s1++ = *s2++);
}

int uporedi(char *s1, char *s2)
{
  int i;
  for (i = 0; s1[i] && s1[i] == s2[i]; i++);
  return s1[i] - s2[i];
}

int palindrom(char *s)
{
  int d = duzina(s), i;
  for (i = 0; i < d / 2; i++)
    if (s[i] != s[d - i - 1]) return 0;
  return 1;
}

int pozicija(char *s1, char *s2)
{
  int i, j;
  for (i = 0; s1[i]; i++)
  {
    for (j = 0; s2[j] && s2[j] == s1[i + j]; j++);
    if (!s2[j]) return i;
  }
  return -1;
}

void izbaci(char *s1, char *s2)
{
  int i = 0, j, k;
  while (s1[i])
  {
    for (j = 0; s2[j] && s2[j] == s1[i + j]; j++);
    if (!s2[j])
    {
      for (k = i; s1[k + j]; k++)
        s1[k] = s1[k + j];
      s1[k] = 0;
    }
    else
      i++;
  }
}

void konkatenacija(char *s1, char *s2)
{
  while (*s1) s1++;
  while (*s1++ = *s2++);
}

// krece na poziciji r
void konkatenacija(char *s1, char *s2, char *r)
{
  while (*r++ = *s1++);
  r--;
  while (*r++ = *s2++);
}

char* konkatenacija(char *s1, char *s2)
{
  char *r, *t;
  int d1 = -1, d2 = -1;
  while (s1[++d1]);
  while (s2[++d2]);
  t = r = (char *)calloc(d1 + d2 + 1, sizeof(char));
  while (*t++ = *s1++);
  t--;
  while (*t++ = *s2++);
  return r;
}
