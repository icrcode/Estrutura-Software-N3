#define TAMANHO 10000

void insertionSort(int *vet){
    int eleito, i, j, qtd_trocas, qtd_comparacoes;

    eleito = 0;
    qtd_trocas = 0;
    qtd_comparacoes = 0;

    // Ponto do algoritmo para iniciar o tempo de execução
    float tempo_inicial = clock();
    for (i = 1; i <= TAMANHO - 1; i++) {
        eleito = vet[i];
        j = i - 1;
        // Ponto do algoritmo para contar as comparações e trocas
        qtd_comparacoes++;
        qtd_trocas++;
        while (j >= 0 && vet[j] > eleito) {
            // Ponto do algoritmo para contar as comparações

            qtd_comparacoes++;
            vet[j + 1] = vet[j];
            j = j - 1;
            // Ponto do algoritmo para contar as trocas

            qtd_trocas++;

        }
        vet[j + 1] = eleito;
        qtd_trocas++;
    }

    // Ponto do algoritmo para calcular o tempo de execução
    float tempo_final = clock() - tempo_inicial;

    // Saída de dados
    printf("Esse e o Insertion Sort");
    printf("\nQuantidade de comparacoes: %i\n", qtd_comparacoes);
    printf("Quantidade de trocas: %i\n", qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f", tempo_final/1000);
}