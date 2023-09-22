#define TAMANHO 10000

void selectionSort(int *vet){
    int i, j, menor, eleito, pos, qtd_trocas, qtd_comparacoes;

    qtd_trocas = 0;
    qtd_comparacoes = 0;

    float tempo_inicial = clock();
    for (i = 0; i <= TAMANHO-2; i++) {
        qtd_trocas++;
        eleito = vet[i];
        menor = vet[i + 1];
        pos = i + 1;
        for (j = i + 2; j <= TAMANHO; j++) {
            qtd_comparacoes++;
            if (vet[j] < menor) {
                menor = vet[j];
                pos = j;
            }
        }
        if (menor < eleito) {
            qtd_trocas++;
            vet[i] = vet[pos];
            vet[pos] = eleito;

        }
    }
    float tempo_final = clock() - tempo_inicial;
    // Saída de dados
    printf("Esse e o Insertion Selection Sort");
    printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f",tempo_final/1000);
}
