#define TAMANHO 10000

void insertionSort(int *vet){
    int eleito, i, j, qtd_trocas, qtd_comparacoes;

    qtd_trocas = 0;
    qtd_comparacoes = 0;

    float tempo_inicial = clock();
    for (i = 1; i <= TAMANHO - 1; i++) {
        eleito = vet[i];
        j = i - 1;
        qtd_comparacoes++;//Compara
        qtd_trocas++;//Troca
        while (j >= 0 && vet[j] > eleito) {
            qtd_comparacoes++;//Compara
            vet[j + 1] = vet[j];
            j = j - 1;
            qtd_trocas++;//Troca
        }
        vet[j + 1] = eleito;
        qtd_trocas++;//Troca
    }
    float tempo_final = clock() - tempo_inicial;

    printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
}