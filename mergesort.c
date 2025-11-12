#include <stdio.h>


void merge(int arr[], int inicio, int meio, int fim) // Função que "mescla" duas metades do vetor em ordem
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Vetores temporários
    int esquerda[n1], direita[n2];

    // Copia os dados para os vetores temporários
    for (i = 0; i < n1; i++)
        esquerda[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        direita[j] = arr[meio + 1 + j];

    i = 0;  // índice do vetor esquerdo
    j = 0;  // índice do vetor direito
    k = inicio;  // índice do vetor principal

    // Mescla as duas metades em ordem
    while (i < n1 && j < n2) 
    {
        if (esquerda[i] <= direita[j]) 
        {
            arr[k] = esquerda[i];
            i++;
        } 
        else 
        {
            arr[k] = direita[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes, se houver
    while (i < n1) 
    {
        arr[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int inicio, int fim) 
{
    if (inicio < fim) 
    {
        int meio = inicio + (fim - inicio) / 2;

       
        mergeSort(arr, inicio, meio); // Ordena a primeira e a segunda metade
        mergeSort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim); // Mescla as duas metades
    }
}

void imprimeVetor(int arr[], int tamanho) 
{
    for (int i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    imprimeVetor(arr, tamanho);

    mergeSort(arr, 0, tamanho - 1);

    printf("\nVetor ordenado com Merge Sort:\n");
    imprimeVetor(arr, tamanho);

    return 0;
}
