#define TAMANHO 10000

void bubbleSort(int *vet){
    int n, troca, i, aux, qtd_trocas, qtd_comparacoes;
    n = 1;
    troca = 1;
    qtd_trocas = 0;
    qtd_comparacoes = 0;
// Ponto do algoritmo para iniciar o tempo de execução
    float tempo_inicial = clock();
    while (n <= TAMANHO && troca == 1) {
        troca = 0;

        for (i = 0; i <= TAMANHO-2; i++) {
            // Ponto do algoritmo para contar as comparações
            qtd_comparacoes++;
            if (vet[i] > vet[i + 1]) {
                // Ponto do algoritmo para contar as trocas
                qtd_trocas++;
                troca = 1;
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
        n = n + 1;
    }
    // Ponto do algoritmo para calcular o tempo de execução
    float tempo_final = clock() - tempo_inicial;
    // Saída de dados
    printf("Esse e o Insertion Bubble Sort");
    printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f",tempo_final/1000);
}