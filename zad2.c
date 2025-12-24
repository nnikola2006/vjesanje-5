#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char naziv[30];
    int dati;
    int primljeni; // ha ha oni ga primaju jesam smijesan
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
    if(liga == NULL) // U slucaju da nekako ne proradi dinamicka alokacije memorije da ne kresuje program
        return 1;
    
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
    // SYBAU MRVA I TVOJE PJEVANJE (da ovde mi mrva doso pjevat u pozivu)
    TIM *niz;
    scanf("%d", n);

    // Dinamicka alokacija memorije za niz (dabogda plano ko izmisli ovo)
    niz = (TIM *)malloc((*n) * sizeof(TIM));
    if(niz == NULL) // provjera jel dobro alociro ako nije da zna da je balija
    {
        printf("Greska u alokaciji memorije\n");
        return NULL;
    }

    // ucitava balije
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


















// AKO SLUCAJNO budu jeli govna za razmak kod stringa npr. Crvena Zvezda
// samo prepravite funckiju ucitaj u ovo
void ucitaj(TIM *t)
{
    printf("Unesite naziv tima: ");
    fgets(t->naziv, 30, stdin);

    // ukloni \n ako postoji
    size_t len = strlen(t->naziv);
    if(len > 0 && t->naziv[len-1] == '\n')
        t->naziv[len-1] = '\0';

    printf("Unesite dati golovi, primljeni golovi i bodove: ");
    scanf("%d %d %d", &t->dati, &t->primljeni, &t->bodovi);

    getchar(); // uklanja \n nakon scanf, da sljedeći fgets radi
}


// MODIFIKACIJE
// SORTIRANJE PO NAZIVU (alfabetički)
void sortiraj_alf(TIM *t, int n)
{
    TIM tmp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(strcmp(t[i].naziv, t[j].naziv) > 0)
            {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

// SORTIRANJE PO NAJMANJE PRIMLJENIM GOLOVIMA
void sortiraj_primljeni(TIM *t, int n)
{
    TIM tmp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(t[i].primljeni > t[j].primljeni)
            {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

// SORTIRANJE PO NAJMANJE PRIMLJENIM GOLOVIMA
void sortiraj_primljeni(TIM *t, int n)
{
    TIM tmp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(t[i].primljeni > t[j].primljeni)
            {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

int tim_sa_positivnom_gol_razlikom(TIM *t, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(t[i].dati - t[i].primljeni > 0)
            count++;
    }
    return count;
}

int tim_sa_negativnom_gol_razlikom(TIM *t, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(t[i].dati - t[i].primljeni < 0)
            count++;
    }
    return count;
}

int tim_sa_vise_datih_golova(TIM *t, int n, int min_golova)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(t[i].dati > min_golova)
            count++;
    }
    return count;
}

int tim_sa_istim_bodovima(TIM *t, int n, int bodovi)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(t[i].bodovi == bodovi)
            count++;
    }
    return count;
}

// BROJ TIMOVA SA ISTOM GOL RAZLIKOM
int tim_sa_istom_gol_razlikom(TIM *t, int n, int gol_razlika)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if((t[i].dati - t[i].primljeni) == gol_razlika)
            count++;
    }
    return count;
}

// NAJBOLJI TIM PO GOL RAZLICI (vraća indeks)
int najbolji_po_gol_razlici(TIM *t, int n)
{
    int idx = 0;
    int max = t[0].dati - t[0].primljeni;
    for(int i = 1; i < n; i++)
    {
        int gr = t[i].dati - t[i].primljeni;
        if(gr > max)
        {
            max = gr;
            idx = i;
        }
    }
    return idx;
}

// NAJGORI TIM PO BODOVIMA (vraća indeks)
int najgori_tim(TIM *t, int n)
{
    int idx = 0;
    int min = t[0].bodovi;
    for(int i = 1; i < n; i++)
    {
        if(t[i].bodovi < min)
        {
            min = t[i].bodovi;
            idx = i;
        }
    }
    return idx;
}

// PROSJEK BODOVA LIGE
double prosjek_bodova(TIM *t, int n)
{
    int suma = 0;
    for(int i = 0; i < n; i++)
        suma += t[i].bodovi;
    return (double)suma / n;
}

// PROSJEK GOL RAZLIKE
double prosjek_gol_razlike(TIM *t, int n)
{
    int suma = 0;
    for(int i = 0; i < n; i++)
        suma += t[i].dati - t[i].primljeni;
    return (double)suma / n;
}
