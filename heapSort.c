#include <stdio.h>
#include <stdio.h>


void heapify(int arr[], int n, int i)  // Função que transforma uma subárvore em heap, com raiz no nó i 
{

    int maior = i;  // Inicializa o maior valor como a raiz

   
    int esquerda = 2 * i + 1;  // Índice do filho esquerdo = 2*i + 1 

   
    int direita = 2 * i + 2;   // Índice do filho direito = 2*i + 2


    if (esquerda < n && arr[esquerda] > arr[maior]) // Se o filho esquerdo for maior que a raiz
        maior = esquerda;

    
    if (direita < n && arr[direita] > arr[maior])  // Se o filho direito for maior que o maior atual
        maior = direita;

    // Se o maior não for a raiz
    if (maior != i) 
    {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

       
        heapify(arr, n, maior);  // Chama recursivamente o heapify para a subárvore afetada
    }
}


void heapSort(int arr[], int n)  // Função principal do algoritmo Heap Sort
{

    // Constrói o heap máximo 
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   
    for (int i = n - 1; i > 0; i--)  // Extrai um elemento do heap por vez
    {

        // Move a raiz (maior elemento) para o final do vetor
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    return 0;
}
