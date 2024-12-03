#include <stdio.h>
#define TAMANHO 50

// Estrutura da lista est�tica
typedef struct {
    int lista[TAMANHO];
    int tamanho_atual;
} ListaEstatica;

// Inicializar a lista
void inicializar(ListaEstatica *lista) {
    lista->tamanho_atual = 0;
}

// Inserir elemento em ordem crescente
void inserir_crescente(ListaEstatica *lista, int x) {
    if (lista->tamanho_atual >= TAMANHO) {
        printf("Erro: Lista cheia.\n");
        return;
    }

    int posicao = 0;
    // Encontrar a posi��o correta
    while (posicao < lista->tamanho_atual && lista->lista[posicao] < x) {
        posicao++;
    }

    // Deslocar elementos para abrir espa�o
    for (int i = lista->tamanho_atual; i > posicao; i--) {
        lista->lista[i] = lista->lista[i - 1];
    }

    // Inserir o elemento
    lista->lista[posicao] = x;
    lista->tamanho_atual++;
}

// Inserir elemento em ordem decrescente
void inserir_decrescente(ListaEstatica *lista, int x) {
    if (lista->tamanho_atual >= TAMANHO) {
        printf("Erro: Lista cheia.\n");
        return;
    }

    int posicao = 0;
    // Encontrar a posi��o correta
    while (posicao < lista->tamanho_atual && lista->lista[posicao] > x) {
        posicao++;
    }

    // Deslocar elementos para abrir espa�o
    for (int i = lista->tamanho_atual; i > posicao; i--) {
        lista->lista[i] = lista->lista[i - 1];
    }

    // Inserir o elemento
    lista->lista[posicao] = x;
    lista->tamanho_atual++;
}

// Exibir a lista
void exibir_lista(ListaEstatica *lista) {
    for (int i = 0; i < lista->tamanho_atual; i++) {
        printf("%d ", lista->lista[i]);
    }
    printf("\n");
}

// Fun��o principal para demonstrar o funcionamento
int main() {
    ListaEstatica lista_crescente;
    ListaEstatica lista_decrescente;

    inicializar(&lista_crescente);
    inicializar(&lista_decrescente);

    // Inserir elementos em ordem crescente
    inserir_crescente(&lista_crescente, 10);
    inserir_crescente(&lista_crescente, 5);
    inserir_crescente(&lista_crescente, 20);
    inserir_crescente(&lista_crescente, 15);

    printf("Lista em ordem crescente: ");
    exibir_lista(&lista_crescente);

    // Inserir elementos em ordem decrescente
    inserir_decrescente(&lista_decrescente, 10);
    inserir_decrescente(&lista_decrescente, 5);
    inserir_decrescente(&lista_decrescente, 20);
    inserir_decrescente(&lista_decrescente, 15);

    printf("Lista em ordem decrescente: ");
    exibir_lista(&lista_decrescente);

    return 0;
}

