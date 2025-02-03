#include <stdio.h>

// Para ajustar um subárvore com raiz no nó i,
// que é um índice no arr[].
void heapify(int arr[], int n, int i) {

    // Inicializa o maior como a raiz
    int maior = i; 

    // Índice do filho esquerdo = 2*i + 1
    int l = 2 * i + 1; 

    // Índice do filho direito = 2*i + 2
    int r = 2 * i + 2;

    // Se o filho esquerdo for maior que a raiz
    if (l < n && arr[l] > arr[maior]) {
        maior = l;
    }

    // Se o filho direito for maior que o maior até agora
    if (r < n && arr[r] > arr[maior]) {
        maior = r;
    }

    // Se o maior não for a raiz
    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        // Recursivamente ajusta a subárvore afetada
        heapify(arr, n, maior);
    }
}

// Função principal para ordenar usando Heap Sort
void heapSort(int arr[], int n) {

    // Constrói o heap (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extrai um elemento do heap um por um
    for (int i = n - 1; i > 0; i--) {

        // Move a raiz atual para o final
        int temp = arr[0]; 
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama heapify na heap reduzida
        heapify(arr, i, 0);
    }
}

// Função utilitária para imprimir um array de tamanho n
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Código principal (função main)
int main() {
    int arr[] = {9, 4, 3, 8, 10, 2, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("O array ordenado é: \n");
    printArray(arr, n);
    return 0;
}
