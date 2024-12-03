#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* criar_no(int data) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = data;
    novo->next = NULL;
    return novo;
}

// Função para adicionar um nó no final da lista
void adicionar_no(Node** head, int data) {
    Node* novo = criar_no(data);
    if (*head == NULL) {
        *head = novo;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novo;
    }
}

// Função para encontrar o ponto médio da lista encadeada
Node* ponto_medio(Node* head) {
    if (head == NULL) {
        return NULL;  // Lista vazia
    }

    Node* rapido = head;
    Node* lento = head;

    // O ponteiro rápido avança duas células por vez e o ponteiro lento uma
    while (rapido != NULL && rapido->next != NULL) {
        lento = lento->next;          // Avança o ponteiro lento uma célula
        rapido = rapido->next->next;  // Avança o ponteiro rápido duas células
    }

    return lento;  // O ponteiro lento está no ponto médio
}

// Função para imprimir a lista (opcional, para testes)
void imprimir_lista(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função para liberar a memória da lista
void liberar_lista(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* lista = NULL;

    // Adicionando elementos à lista
    adicionar_no(&lista, 1);
    adicionar_no(&lista, 2);
    adicionar_no(&lista, 3);
    adicionar_no(&lista, 4);
    adicionar_no(&lista, 5);

    // Imprimindo a lista
    printf("Lista: ");
    imprimir_lista(lista);

    // Encontrando o ponto médio
    Node* meio = ponto_medio(lista);
    
    if (meio != NULL) {
        printf("O ponto médio da lista tem o valor: %d\n", meio->data);
    } else {
        printf("A lista está vazia.\n");
    }

    // Liberando a memória
    liberar_lista(lista);

    return 0;
}

