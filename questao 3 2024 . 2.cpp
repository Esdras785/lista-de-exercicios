#include <stdio.h>
#include <string.h>

#define TAM 20

typedef struct {
    char nome[80];
    float preco;
} PROD;

// Fun��o para inflacionar o pre�o
void inflacionar(PROD *produto) {
    if (produto->preco < 100) {
        produto->preco *= 1.05; // Acrescenta 5% ao pre�o
    }
}

// Fun��o para ler os dados dos produtos
void lerDados(PROD produtos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Produto %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
    }
}

// Fun��o para imprimir os produtos
void imprimir(PROD produtos[], int tamanho) {
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s, Preco: %.2f\n", produtos[i].nome, produtos[i].preco);
    }
}

// Fun��o para ordenar os produtos por nome (ordem alfab�tica)
void ordenar(PROD produtos[], int tamanho) {
    PROD temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
}

int main() {
    PROD produtos[TAM];

    // Leitura dos dados
    lerDados(produtos, TAM);

    // Ordena��o por nome
    ordenar(produtos, TAM);

    // Inflacionar produtos com pre�o menor que 100
    for (int i = 0; i < TAM; i++) {
        inflacionar(&produtos[i]);
    }

    // Impress�o dos produtos
    imprimir(produtos, TAM);

    return 0;
}

