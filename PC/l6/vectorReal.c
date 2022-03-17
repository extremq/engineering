#include <stdio.h>
#include <math.h>

void citireVector(int *n, double *v)
{
    printf("n = ");
    scanf("%d", n);

    int i;

    printf("x = [\n");
    for(i = 0; i < *n; ++i)
    {
        scanf("%lf", &v[i]);
    }
    printf("]\n");

    return;
}

void afisareVector(int n, double *v)
{
    int i;

    printf("x = [ ");
    for(i = 0; i < n; ++i)
    {
        printf("%.2lf ", v[i]);
    }
    printf("]\n");

    return;
}

double valoareMedie(int n, double *v)
{
    int i;
    double medie = 0.0L;
    
    for(i = 0; i < n; ++i)
    {
        medie += v[i];
    }
    
    medie = (double) medie / n;

    return medie;
}

double abatereMediePatratica(int n, double *v)
{
    int i;
    double medie = valoareMedie(n, v);
    double abatere = 0.0L;

    for(i = 0; i < n; ++i)
    {
        abatere += pow(v[i] - medie, 2);
    }

    abatere = sqrt(abatere / (n * (n - 1)));
    
    return abatere;
}

int elementeSubMedie(int n, double *v)
{
    int i, cate = 0;
    double medie = valoareMedie(n, v);
    
    for(i = 0; i < n; ++i)
    {
        if(v[i] <= medie)
        {
            ++cate;
        }
    }

    return cate;
}

int vectorElementeSubMedie(int n, double *v, double *y)
{
    int j = 0, i;
    double medie = valoareMedie(n, v);

    for(i = 0; i < n; ++i)
    {
        if(v[i] <= medie)
        {
            y[j++] = v[i];
        }
    }

    return j;
}

void afisareRezultate(int *n, double *v, double *y)
{
    citireVector(n, v);
    
    printf("Vectorul citit este: \n");
    afisareVector(*n, v);

    printf("Valoarea medie este: \n%.2lf\n", valoareMedie(*n, v));

    printf("Valoarea abaterii medii patratice este: \n%.2lf\n",
            abatereMediePatratica(*n, v));

    printf("Numarul de elemente ce nu depasesc valoarea medie: \n%d\n",
           elementeSubMedie(*n, v));

    printf("Numarul de elemente ale vectorului y: \n%d\n",
           vectorElementeSubMedie(*n, v, y));

    return;  
}
