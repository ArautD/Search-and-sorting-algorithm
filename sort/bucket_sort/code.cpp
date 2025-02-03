#include <iostream>
#include <vector>
using namespace std;

#define N 10
int a[] = {5, 2, 9, 0, 7, 1, 3, 6, 4, 8};

// Função para encontrar o valor máximo no vetor
int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

// Função de ordenação com Bucket Sort
void bucket(int a[], int n) {
    int max = getMax(a, n);  // Encontrar o valor máximo do vetor

    // Criar um vetor de "baldes" para contar as ocorrências
    vector<int> bucket(max + 1, 0);  // Criando um vetor de tamanho max + 1

    // Contar as ocorrências de cada valor no vetor
    for (int i = 0; i < n; i++) {
        bucket[a[i]]++;
    }

    // Reconstituir o vetor original com os valores ordenados
    int j = 0;
    for (int i = 0; i <= max; i++) {
        while (bucket[i] > 0) {
            a[j++] = i;  // Colocar o valor no vetor original
            bucket[i]--;  // Reduzir o contador do balde
        }
    }
}

int main() {
    cout << "Vetor original: ";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    bucket(a, N);  // Chama a função de ordenação Bucket Sort

    cout << "Vetor ordenado: ";
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
