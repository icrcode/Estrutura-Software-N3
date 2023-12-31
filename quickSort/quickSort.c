#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 10000

// Protótipo de Função
void geraNumero(int *vet, int op);
void quickSort(int *vet, int p, int r);
int particao(int *vet, int p, int r);
void imprimirVetor(int *vet);
int qtd_comparacoes = 0, qtd_trocas = 0;

int main(void)
{
    int vet1[TAMANHO];

    // Entrada de dados;
    geraNumero(vet1, 2);

    // Processamento dos dados
    quickSort(vet1, 0, TAMANHO - 1);

    // Saída de dados
    printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
    printf("Quantidade de trocas: %i\n", qtd_trocas);
    return 0;
}

// Função geração de números
void geraNumero(int *vet, int op)
{
    int i, j;
    switch (op)
    {
    case 1: // Ordenados
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = i + 1;
        }
        break;
    case 2: // Invertidos
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = TAMANHO - i;
        }
        break;
    case 3: // Aleatórios
        for (i = 0; i < TAMANHO; i++)
        {
            vet[i] = (int)(rand() % TAMANHO);
        }
        break;
    }
}


int particao(int *vet, int comeco, int fim)
{
    int pivo = vet[(comeco + fim) / 2]; //indice que vira pivo
    int i = comeco - 1;//i vira um indice antes do primeiro
    int j = fim + 1;//j vira um indice depois do ultimo
    int temp; //variavel auxiliar
    while (i<j)//começo até o fim
    {
        do
        {
            qtd_comparacoes++;//ambas as situações são comparações
            i = i + 1; //continua incrementando i, (até ele alcançar ou varrer o array todo chegando em j)
        } while (vet[i] < pivo); //fará isso até encontrar um indice do array que seja maior que o pivo
        do
        {
            qtd_comparacoes++;//ambas as situações são comparações
            j = j - 1; //decrementa o j
        } while (vet[j] > pivo);//até encontrar um indice do array que seja menor que o pivo
        if (i < j) //se houver uma troca das condições, algo maior na esquerda e menor na direita
        {
            qtd_trocas++;
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            //bloco da troca
        }
        else
        {
            return j;//indice final do pivo
        }
    }
}

// Função ordenação Quicksort
void quickSort(int *vet, int comeco, int fim)
{
    if (comeco < fim)//verifica se o array não tem um unico elemento (ja estaria ordenado se tivesse)
    {
        int part = particao(vet, comeco, fim); //recebe o retorno de particao, que é j, o indice final do pivo
        quickSort(vet, comeco, part);//a mesma função de cima, mas agora o q é o ultimo indice, ou seja, começa no inicio e termina no pivo que acabou de ser encontrado
        quickSort(vet, part + 1, fim);//o contrário da função de cima, agora começa no indice diretamente seguinte ao pivo e vai até o fim.
        //duas metades do array varridas e ordenadas.
    }
}

// Função impressão do vetor
void imprimirVetor(int *vet){
    int i;
    for (i = 0; i < TAMANHO; i++){
        printf("%i, ", vet[i]);
        if ((i + 1) % 14 == 0){
            printf("\n");
        }
    }
}
