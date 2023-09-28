#define TAMANHO 10000

void merge(int x[], int inicio, int fim);
void intercala(int x[], int inicio, int fim, int meio);
int qtd_trocas = 0, qtd_comparacoes = 0;

void merge(int x[], int inicio, int fim) {
    int meio;

    if (inicio < fim) {
        meio = (inicio + fim) / 2;

        merge(x, inicio, meio);
        merge(x, meio + 1, fim);
        intercala(x, inicio, fim, meio);
    }
}

void intercala(int x[], int inicio, int fim, int meio) {
    int poslivre = inicio, iniciovetor1 = inicio, iniciovetor2 = meio + 1, i;
    int aux[TAMANHO];

    while (iniciovetor1 <= meio && iniciovetor2 <= fim) {
        qtd_trocas++;
        if (x[iniciovetor1] <= x[iniciovetor2]) {
            aux[poslivre] = x[iniciovetor1];
            iniciovetor1++;
        } else {
            aux[poslivre] = x[iniciovetor2];
            iniciovetor2++;
        }
        poslivre++;
        qtd_comparacoes++;
    }

    for (i = iniciovetor1; i <= meio; i++) {
        aux[poslivre] = x[i];
        poslivre++;
        qtd_trocas++;
    }

    for (i = iniciovetor2; i <= fim; i++) {
        aux[poslivre] = x[i];
        poslivre++;
        qtd_trocas++;
    }

    for (i = inicio; i <= fim; i++) {
        x[i] = aux[i];
    }
}