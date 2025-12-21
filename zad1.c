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



















// MODIFIKACIJA
double povrsina(TROUGAO t)
{
    // Računanje stranica
    double a = sqrt((t.A.x - t.B.x)*(t.A.x - t.B.x) + (t.A.y - t.B.y)*(t.A.y - t.B.y));
    double b = sqrt((t.B.x - t.C.x)*(t.B.x - t.C.x) + (t.B.y - t.C.y)*(t.B.y - t.C.y));
    double c = sqrt((t.A.x - t.C.x)*(t.A.x - t.C.x) + (t.A.y - t.C.y)*(t.A.y - t.C.y));

    // Poluperimetar
    double s = (a + b + c) / 2.0;

    // Heronova formula
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
