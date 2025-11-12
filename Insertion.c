#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void imprimir(int numero[]);

int main()
{
    int i, j, troca, numero[5] = {200,10,0,5,30};
    
    printf("Valores armazenados no array");
    imprimir(numero);
    
    for (i = 1; i < 5; ++i) 
    {
        troca = numero[i];
        j = i - 1;

        while (j >= 0 && numero[j] > troca) 
        {
            numero[j + 1] = numero[j];
            j = j - 1;
        }
        numero[j + 1] = troca;
    }



    printf("\n");
    printf("\nValores ordenados");
    imprimir(numero);
    printf("\n");
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
