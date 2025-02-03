/*
    Método de Ordenação de Dados - Selection Sort
*/

// Declaração das Bibliotecas;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50 // Define o tamanho do vetor;

void fSelect_Sort(int *pVetor); // Declara a função select sort;

int main()
{
    int vVetor[TAM]; // Declara o vetor
    int vAux;

    srand ( time(NULL) );
    for (vAux=0; vAux < TAM; vAux++)
    {
        vVetor[vAux] = (rand() % 89) + 10; // Preenche o vetor aleatóriamente;
        printf(" %d,",vVetor[vAux]);
    }

    fSelect_Sort(vVetor); // Chama a função de Ordenação;

    printf("\n\n");

    for (vAux=0; vAux < TAM; vAux++)
    {
        printf(" %d,",vVetor[vAux]);
    }

    printf("\n\n ");
    system("pause");
    return 0;
}

void fSelect_Sort(int *pVetor)
{
    int vMenor;
    int vAux;
    int vTemp;
    int vTroca;

    for(vAux=0; vAux < TAM-1; vAux++) // Percorre todo o vetor até TAM-1, pois a ultima posição não precisa testar pois ja estara ordenada;
    {
        vMenor = vAux; // Menor valor recebe a posição que está passando;

        for (vTemp=vAux+1; vTemp < TAM; vTemp++) // Percorre o vetor da posição vAux+1 até o final;
        {
            if (pVetor[vTemp] < pVetor[vMenor]) // Testa se a posição que está passando é menor que o menor valor;
            {
                vMenor = vTemp; // vMenor recebe a posição do menor valor;
            }
        }

        if (vMenor != vAux) // Se a posição for diferente da que está passando, ocorre a troca;
        {
            vTroca         = pVetor[vAux];
            pVetor[vAux]   = pVetor[vMenor];
            pVetor[vMenor] = vTroca;
        }
    }
}