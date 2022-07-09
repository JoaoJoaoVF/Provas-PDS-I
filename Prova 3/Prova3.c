#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 1
float verificaValidade(int filial, int ini, int fim)
{
    if (filial > 5 || filial < 1)
    {
        return 0;
    }
    else if (fim < ini)
    {
        return 0;
    }
    else if (ini < 1)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
float somaSaldo(char nome_arquivo[], int filial, int ini, int fim)
{
    float valor[5];
    float soma = 0;
    FILE *arq;
    arq = fopen(nome_arquivo, "r");
    if (arq == NULL || verificaValidade(filial, ini, fim) == 0)
    {
        return 0;
    }
    else if (verificaValidade(filial, ini, fim) == 2)
    {
        ini = 1;
    }
    char buffer[10000];
    int linha = 0;
    while (!feof(arq))
    {
        fgets(buffer, 10000, arq);
        linha++;
        if (linha >= ini && linha <= fim)
        {
            valor[0] = atof(strtok(buffer, " "));
            valor[1] = atof(strtok(NULL, " "));
            valor[2] = atof(strtok(NULL, " "));
            valor[3] = atof(strtok(NULL, " "));
            valor[4] = atof(strtok(NULL, " "));
            soma += valor[filial - 1];
            ;
        }
    }
    fclose(arq);
    return soma;
}

// 2
float **carregaLista(char nome_arquivo[])
{
    float **lista;
    char buffer[1024];
    FILE *arq = fopen(nome_arquivo, "r");

    int num_linhas = 0;
    fscanf(arq, "%d\n", &num_linhas);

    lista = (float **)malloc((num_linhas + 1) * sizeof(float *));

    char *mes;
    int ano, qtde;
    float gasto;

    for (int i = 0; i < num_linhas; i++)
    {
        fgets(buffer, 1024, arq);
        mes = (strtok(buffer, " "));
        ano = atoi(strtok(NULL, " "));
        qtde = atoi(strtok(NULL, " "));

        lista[i] = (float *)malloc((qtde + 1) * sizeof(float));

        for (int j = 0; j < qtde; j++)
        {
            gasto = atof(strtok(NULL, " "));
            lista[i][j] = gasto;
        }
        lista[i][qtde] = 0;
    }
    lista[num_linhas] = NULL;
    fclose(arq);
    return lista;
}

// 3
float mes(float **gastos, int i, int j, int s)
{
    if (gastos[i][j] != 0)
    {
        s = s + gastos[i][j] + mes(gastos, i, j + 1, s);
    }
    else if (gastos[i] == NULL)
    {
        return 0;
    }
}
float maiorGasto(float **gastos)
{
    float maiorsoma1 = 0, maiorsoma2 = 0, maiorsoma3 = 0;
    int i = 0, j = 0;
    maiorsoma1 = mes(gastos, 0, 0, maiorsoma1);
    maiorsoma2 = mes(gastos, 1, 0, maiorsoma2);
    maiorsoma3 = mes(gastos, 2, 0, maiorsoma3);
    if (maiorsoma1 > maiorsoma2)
    {
        if (maiorsoma1 > maiorsoma3)
        {
            return maiorsoma1;
        }
        else
        {
            return maiorsoma3;
        }
    }
    else
    {
        if (maiorsoma2 > maiorsoma3)
        {
            return maiorsoma2;
        }
        else
        {
            return maiorsoma3;
        }
    }
}

// 4
// não altere este struct!
typedef struct Empresa
{
    float juros;
    float taxa;
} Empresa;

float valorTotalEmprestimo(float valor, int m, Empresa empresa)
{
    if (m == 1)
    {
        return (((valor + empresa.taxa) * empresa.juros) + (valor + empresa.taxa));
    }

    return valorTotalEmprestimo((((valor + empresa.taxa) * empresa.juros) + (valor)), (m - 1), empresa);
}

// 5
int conta(char *palavra, int saldo)
{
    if (palavra != NULL)
    {
        if (*palavra == '{')
        {
            saldo += 1;
        }
        else if (*palavra == '}')
        {
            saldo -= 1;
        }
        palavra = strtok(NULL, " \n");

        saldo = conta(palavra, saldo);
    }
    return saldo;
}
int diferencaChaves(char *programa)
{
    char *palavra;
    palavra = strtok(programa, " \n");
    int saldo = 0;
    saldo = conta(palavra, saldo);
    return saldo;
}

// Para testes
int minha_main()
{
    return -1;
}