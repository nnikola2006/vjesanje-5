#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char naziv[30];
    char ekstenzija[10];
    long velicina;
} DOKUMENT;

DOKUMENT* formiraj(int *);
void ispisi(DOKUMENT);

int main()
{
    DOKUMENT *dok; // nas "niz"
    int n;
    long granica; // nasa vrijednost od koje velicina naseg dokumenta mora biti veca

    // pravi niz
    dok = formiraj(&n);

    scanf("%ld", &granica);

    // nista ispisuje klasicno
    for(int i = 0; i < n; i++)
    {
        if(dok[i].velicina > granica)
        {
            ispisi(dok[i]);
        }
    }
    // jer je heap memory mora se free inace ce nas brdja poobarat
    free(dok);

    return 0;
}

DOKUMENT* formiraj(int *n)
{
    DOKUMENT *niz;
    scanf("%d", n);

    // isto ko u proslom dynamic mem allocation (boli me kurac sto pisem na eng.)
    // (Dabogda vam gogi procita ovo)
    niz = (DOKUMENT *)malloc((*n) * sizeof(DOKUMENT));

    for(int i = 0; i < *n; i++)
    {
        scanf("%29s %9s %ld", niz[i].naziv, niz[i].ekstenzija, &niz[i].velicina);
    }

    return niz;
}

// sta mislis da ce radit genije, zasto ovo i dalje 
// citas kao lice nemas potrebe, ako si procitao/la do kraja ti si debil
void ispisi(DOKUMENT d)
{
    printf("%s.%s | %ld [B]\n", d.naziv, d.ekstenzija, d.velicina);
}
















// MODIFIKACIJE
void sortiraj(DOKUMENT *d, int n)
{
    DOKUMENT tmp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(d[i].velicina < d[j].velicina)
            {
                tmp = d[i];
                d[i] = d[j];
                d[j] = tmp;
            }
        }
    }
}


int ista_ekstenzija(DOKUMENT *d, int n, const char *ext)
{
    int brojac = 0;

    for(int i = 0; i < n; i++)
    {
        if(strcmp(d[i].ekstenzija, ext) == 0)
        {
            brojac++;
        }
    }

    return brojac;
}
// Ako ne znas stringove dadnu ovo
int ista_velicina(DOKUMENT *d, int n, long vel)
{
    int brojac = 0;

    for(int i = 0; i < n; i++)
    {
        if(d[i].velicina == vel)
        {
            brojac++;
        }
    }

    return brojac;
}


// Promjena structa
typedef struct
{
    char naziv[30];
    char ekstenzija[10];
    char autor[30];
    long velicina;
} DOKUMENT;
void autor(DOKUMENT *d, int n, const char *autor)
{
    for(int i = 0; i < n; i++)
    {
        if(strcmp(d[i].autor, autor) == 0)
        {
            printf("%s.%s | %ld [B] | %02d.%02d.%d\n",
                   d[i].naziv,
                   d[i].ekstenzija,
                   d[i].velicina,
                   d[i].datum.dan,
                   d[i].datum.mjesec,
                   d[i].datum.godina);
        }
    }
}


// Novi struct
typedef struct
{
    int dan;
    int mjesec;
    int godina;
} DATUM;
// Promjena structa
typedef struct
{
    char naziv[30];
    char ekstenzija[10];
    long velicina;
    DATUM datum;
} DOKUMENT;
void ispisi_2022(DOKUMENT *d, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(d[i].datum.godina == 2022)
        {
            printf("%s.%s | %ld [B]\n",
                   d[i].naziv,
                   d[i].ekstenzija,
                   d[i].velicina);
        }
    }
}
