#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct Xis
{
    int linha, coluna, tam;
} Xis;

typedef struct Ponto
{
    float x, y;
} Ponto;

typedef struct Circulo
{
    Ponto centro;
    float raio;
} Circulo;

typedef struct Triangulo
{
    Ponto sup, base_esq, base_dir;
} Triangulo;

#define MAX_TAM 100

// 1)

void matrizIdentidade(int M[][MAX_TAM], int n)
{
    int i = 0, j = 0;
    for (int i = 0; i < n; ++i)
    {
        M[i][i] = 1;
    }
}

// 2)

int insereXis(int M[][MAX_TAM], int n, Xis x)
{
    if (x.linha < 0 || x.coluna > n || x.linha > n || x.coluna >= n)
    {
        return 0;
    }
    int i = 0;
    int j = 0, a = 0, k = 0;
    for (i = 0; i < x.linha + x.tam; ++i)
    {
        for (j = i + 1; j < x.coluna + x.tam; j++)
        {
            M[i][j] = 0;
            M[j][i] = 0;
        }
        M[i][i] = 1;
        M[i][x.tam - 1 - i] = 1;
    }
    return 1;
}

// 3)

Xis maiorXis(int M[][MAX_TAM], int n, int i, int j)
{
    // seu codigo aqui
    Xis x;
    int k = 0, l = 0, s = i + j, d = i - j;
    x.tam = MAX_TAM;
    for (k = 0; k < i; k++)
    {
        for (l = 0; l < j; l++)
        {
            if (k + l == s && k - l == d)
            {
                if (M[k][l] == 0)
                    x.tam = 0;
            }
            else if (M[k][l] != 0)
            {
                x.tam = 0;
            }
        }
    }
    return x;
}

// 4)

int lerXis(Xis *x, int n)
{
    int tentativa = 0;
    do
    {
        scanf("%d %d %d", &x->linha, &x->coluna, &x->tam);
        tentativa++;
    } while (x->linha - (x->tam - 1) < 0 || x->coluna - (x->tam - 1) < 0 || x->linha + (x->tam - 1) > n || x->coluna + (x->tam - 1) > n && x->linha != x->coluna);
    return tentativa;
}

// 5)

int numCharsRepetidos(char str[])
{
    int cont[256];
    int i;
    for (i = 0; i < 256; i++)
    {
        // printf("linha 94");
        cont[i] = 0;
    }
    i = 0;
    while (str[i] != '\0')
    {
        // printf("linha 100");
        cont[toupper(str[i])]++;
        i++;
    }
    int n = 0;
    for (i = 0; i <= 256; i++)
    {
        // printf("linha 106");
        n += (cont[i] > 1);
    }
    return n;
}

// 6

float dist(Ponto p1, Ponto p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float dist2(float x1, float x2, float y1, float y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float areaC(Circulo c)
{
    return 3.141592 + pow(c.raio, 2);
}

int centroT(Triangulo v)
{
    return (v.sup.x + v.sup.y + v.base_esq.x + v.base_esq.y + v.base_dir.x + v.base_dir.y) / 3;
}
int estaContidoCirculoTriangulo(Circulo cir, Triangulo tri)
{
    if (centroT(tri) <= cir.raio)
    {
        if (dist(tri.sup, tri.base_esq) <= 2 * cir.raio && dist(tri.sup, tri.base_dir) <= 2 * cir.raio && dist(tri.base_dir, tri.base_esq) <= 2 * cir.raio)
        {
            return 1;
        }
    }
    else
        return 0;
}
// 0

void minha_main()
{
    // Voce pode simular uma funcao main nesta funcao. Use-a para testar o que quiser.
    // Para isso, execute a sua prova e entre com o exercicio 0.
    // Isso fara com que esta funcao (minha_main) seja chamada pelo VPL.
    // Importante: esta funcao NAO sera avaliada!!! No entanto, erros de compilacao nesta funcao invalidam (nota 0!) TODA a prova!

    printf("\nPor enquanto nao estou fazendo nada :(");
}
