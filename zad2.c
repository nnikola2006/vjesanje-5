#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char naziv[30];
    int dati;
    int primljeni;
    int bodovi;
} TIM;

void ucitaj(TIM *);
TIM* formiraj(int *);
void sortiraj(TIM *, int);
void ispisi(TIM *, int);

int main()
{
    // *liga je taj "niz" koji ima neki broj timova, a n je broj clanova
    TIM *liga;
    int n;

    liga = formiraj(&n);

    sortiraj(liga, n);

    ispisi(liga, n);

    // jer je heap memory mora se free inace ce nas brdja poobarat
    free(liga);

    return 0;
}

void ucitaj(TIM *t)
{
    // %29s jer je definisano max 30 znakova u nizu za string
    scanf("%29s %d %d %d", t->naziv, &t->dati, &t->primljeni, &t->bodovi);
}

// n je ovdje * jer mi unosimo ovde u funkciji broj timova sto ima
// da se stavilo samo n pravila bi se kopija a nama treba promjenit i u main()
TIM* formiraj(int *n)
{
    TIM *niz;

    scanf("%d", n);

    // Dinamicka alokacija memorije za niz
    niz = (TIM *)malloc((*n) * sizeof(TIM));
    if(niz == NULL) // provjera jel dobro alociro ako nije da zna
    {
        printf("Greska u alokaciji memorije\n");
        return NULL;
    }

    // ucitava timove
    for(int i = 0; i < *n; i++)
    {
        ucitaj(&niz[i]);
    }

    return niz;
}

/* Sortira po:
   1. bodovi
   2. gol razlika
   3. dati golovi
*/
void sortiraj(TIM *t, int n)
{
    TIM temp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int gol_razlika1 = t[i].dati - t[i].primljeni;
            int gol_razlika2 = t[j].dati - t[j].primljeni;

            // da
            if(t[j].bodovi > t[i].bodovi ||
                (t[j].bodovi == t[i].bodovi && gol_razlika2 > gol_razlika1) ||
                (t[j].bodovi == t[i].bodovi && gol_razlika2 == gol_razlika1 && t[j].dati > t[i].dati))
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

void ispisi(TIM *t, int n)
{
    // RB. NAZIV je ime kluba, GPO je datih kolova, GPR je primjenih, GR je gol razlika, BOD je bod logicki
    printf("RB. NAZIV                       GPO GPR   GR   BOD\n");
    for(int i = 0; i < n; i++)
    {
        printf("%2d. %-27s %3d %3d %4d %4d\n", i + 1, t[i].naziv, t[i].dati, t[i].primljeni, t[i].dati - t[i].primljeni, t[i].bodovi);
    }
}
