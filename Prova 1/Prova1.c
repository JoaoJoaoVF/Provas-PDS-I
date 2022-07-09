#include <stdio.h>
// arquivo inicial da prova.

// implemente abaixo os codigos das funcoes da prova:
// EXERCICIO 1
int cadastraUsuario(int *chave, int *senha)
{
    int login;
    do
    {
        scanf("%d %d", chave, senha);
    } while (*chave < 1000 || *chave > 999999 || *senha < 1000 || *senha > 999999);
    if (*chave > 2000)
    {
        login = 3;
        return login;
    }
    else
    {
        login = 5;
        return login;
    }
}
// EXERCICIO 2
int verificaSenha(int tentativa, int senha)
{
    while (tentativa == senha)
    {
        return 1;
    }
    return 0;
}

// EXERCICIO 3
int acessoConta(int senha, int n)
{
    int tentativa;
    int x, modo;
    x = 1;
    modo = 1;
    while (x <= n)
    {
        scanf("%i", &tentativa);
        if (verificaSenha(tentativa, senha) == 1)
        {
            x = n;
            return 1;
        }
        else if (modo != 1 && tentativa > 10 && senha % tentativa == 0)
        {
            x = n;
            return 1;
        }
        else if (tentativa == -999)
        {
            modo = 0;
        }
        x++;
    }
    return 0;
}
// EXERCICIO 4
char cartaoCredito(int score)
{
    if (score >= 0 && score <= 400)
    {
        printf("Cartao negado\n");
        return 'N';
    }
    else if (score <= 600)
    {
        printf("Necessita de mais detalhes\n");
        return 'X';
    }
    else if (score <= 800)
    {
        printf("Cartao basico\n");
        return 'B';
    }
    else if (score <= 1000)
    {
        printf("Cartao gold\n");
        return 'A';
    }
    else if (score < 0 || score > 1000)
    {
        printf("Score Invalido\n");
        return 'X';
    }
}
// EXERCICIO 5
void banco()
{
    int chave, senha, n, score, x;
    n = cadastraUsuario(&chave, &senha);
    printf("%d\n", n);
    x = acessoConta(senha, n);
    printf("%d\n", x);
    if (x == 1)
    {
        printf("Acesso realizado com sucesso\n");
        score = chave % 1000;
        printf("%c\n", cartaoCredito(score));
    }
    else
    {
        printf("Cliente bloqueado\n");
    }
}
// EXERCICIO 7
int codigoVerificador(int chave)
{

    int X = 0;
    while (chave != 0)
    {
        if (chave % 2 != 0)
        {
            X++;
        }
        chave = chave / 2;
    }
    if (X > 10)
    {
        return X % 10;
    }

    return X;
}
// IMPORTANTE: voce nao deve implementar a funcao main()!