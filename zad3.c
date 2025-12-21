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
