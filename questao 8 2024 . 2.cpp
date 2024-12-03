#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do n� da lista encadeada
typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Fun��o para criar um novo n�
No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de aloca��o de mem�ria.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Fun��o para adicionar um n� ao final da lista
void adicionarNo(No **inicio, int valor) {
    No *novo = criarNo(valor);

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    No *atual = *inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
}

// Fun��o para encontrar o m�nimo de forma iterativa
int encontrarMinimoIterativo(No *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return -1;  // Indicativo de erro
    }

    No *atual = inicio;
    int minimo = atual->valor;  // Inicializa o m�nimo com o valor do primeiro n�

    while (atual != NULL) {
        if (atual->valor < minimo) {
            minimo = atual->valor;  // Atualiza o m�nimo se encontrar um valor menor
        }
        atual = atual->proximo;
    }

    return minimo;
}

// Fun��o para encontrar o m�nimo de forma recursiva
int encontrarMinimoRecursivo(No *inicio, int minimo) {
    if (inicio == NULL) {
        return minimo;  // Lista percorrida, retorna o m�nimo
    }

    if (inicio->valor < minimo) {
        minimo = inicio->valor;  // Atualiza o m�nimo se necess�rio
    }

    return encontrarMinimoRecursivo(inicio->proximo, minimo);  // Chamada recursiva para o pr�ximo n�
}

// Fun��o para exibir a lista
void exibirLista(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Fun��o para liberar a mem�ria da lista
void liberarLista(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

// Fun��o principal para testar
int main() {
    No *lista = NULL;

    // Criando uma lista de exemplo
    adicionarNo(&lista, 7);
    adicionarNo(&lista, 3);
    adicionarNo(&lista, 8);
    adicionarNo(&lista, 1);
    adicionarNo(&lista, 5);

    printf("Lista: ");
    exibirLista(lista);

    // Encontrando o m�nimo de forma iterativa
    int minimoIterativo = encontrarMinimoIterativo(lista);
    if (minimoIterativo != -1) {
        printf("M�nimo encontrado (iterativo): %d\n", minimoIterativo);
    }

    // Encontrando o m�nimo de forma recursiva
    int minimoRecursivo = encontrarMinimoRecursivo(lista, lista->valor);
    printf("M�nimo encontrado (recursivo): %d\n", minimoRecursivo);

    // Liberando a mem�ria
    liberarLista(lista);

    return 0;
}

