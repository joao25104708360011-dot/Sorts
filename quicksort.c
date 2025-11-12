#include <stdio.h>

void swap(int* a, int* b);

// Função de partição
int partition(int arr[], int low, int high) 
{
    // Escolhe o pivô (último elemento do vetor)
    int pivot = arr[high];
    // Índice do menor elemento; indica a posição correta do pivô encontrada até agora
    int i = low - 1;
    // Percorre arr[low..high] e move todos os elementos menores que o pivô para a esquerda.
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Coloca o pivô logo após os elementos menores e retorna sua posição correta
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}

// Implementação do algoritmo QuickSort
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        // pi é o índice retornado pela função partition representando a posição correta do pivô
        int pi = partition(arr, low, high);

        // Chamada recursiva para ordenar os elementos menores que o pivô e os maiores que o pivô
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função auxiliar para trocar dois elementos de posição
void swap(int* a, int* b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    // Imprime o vetor ordenado
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
