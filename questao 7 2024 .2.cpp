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

// Fun��o de busca iterativa
No *buscarIterativo(No *inicio, int valor) {
    No *atual = inicio;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual; // Valor encontrado
        }
        if (atual->valor > valor) {
            return NULL; // Como a lista � crescente, se o valor for maior, o valor n�o est� na lista
        }
        atual = atual->proximo;
    }
    return NULL; // Valor n�o encontrado
}

// Fun��o de busca recursiva
No *buscarRecursivo(No *inicio, int valor) {
    if (inicio == NULL || inicio->valor > valor) {
        return NULL; // Valor n�o encontrado ou a lista foi percorrida completamente
    }
    if (inicio->valor == valor) {
        return inicio; // Valor encontrado
    }
    return buscarRecursivo(inicio->proximo, valor); // Chamada recursiva para o pr�ximo n�
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

// Fun��o para exibir a lista
void exibirLista(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;

    // Criando uma lista de exemplo (crescente)
    adicionarNo(&lista, 1);
    adicionarNo(&lista, 3);
    adicionarNo(&lista, 5);
    adicionarNo(&lista, 7);
    adicionarNo(&lista, 9);

    printf("Lista: ");
    exibirLista(lista);

    // Testando a busca iterativa
    int valorBusca = 5;
    No *resultadoIterativo = buscarIterativo(lista, valorBusca);
    if (resultadoIterativo != NULL) {
        printf("Valor %d encontrado (iterativo).\n", valorBusca);
    } else {
        printf("Valor %d n�o encontrado (iterativo).\n", valorBusca);
    }

    // Testando a busca recursiva
    No *resultadoRecursivo = buscarRecursivo(lista, valorBusca);
    if (resultadoRecursivo != NULL) {
        printf("Valor %d encontrado (recursivo).\n", valorBusca);
    } else {
        printf("Valor %d n�o encontrado (recursivo).\n", valorBusca);
    }

    // Liberando a mem�ria
    liberarLista(lista);

    return 0;
}

