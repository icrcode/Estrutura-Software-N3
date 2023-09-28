
#define TAMANHO 10000

void selectionSort(int *vet){
    int i, j, menor, eleito, pos, qtd_trocas, qtd_comparacoes;

    qtd_trocas = 0;
    qtd_comparacoes = 0;

    float tempo_inicial = clock();
    for (i = 0; i <= TAMANHO-2; i++) {
        eleito = vet[i];
        menor = vet[i + 1];
        pos = i + 1;
        for (j = i + 2; j <= TAMANHO; j++) {
            qtd_comparacoes++; //Compara
            if (vet[j] < menor) {
                menor = vet[j];
                pos = j;
            }
        }
        qtd_trocas++; //Troca
        if (menor < eleito) {
            vet[i] = vet[pos];
            qtd_trocas++; //Troca
            vet[pos] = eleito;
        }
    }

    printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
}