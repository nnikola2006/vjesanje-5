#include <stdio.h>
#include <math.h>

typedef struct
{
    char oznaka; // slovo tacke kao A, B, C, M
    double x;
    double y;
} TACKA;

typedef struct
{
    TACKA A;
    TACKA B;
    TACKA C;
} TROUGAO;

void citaj(TACKA *t);
int provjera(TACKA *t);
TROUGAO trougao(TACKA *t);
double obim(TROUGAO t);

int main()
{
    TACKA t[3];
    TROUGAO tr;

    // Ucitava 3 tacke (puljke)
    for(int i = 0; i < 3; i++)
    {
        citaj(&t[i]);
    }

    // Provjera da li je ispravan trougao
    if(!provjera(t))
    {
        printf("Ne moze se formirati trougao\n");
        return 0;
    }
    tr = trougao(t);

    printf("Obim trougla = %.2lf\n", obim(tr));

    return 0;
}

void citaj(TACKA *t)
{
    scanf(" %c %lf %lf", &t->oznaka, &t->x, &t->y);
}

int provjera(TACKA *t)
{   
    // ona formula za distance izmedju tacka sqrt((x1 - x0)^2 + (y1 - y0)^2)
    double a = sqrt((t[0].x - t[1].x)*(t[0].x - t[1].x) + (t[0].y - t[1].y)*(t[0].y - t[1].y));
    double b = sqrt((t[1].x - t[2].x)*(t[1].x - t[2].x) + (t[1].y - t[2].y)*(t[1].y - t[2].y));
    double c = sqrt((t[0].x - t[2].x)*(t[0].x - t[2].x) + (t[0].y - t[2].y)*(t[0].y - t[2].y));

    // neka pravila kada trougao ne mere da bude
    if(a == 0 || b == 0 || c == 0)
        return 0;

    if(a + b <= c || a + c <= b || b + c <= a)
        return 0;
    
    return 1;
}

TROUGAO trougao(TACKA *t)
{
    TROUGAO tr; // trtrtrtrtrtrtr SAMO TURBODIZEL BAJOOOO PUSI GA STRAHINJA

    tr.A = t[0];
    tr.B = t[1];
    tr.C = t[2];

    return tr;
}

double obim(TROUGAO t)
{   
    double a = sqrt((t.A.x - t.B.x)*(t.A.x - t.B.x) + (t.A.y - t.B.y)*(t.A.y - t.B.y));
    double b = sqrt((t.B.x - t.C.x)*(t.B.x - t.C.x) + (t.B.y - t.C.y)*(t.B.y - t.C.y));
    double c = sqrt((t.A.x - t.C.x)*(t.A.x - t.C.x) + (t.A.y - t.C.y)*(t.A.y - t.C.y));

    return a + b + c;
}



















// Pomocna funkcija
double distanca(TACKA a, TACKA b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}


// MODIFIKACIJA
int je_jednakokraki(TROUGAO *t)
{
    double a = distanca(t->A, t->B);
    double b = distanca(t->B, t->C);
    double c = distanca(t->A, t->C);

    if(a == b || a == c || b == c)
        return 1;

    return 0;
}

double povrsina(TROUGAO *t)
{
    double a = distanca(t->A, t->B);
    double b = distanca(t->B, t->C);
    double c = distanca(t->A, t->C);

    double s = (a + b + c) / 2.0;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int je_pravougli(TROUGAO *t)
{
    double a = distanca(t->A, t->B);
    double b = distanca(t->B, t->C);
    double c = distanca(t->A, t->C);

    if(a*a + b*b == c*c)
        return 1;
    if(a*a + c*c == b*b)
        return 1;
    if(b*b + c*c == a*a)
        return 1;

    return 0;
}

double R(TROUGAO *t)
{
    double a = distanca(t->A, t->B);
    double b = distanca(t->B, t->C);
    double c = distanca(t->A, t->C);

    return (a * b * c) / (4.0 * povrsina(t));
}

double r(TROUGAO *t)
{
    double a = distanca(t->A, t->B);
    double b = distanca(t->B, t->C);
    double c = distanca(t->A, t->C);

    double s = (a + b + c) / 2.0;

    return povrsina(t) / s;
}

int je_nejednakostranicni(TROUGAO *t)
{
    double a = distanca(t->A, t->B);
    double b = distanca(t->B, t->C);
    double c = distanca(t->A, t->C);

    if(a != b && a != c && b != c)
        return 1;

    return 0;
}


