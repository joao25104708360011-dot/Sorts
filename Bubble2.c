#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void imprimir(int numero[]);

int main()
{
    int i, aux, troca, numero[5] = {200,10,0,5,30};
    
    printf("Valores armazenados no array");
    imprimir(numero);
    printf("\n");

    troca = 1;
    while (troca == 1)
    {
        troca = 0;        
        for (i = 0; i <= 3; i++)
        {
            if (numero[i] < numero[i + 1])
            {
                troca = 1;
                aux = numero[i];
                numero[i] = numero[i + 1];
                numero[i + 1] = aux;
            }
        }
    }
    printf("\n\n");
    printf("Valores ordenados");
    imprimir(numero);
    printf("\n\n");
    return 0;
}

void imprimir(int numero[])
{
    int i;

    for (i=0; i<5; i++)
    {
        printf("\n|Posicao: %d | Número: %d|", i, numero[i]);
    }
}