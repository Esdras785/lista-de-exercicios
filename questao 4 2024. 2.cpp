#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    char *string;
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *inicio;
    int tamanho; // Número de elementos na lista
    int capacidade; // Capacidade alocada
} ListaDinamica;

// Inicializa a lista dinâmica
void inicializarLista(ListaDinamica *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}

// Insere uma string na lista
void inserir(ListaDinamica *lista, const char *str) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    novo->string = strdup(str);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    lista->capacidade++;
}

// Remove um elemento com a string especificada
int remover(ListaDinamica *lista, const char *str) {
    Nodo *atual = lista->inicio, *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->string, str) == 0) {
            if (anterior == NULL) {
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }

            free(atual->string);
            free(atual);
            lista->tamanho--;
            return 1; // Removido com sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // Não encontrado
}

// Busca um elemento na lista
Nodo *buscar(ListaDinamica *lista, const char *str) {
    Nodo *atual = lista->inicio;

    while (atual != NULL) {
        if (strcmp(atual->string, str) == 0) {
            return atual; // Encontrado
        }
        atual = atual->proximo;
    }
    return NULL; // Não encontrado
}

// Verifica se a lista está vazia
int estaVazia(ListaDinamica *lista) {
    return lista->tamanho == 0;
}

// Retorna o tamanho da lista
int tamanho(ListaDinamica *lista) {
    return lista->tamanho;
}

// Calcula a perda de memória (total de nós alocados - nós ocupados)
int perdaDeMemoria(ListaDinamica *lista) {
    return lista->capacidade - lista->tamanho;
}

// Exibe todos os elementos da lista
void exibirLista(ListaDinamica *lista) {
    Nodo *atual = lista->inicio;

    printf("Lista de Strings:\n");
    while (atual != NULL) {
        printf("- %s\n", atual->string);
        atual = atual->proximo;
    }
}

// Libera a memória da lista
void liberarLista(ListaDinamica *lista) {
    Nodo *atual = lista->inicio;

    while (atual != NULL) {
        Nodo *temp = atual;
        atual = atual->proximo;
        free(temp->string);
        free(temp);
    }
    lista->inicio = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
}

// Função principal
int main() {
    ListaDinamica lista;
    inicializarLista(&lista);

    // Testando inserções
    inserir(&lista, "Primeira");
    inserir(&lista, "Segunda");
    inserir(&lista, "Terceira");

    // Exibindo a lista
    exibirLista(&lista);

    // Removendo um elemento
    printf("\nRemovendo 'Segunda':\n");
    remover(&lista, "Segunda");
    exibirLista(&lista);

    // Buscando um elemento
    Nodo *resultado = buscar(&lista, "Primeira");
    if (resultado != NULL) {
        printf("\nElemento encontrado: %s\n", resultado->string);
    } else {
        printf("\nElemento não encontrado\n");
    }

    // Tamanho e perda de memória
    printf("\nTamanho da lista: %d\n", tamanho(&lista));
    printf("Perda de memória: %d\n", perdaDeMemoria(&lista));

    // Liberando a memória
    liberarLista(&lista);

    return 0;
}

