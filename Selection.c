#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void imprimir(int numero[]);

int main()
{
    int i, j, maior, troca, numero[5] = {200,10,0,5,30};
    
    printf("Valores armazenados no array");
    imprimir(numero);
    
    for (i = 0; i < 5 - 1; i++) 
    {
        maior = i;
    
        for (j = i + 1; j < 5; j++) 
        {
            if (numero[j] > numero[maior]) 
            {
                maior = j;
            }
        }
        
        troca = numero[i];
        numero[i] = numero[maior];
        numero[maior] = troca;
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
