#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista encadeada
typedef struct No {
    int valor;
    struct No *proximo;
} No;

// Função para criar um novo nó
No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Função para adicionar um nó ao final da lista
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

// Função para encontrar o mínimo de forma iterativa
int encontrarMinimoIterativo(No *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia!\n");
        return -1;  // Indicativo de erro
    }

    No *atual = inicio;
    int minimo = atual->valor;  // Inicializa o mínimo com o valor do primeiro nó

    while (atual != NULL) {
        if (atual->valor < minimo) {
            minimo = atual->valor;  // Atualiza o mínimo se encontrar um valor menor
        }
        atual = atual->proximo;
    }

    return minimo;
}

// Função para encontrar o mínimo de forma recursiva
int encontrarMinimoRecursivo(No *inicio, int minimo) {
    if (inicio == NULL) {
        return minimo;  // Lista percorrida, retorna o mínimo
    }

    if (inicio->valor < minimo) {
        minimo = inicio->valor;  // Atualiza o mínimo se necessário
    }

    return encontrarMinimoRecursivo(inicio->proximo, minimo);  // Chamada recursiva para o próximo nó
}

// Função para exibir a lista
void exibirLista(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para liberar a memória da lista
void liberarLista(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

// Função principal para testar
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

    // Encontrando o mínimo de forma iterativa
    int minimoIterativo = encontrarMinimoIterativo(lista);
    if (minimoIterativo != -1) {
        printf("Mínimo encontrado (iterativo): %d\n", minimoIterativo);
    }

    // Encontrando o mínimo de forma recursiva
    int minimoRecursivo = encontrarMinimoRecursivo(lista, lista->valor);
    printf("Mínimo encontrado (recursivo): %d\n", minimoRecursivo);

    // Liberando a memória
    liberarLista(lista);

    return 0;
}

