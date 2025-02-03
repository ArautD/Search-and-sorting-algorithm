/*
    Ordenação Insertion Sort em C
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100 // Declara o tamanho do vetor;

void fInsertion_Sort(int *pVetor);

int main()
{
    int vVetor[TAM];
    int vAux;

    srand(time(NULL));
    for (vAux=0; vAux < TAM; vAux++)
    {
        vVetor[vAux] = (rand() % 90) + 10; // Preenche o vetor com valores aleatórios de 10 até 99;
        printf(" %d,",vVetor[vAux]);
    }

    fInsertion_Sort(vVetor); // Chama a função de Ordenação;

    printf("\n\n");
    for (vAux=0; vAux < TAM; vAux++)
    {
        printf(" %d,",vVetor[vAux]);
    }

    printf("\n\n ");
    system("pause");
}

void fInsertion_Sort(int *pVetor)
{
    int vAux;
    int vTemp;
    int vTroca;

    for (vAux=1; vAux < TAM; vAux++) // vAux começa na posição 1 do vetor e vai até a ultima posição;
    {
        vTemp = vAux; // vTemp recebe a posição que está passando no "for";

        while (pVetor[vTemp] < pVetor[vTemp-1]) // Enquanto o valor que está passando na posição "vTemp" for menor que a posição "vTemp" menos 1, ocorre a troca;
        { // Ocorre a troca;
            vTroca          = pVetor[vTemp];
            pVetor[vTemp]   = pVetor[vTemp-1];
            pVetor[vTemp-1] = vTroca;
            vTemp--; // vTemp decrementa 1;

            if (vTemp == 0) // Quando "vTemp" chegar na posição 0, primeira posição do vetor, o laço while para;
                break;
        }

    }
}