#include <stdio.h>

// Função auxiliar para obter o maior valor no array
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Função para realizar o Counting Sort no array
// de acordo com o dígito representado por exp
void countSort(int arr[], int n, int exp) {
    int output[n]; // Array de saída
    int count[10] = {0}; // Inicializa o array de contagem com 0

    // Armazena a contagem de ocorrências em count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Ajusta count[i] para armazenar a posição correta deste dígito
    // no array de saída
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída de volta para arr[],
    // de modo que agora arr[] contenha os números
    // ordenados de acordo com o dígito atual
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Função principal para ordenar arr[] de tamanho n
// usando o algoritmo Radix Sort
void radixSort(int arr[], int n) {
  
    // Encontra o maior número para determinar
    // o número de dígitos
    int m = getMax(arr, n); 

    // Aplica o Counting Sort para cada dígito
    // exp é 10^i onde i é a posição do dígito atual
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Função auxiliar para imprimir um array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Código principal (driver)
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Chamada da função de ordenação
    radixSort(arr, n);
    
    // Exibe o array ordenado
    printArray(arr, n);
    
    return 0;
}